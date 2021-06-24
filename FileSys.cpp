#include "FileSys.h"
#include <bits/stdc++.h>

void insert(const char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(const char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

// 200个inode节点，每个inode 10个block
/********** InodeTable *********/
InodeTable::InodeTable()
{
    ifstream sysfile(DATAFILE, ios::in | ios::binary);             // 读取二进制文件
    sysfile.seekg(0);                                              // 设置写文件指针的位置
    sysfile.read(reinterpret_cast<char *>(entry), INODE_BIT_SIZE); // 读取从文件指针开始INODE_BIT_SIZE大小的内容到entry(强制转换成char)
    sysfile.close();                                               // 关闭文件
}

size_t InodeTable::add(Inode *i)
{
    fstream sysfile(DATAFILE, ios::in | ios::out | ios::binary);      // 读写二进制文件
    size_t address = getAvailable() * sizeof(Inode) + INODE_BIT_SIZE; //得到该节点的地址
    sysfile.seekp(address);                                           // 设置写文件指针的位置
    sysfile.write(reinterpret_cast<const char *>(i), sizeof(Inode));  // 把i的内容写到从文件指针开始Inode大小的位置
    sysfile.close();                                                  // 关闭文件
    return address;
}

Inode *InodeTable::getInode(size_t address)
{
    ifstream sysfile(DATAFILE, ios::in | ios::binary);          // 读取二进制文件
    auto res = new Inode();                                     //创建一个Inode
    sysfile.seekg(address);                                     //调整文件指针
    sysfile.read(reinterpret_cast<char *>(res), sizeof(Inode)); // 读取从文件指针开始INODE大小的内容到res
    sysfile.close();                                            // 关闭文件
    return res;
}

size_t InodeTable::getAvailable()
{
    for (size_t i = 0; i < 200; ++i) //200个索引表项
    {
        if (entry[i] == false)
        {
            entry[i] = true;
            write(); // 将该表写入磁盘
            return i;
        }
    }
    return -1;
}

void InodeTable::release(size_t add, Bitmap *bitmap)
{
    auto cur = getInode(add);                  //使用inode地址获取一个inode指针
    for (size_t i = 0; i < cur->blockNum; ++i) //从0到该iNode磁盘块的个数
    {
        bitmap->release(cur->blockAddress[i]); //释放位图中的iNode的磁盘块的地址
    }
    size_t index = (add - INODE_BIT_SIZE) / sizeof(Inode);
    if (index < 200)
        entry[index] = false;
    write();
    delete cur;
}

void InodeTable::write()
{
    fstream sysfile(DATAFILE, ios::out | ios::in | ios::binary);
    sysfile.seekp(0);
    sysfile.write(reinterpret_cast<const char *>(entry), INODE_BIT_SIZE);
    sysfile.close();
}

/********** Bit map *********/
void Bitmap::init() //初始化位图全为空闲
{
    for (size_t i = 0; i < BLOCK_NUM; ++i)
        bitmap[i] = false;
}

void Bitmap::write()
{
    fstream sysfile(DATAFILE, ios::out | ios::in | ios::binary);
    sysfile.seekp(INODE_TABLE_SIZE);
    sysfile.write(reinterpret_cast<const char *>(this), BITMAP_SIZE);
    sysfile.close();
}
size_t Bitmap::getNext()
{
    for (size_t i = 0; i < BLOCK_SIZE; ++i)
    {
        if (!bitmap[i])
        {
            bitmap[i] = true;
            write(); // 将位图写到磁盘
            return i * BLOCK_SIZE + INODE_TABLE_SIZE + BITMAP_SIZE;
        }
    }
    return -1;
}

void Bitmap::release(size_t add)
{
    size_t index = (add - INODE_TABLE_SIZE - BITMAP_SIZE) / BLOCK_SIZE;
    bitmap[index] = false;
    write();
}

/********** User *********/
void User::setUsername(string name)
{
    size_t len = name.size() < 30 ? name.size() : 29;
    name.copy(username, len);
    username[len] = '\0';
}

/********** File *********/

vector<FileEntry> File::getDir()
{
    vector<FileEntry> res;
    FileEntry now;
    string all = readAll();
    string field = "";
    int flag = 0;
    for (char c : all)
    {
        if (c == '$')
        {
            switch (flag)
            {
            case FILENAME:
                field.copy(now.fileName, field.length() < 30 ? field.length() : 29);
                break;
            case ADDRESS:
                now.address = stoi(field);
                break;
            case PROTECTCODE:
                now.protectCode = stoi(field);
                break;
            case LENGTH:
                now.length = stoi(field);
                res.push_back(now);
            }
            flag = (flag + 1) % 4;
            field = "";
        }
        else
            field += c;
    }
    for(auto i:res){
        insert(i.fileName);
    }
    return res;
}

void File::writeDir(const vector<FileEntry> &dir, size_t inode_address)
{
    string res = "";
    for (auto &i : dir)
    {
        res += string(i.fileName) + '$';
        res += to_string(i.address) + '$';
        res += to_string(i.protectCode) + '$';
        res += to_string(i.length) + '$';
    }
    write(res, inode_address);
}
//将本身i-node重新写入i-node表
void File::writeSelf(size_t address)
{
    fstream sysfile(DATAFILE, ios::in | ios::out | ios::binary);
    sysfile.seekp(address);
    sysfile.write(reinterpret_cast<const char *>(inode), sizeof(Inode));
    sysfile.close();
}

string File::readAll()
{
    size_t len = inode->blockNum; //存储iNode的磁盘块的地址该iNode磁盘块的个数
    string res = "";
    char temp[BLOCK_SIZE]; //每次循环将读取的内容暂存到temp
    for (size_t i = 0; i < len; ++i)
    {
        auto BlockAddress = inode->blockAddress[i];
        ifstream sysfile(DATAFILE, ios::in | ios::binary);
        sysfile.seekg(BlockAddress);
        sysfile.read(temp, BLOCK_SIZE);
        sysfile.close();
        res += temp;
    }
    return res;
}
//写到当前的i-node拥有的block里面
size_t File::write(const string &towrite, size_t inode_address)
{
    auto vec = split(towrite);
    if (vec.size() > 10) //每个inode共有10个block，超过就越界报错
        return 0;
    fstream sysfile(DATAFILE, ios::in | ios::out | ios::binary);
    size_t i = 0;
    for (; i < vec.size(); ++i)
    {
        //如果这个块本来就有的了就写进去
        if (i < inode->blockNum)
            sysfile.seekp(inode->blockAddress[i]);
        else
        {
            //新的块则从bitmap中分配
            inode->blockAddress[inode->blockNum++] = bitmap.getNext();
            sysfile.seekp(inode->blockAddress[i]);
        }
        sysfile.write(reinterpret_cast<const char *>(vec[i].c_str()), vec[i].length());
    }
    //从bitMap中释放闲置多余的块
    for (size_t j = i; j < inode->blockNum; ++j)
    {
        auto address = inode->blockAddress[j];
        bitmap.release(address);
    }
    inode->blockNum = i;
    sysfile.close();
    writeSelf(inode_address);
    return ((i < 1) ? 0 : (i - 1)) * BLOCK_SIZE + vec[i - 1].length();
}

vector<string> File::split(const string &now)
{
    vector<string> res;
    size_t len = now.length();
    size_t block_num = len / BLOCK_SIZE;
    for (size_t i = 0; i < block_num; ++i)
    {
        res.push_back(string(now.substr(i * BLOCK_SIZE, BLOCK_SIZE)));
    }
    res.push_back(string(now.substr(BLOCK_SIZE * block_num, now.length() - BLOCK_SIZE * block_num)) + "\0");
    return res;
}

void File::readBitmap()
{
    ifstream sysfile(DATAFILE, ios::in | ios::binary);
    sysfile.seekg(INODE_TABLE_SIZE);
    sysfile.read(reinterpret_cast<char *>(&bitmap), BITMAP_SIZE);
    sysfile.close();
}

/********** FileSys *********/

FileSys::FileSys()
{
    prefix = "Administrator:";
    ifstream checkFile(MAINFILE);
    if (!checkFile.good())
    {
        checkFile.close();
        boot(); //启动
    }
    else
        checkFile.close();
}
void FileSys::run()
{
    printf("请输入regist以注册用户，输入login以登录账号，按Ctrl+C退出\n");
    p(prefix);
    string command = "";
    while (cin >> command)
    {
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        if (command == "login" && login())
            break;
        if (command == "regist")
            adduser();
        if (command != "login" && command != "regist")
        {
            printf("请输入regist以注册用户，输入login以登录账号，按Ctrl+C退出\n");
        }
        p(prefix);
    }
    init();
    for (;;)
    {
        p(prefix);
        cin >> command;
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        if (command == "dir")
            printDir();
        else if (command == "create")
            createFile();
        else if (command == "delete")
            deleteFile();
        else if (command == "open")
            openFile();
        else if (command == "read")
            readFile();
        else if (command == "write")
            writeFile();
        else if (command == "copy")
            copyFile();
        else if (command == "close")
            closeFile();
        else if (command == "info")
            info();
        else if (command == "exit")
            break;
        else
        {
            printf("命令出错!\n");
        }
    }
}

void FileSys::printDir()
{
    if (fileEntrys.size() == 0)
        return;
    cout << left << setw(15) << "FileName" << setw(9) << "Address" << setw(15) << "Protect code" << setw(10) << "Length" << endl;
    for (FileEntry &i : fileEntrys)
    {
        cout << left << setw(15) << i.fileName << setw(9) << i.address << setw(15) << pcToBinary(i.protectCode) << setw(10) << i.length << endl;
    }
}

void FileSys::enterFileName()
{
    p("fileName:");
    cin >> fileName;
}

void FileSys::createFile()
{
    enterFileName(); //FileSys的filename
    if (query(fileName.c_str()) == 1)
    {
        printf("已存在同名文件！\n");
        return;
    }
    insert(fileName.c_str());
    pln("Protect Code(three-bit integer): ");
    int pc; //保护码
    cin >> pc;
    FileEntry newfe;
    auto len = fileName.size();
    len = len < 30 ? len : 29;
    fileName.copy(newfe.fileName, len); //把fileName拷贝到newfe.fileName
    newfe.fileName[len] = '\0';
    newfe.protectCode = pc;
    //新的inode
    Inode newinode(0);
    auto address = inodeTable.add(&newinode); //添加一个索引节点
    newfe.address = address;                  //newfe文件地址
    fileEntrys.push_back(newfe);
    file.setInode(&rootDir);                      // 绑定inode到根目录
    file.writeDir(fileEntrys, user.inodeAddress); // 写inode为目录
    file.setInode(&newinode);                     // 绑定inode到新建的节点
    file.writeSelf(address);                      //将本身i-node重新写入i-node表
    file.setInode(NULL);
}

int FileSys::openFile()
{
    enterFileName();
    if (query(fileName.c_str()) == 0)
    {
        pln("No Such File");
        return -1;
    }
    for (size_t i = 0; i < fileEntrys.size(); ++i)
    {
        if (string(fileEntrys[i].fileName) == fileName) //找到文件
        {
            nowFileEntry = &fileEntrys[i];
            // 绑定inode到找到的文件
            file.setInode(inodeTable.getInode(fileEntrys[i].address));
            pln("Open Successfully");
            return 1;
        }
    }
    return -1;
    // pln("No Such File");
    // return -1;
}

void FileSys::deleteFile()
{
    enterFileName();
    for (auto i = fileEntrys.begin(); i < fileEntrys.end(); ++i)
    {
        if (string(i->fileName) == fileName)
        {
            fileEntrys.erase(i);
            // 绑定inode到根目录
            file.setInode(&rootDir);
            file.writeDir(fileEntrys, user.inodeAddress);
            pln("Delete Successfully");
            return;
        }
    }
    pln("No Such File");
}

void FileSys::closeFile()
{
    if(file.getInode()==NULL){
        pln("Close Failed");
        return ;
    }
    // pln("delete success");
    delete file.getInode();
    file.setInode(NULL);
    nowFileEntry = NULL;
    pln("Close Successfully");
}

void FileSys::readFile()
{
    if (nowFileEntry == NULL || nowFileEntry->fileName != fileName)
    {
        printf("请先打开该文件！\n");
        return;
    }
    pln(file.readAll());
}

void FileSys::pln(const string &s) { cout << s << endl; }
void FileSys::p(const string &s) { cout << s; }

void FileSys::copyFile()
{
    int success = 1;
    success = openFile();
    if (success == -1)
    {
        return;
    }
    copyRead();
    success = openFile();
    if (success == -1)
    {
        return;
    }
    copyWrite();
}

void FileSys::copyRead()
{
    tmp = file.readAll();
}

void FileSys::copyWrite()
{
    auto len = file.write(tmp, nowFileEntry->address); // 写到当前的i-node拥有的block里面
    nowFileEntry->length = len;
    file.setInode(&rootDir);
    file.writeSelf(user.inodeAddress);            // 将本身i-node重新写入i-node表
    file.writeDir(fileEntrys, user.inodeAddress); //写inode为目录
}

void FileSys::writeFile()
{
    if (nowFileEntry == NULL || nowFileEntry->fileName != fileName)
    {
        printf("请先打开该文件！\n");
        return;
    }
    pln("write here. End with '$EOF'");
    string res = "", line = "";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //清除当前行
    for (;;)
    {
        getline(cin, line);
        auto pos = line.find("$EOF");
        if (pos != string::npos)
        {
            line[pos] = '\n';
            line[pos + 1] = '\0';
            res += line.substr(0, pos + 2);
            break;
        }
        line += '\n';
        res += line;
    }
    auto len = file.write(res, nowFileEntry->address); // 写到当前的i-node拥有的block里面
    nowFileEntry->length = len;
    file.setInode(&rootDir);
    file.writeSelf(user.inodeAddress);            // 将本身i-node重新写入i-node表
    file.writeDir(fileEntrys, user.inodeAddress); //写inode为目录
}

void FileSys::boot()
{
    ofstream sysfile(MAINFILE, ios::binary);
    size_t i = 0;
    sysfile.write(reinterpret_cast<const char *>(&i), sizeof(size_t));
    sysfile.close();

    sysfile.open(DATAFILE, ios::binary);
    bool tempTable[200] = {0};
    sysfile.seekp(0);
    sysfile.write(reinterpret_cast<const char *>(tempTable), INODE_BIT_SIZE);
    Bitmap tempBitmap;
    tempBitmap.init();
    sysfile.seekp(INODE_TABLE_SIZE);
    sysfile.write(reinterpret_cast<const char *>(&tempBitmap), BITMAP_SIZE);
    sysfile.close();

    file.readBitmap();
    inodeTable = InodeTable();
}

string FileSys::pcToBinary(int n)
{
    string res = "";
    auto convert = [&res](int i) //lambda表达式
    {
        switch (i)
        {
        case 0:
            res += "000";
            break;
        case 1:
            res += "001";
            break;
        case 2:
            res += "010";
            break;
        case 3:
            res += "011";
            break;
        case 4:
            res += "100";
            break;
        case 5:
            res += "101";
            break;
        case 6:
            res += "110";
            break;
        case 7:
            res += "111";
            break;
        }
    };
    convert(n / 100);
    convert(n % 100 / 10);
    convert(n % 10);
    return res;
}

bool FileSys::login()
{
    string username, password;
    p("Username: ");
    cin >> username;
    p("Password: ");
    cin >> password;
    //读取主文件的用户，进行匹配登录
    ifstream sysfile(MAINFILE, ios::in | ios::binary);
    size_t userNum = 0;
    sysfile.read(reinterpret_cast<char *>(&userNum), sizeof(size_t));
    for (size_t i = 0; i < userNum; ++i)
    {
        sysfile.seekg(sizeof(size_t) + i * sizeof(User));
        sysfile.read(reinterpret_cast<char *>(&user), sizeof(User));
        //匹配成功，直接退出
        if (user.username == username && user.password == password)
        {
            pln("Login successfully");
            sysfile.close();
            return true;
        }
    }
    sysfile.close();
    //匹配失败，继续登录
    pln("Login Failed");
    return false;
}

void FileSys::adduser()
{
    User newUser;
    p("Username:");
    cin >> newUser.username;
    p("Password:");
    cin >> newUser.password;
    Inode root(0);
    newUser.inodeAddress = inodeTable.add(&root);
    fstream sysfile(MAINFILE, ios::in | ios::out | ios::binary);
    size_t userNum = 0;
    sysfile.read(reinterpret_cast<char *>(&userNum), sizeof(size_t));
    sysfile.seekp(sizeof(size_t) + userNum * sizeof(User)); //将文件写入位置移到sizeof(size_t) + userNum * sizeof(User)
    sysfile.write(reinterpret_cast<const char *>(&newUser), sizeof(User));
    ++userNum;
    sysfile.seekp(0); // 将文件写入位置移到开头
    sysfile.write(reinterpret_cast<const char *>(&userNum), sizeof(size_t));
    sysfile.close();
}

void FileSys::info()
{
    readnum();
    printf("----------磁盘容量：1M----------\n");
    printf("----------用户数量：%d------------\n", user_num);
    printf("            命令\n");
    printf("- info      列出文件系统信息\n\
- login     用户登录\n\
- dir       列文件目录\n\
- create    创建文件\n\
- delete    删除文件\n\
- open      打开文件\n\
- close     关闭文件\n\
- read      读文件\n\
- write     写文件\n");
}

void FileSys::readnum(){
    fstream sysfile(MAINFILE, ios::in | ios::out | ios::binary);
    size_t userNum = 0;
    sysfile.read(reinterpret_cast<char *>(&userNum), sizeof(size_t));
    user_num = userNum;
}

void FileSys::init()
{
    prefix += "~ " + string(user.username) + "$ "; //~zjx$
    ifstream sysfile(DATAFILE, ios::in | ios::binary);
    sysfile.seekg(user.inodeAddress); //根目录的inode地址
    sysfile.read(reinterpret_cast<char *>(&rootDir), sizeof(Inode));
    sysfile.close();
    file.setInode(&rootDir);
    FileEntry temp;
    nowFileEntry = &temp;
    fileEntrys = file.getDir();
}
