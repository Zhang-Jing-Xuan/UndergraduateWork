#include "FileSys.h"
//g++ -std=c++11 -o file main.cpp FileSys.cpp
// #include <bits/stdc++.h>

void insert(const char str[]) // 字典树插入
{
    int p = 0;                   // 字典树的根节点编号为0
    for (int i = 0; str[i]; i++) // 遍历要插入的字符串的每一位
    {
        int u = str[i] - 'a';  // 默认文件名都是小写
        if (!son[p][u])        // 如果不存在u节点
            son[p][u] = ++idx; // 就给u节点分配一个idx
        p = son[p][u];         // p走到刚才创建的节点
    }
    cnt[p]++; // 维护字典树中每个字符串出现的个数
}

int query(const char str[]) // 字典树查询
{
    int p = 0;                   // 字典树的根节点编号为0
    for (int i = 0; str[i]; i++) // 遍历要插入的字符串的每一位
    {
        int u = str[i] - 'a'; // 默认文件名都是小写
        if (!son[p][u])       // 如果不存在u节点
            return 0;         // 直接返回不存在
        p = son[p][u];        // 否则p往下走一步
    }
    return cnt[p]; // 返回字典树中要查询的那个字符串出现的个数
}

// 200个inode节点，每个inode 10个block
/********** InodeTable *********/
InodeTable::InodeTable() // InodeTable类构造函数
{
    ifstream sysfile(DATAFILE, ios::in | ios::binary);             // 读取二进制文件
    sysfile.seekg(0);                                              // 设置写文件指针的位置
    sysfile.read(reinterpret_cast<char *>(entry), INODE_BIT_SIZE); // 读取从文件指针开始INODE_BIT_SIZE大小的内容到entry(强制转换成char)
    sysfile.close();                                               // 关闭文件
}

size_t InodeTable::add(Inode *i) // 添加一个节点，返回其地址
{
    fstream sysfile(DATAFILE, ios::in | ios::out | ios::binary);      // 读写二进制文件
    size_t address = getAvailable() * sizeof(Inode) + INODE_BIT_SIZE; // 得到该节点的地址
    sysfile.seekp(address);                                           // 设置写文件指针的位置
    sysfile.write(reinterpret_cast<const char *>(i), sizeof(Inode));  // 把i的内容写到从文件指针开始的位置，写入内容的大小为sizeof(Inode)
    sysfile.close();                                                  // 关闭文件
    return address;                                                   //返回可用地址
}

Inode *InodeTable::getInode(size_t address) // 使用inode地址获取一个inode指针，废弃需delete
{
    ifstream sysfile(DATAFILE, ios::in | ios::binary);          // 读取二进制文件
    auto res = new Inode();                                     //创建一个Inode
    sysfile.seekg(address);                                     //调整文件指针
    sysfile.read(reinterpret_cast<char *>(res), sizeof(Inode)); // 读取从文件指针开始INODE大小的内容到res
    sysfile.close();                                            // 关闭文件
    return res;
}

size_t InodeTable::getAvailable() //得到一个可以用的inode索引
{
    for (size_t i = 0; i < 200; ++i) // 200个索引表项
    {
        if (entry[i] == false) // 如果inode表项空闲
        {
            entry[i] = true; //置为不空闲
            write();         // 将该表写入磁盘
            return i;        // 空闲的索引
        }
    }
    return -1; // 否则inode表不空闲，返回-1
}

void InodeTable::release(size_t add, Bitmap *bitmap) // 输入地址，释放该inode的所有块以及该inode本身
{
    auto cur = getInode(add);                  //使用inode地址获取一个inode指针
    for (size_t i = 0; i < cur->blockNum; ++i) //从0到该iNode磁盘块的个数
    {
        bitmap->release(cur->blockAddress[i]); // 释放位图中的iNode的磁盘块的地址
    }
    size_t index = (add - INODE_BIT_SIZE) / sizeof(Inode); // 得到该地址的索引
    if (index < 200)                                       // 200是最大值
        entry[index] = false;                              // 置index索引的inode为空闲
    write();                                               // 将entry表中的内容写到data.dat二进制文件中
    delete cur;                                            // 释放inode本身
}

void InodeTable::write() // 将表写入到磁盘
{
    fstream sysfile(DATAFILE, ios::out | ios::in | ios::binary);          // 读写二进制文件
    sysfile.seekp(0);                                                     //调整文件指针位置
    sysfile.write(reinterpret_cast<const char *>(entry), INODE_BIT_SIZE); //将entry表中的内容写到data.dat二进制文件中
    sysfile.close();                                                      //关闭文件
}

/********** Bit map *********/
void Bitmap::init() //初始化位图全为空闲
{
    for (size_t i = 0; i < BLOCK_NUM; ++i) //遍历所有块
        bitmap[i] = false;                 //将其置为空闲状态
}

void Bitmap::write() // 将位图写到磁盘
{
    fstream sysfile(DATAFILE, ios::out | ios::in | ios::binary);      // 读写二进制文件
    sysfile.seekp(INODE_TABLE_SIZE);                                  // 调整文件指针
    sysfile.write(reinterpret_cast<const char *>(this), BITMAP_SIZE); // 将Bitmap的内容写到从文件指针开始的位置，写入内容的大小为BITMAP_SIZE
    sysfile.close();                                                  // 关闭文件
}
size_t Bitmap::getNext() // 得到下一个可用的块的地址
{
    for (size_t i = 0; i < BLOCK_SIZE; ++i) //遍历所有块
    {
        if (!bitmap[i]) // 如果该位示图索引为i的地方不空闲
        {
            bitmap[i] = true;                                       //置为被占用
            write();                                                // 将位图写到磁盘
            return i * BLOCK_SIZE + INODE_TABLE_SIZE + BITMAP_SIZE; //返回可以被利用的块地址
        }
    }
    return -1; // 不存在可用的地址
}

void Bitmap::release(size_t add) //释放该块
{
    size_t index = (add - INODE_TABLE_SIZE - BITMAP_SIZE) / BLOCK_SIZE; //先得到该块的索引
    bitmap[index] = false;                                              //将该块的地址置为空闲
    write();                                                            // 将位图写到磁盘
}

/********** User *********/
void User::setUsername(string name) //设置用户名
{
    size_t len = name.size() < 30 ? name.size() : 29; // 限制用户名的大小最大30
    name.copy(username, len);                         // 将name拷贝到username中
    username[len] = '\0';                             // 标志字符串结束
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
    for (auto i : res)
    {
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
    memset(h, -1, sizeof(h));        //初始化邻接表表头为空
    id = 0;                          // 文件夹的个数
    current = 0;                     // 当前处于哪一级目录
    total = 0;                       // 文件和文件夹的总数
    memset(depth, 0, sizeof(depth)); //初始化深度为空
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
        else if (command == "overwrite")
            writeFile();
        else if (command == "append")
            appendFile();
        else if (command == "copy")
            copyFile();
        else if (command == "close")
            closeFile();
        else if (command == "info")
            info();
        else if (command == "exit")
            break;
        else if (command == "mkdir")
            mkdir();
        else if (command == "cd")
        {
            string dst;
            cin >> dst;
            if (dst == "..")
            {
                cdback();
            }
            else
            {
                cddir(dst);
            }
        }
        else
        {
            printf("命令出错!\n");
        }
    }
}

void FileSys::printDir()
{
    printf("Folder:\n");
    for (int i = h[current]; ~i; i = ne[i])
    {
        int j = e[i];
        if (depth[j] == depth[current] + 1)
        {
            cout << hash[j] << "\t";
        }
    }
    printf("\n");
    if (fileEntrys.size() == 0)
        return;
    cout << left << setw(15) << "FileName" << setw(9) << "Address" << setw(15) << "Protect code" << setw(10) << "Length" << endl;
    for (FileEntry &i : fileEntrys)
    {
        if (depth[rhash[i.fileName]] == depth[current])
        {
            cout << left << setw(15) << i.fileName << setw(9) << i.address << setw(15) << pcToBinary(i.protectCode) << setw(10) << i.length << endl;
        }
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

    total++; // 文件+文件夹的数量+1
    file.dir = false; // 不是文件夹
    depth[total] = depth[current]; // 该文件的深度和该文件夹的深度相同
    hash[total] = fileName; // 更新哈希表和反哈希表
    rhash[fileName] = total;
}

int FileSys::openFile() // 打开文件
{
    enterFileName(); // 用户输入文件名
    if (query(fileName.c_str()) == 0) // 到字典树中查找，判断该文件名是否已经存在，如果不存在
    {
        pln("No Such File"); // 输出不存在此文件并换行
        return -1;
    }
    for (size_t i = 0; i < fileEntrys.size(); ++i) // 遍历所有文件
    {
        if (string(fileEntrys[i].fileName) == fileName) //找到文件
        {
            nowFileEntry = &fileEntrys[i]; // 得到fileEntry[i]的地址
            // 绑定inode到找到的文件
            file.setInode(inodeTable.getInode(fileEntrys[i].address));
            pln("Open Successfully"); //输出打开成功并换行
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
    if (file.getInode() == NULL)
    {
        pln("Close Failed");
        return;
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
    int success = 1; // 标志源文件是否打开成功
    success = openFile(); 
    if (success == -1) // 如果打开失败
    {
        return;
    }
    copyRead(); // 读取源文件的内容
    success = openFile(); // 标志目标文件是否打开成功
    if (success == -1) // 如果打开失败
    {
        return;
    }
    copyWrite(); // 写入目标文件
    tmp = ""; // 清空缓存
}

void FileSys::copyRead()
{
    tmp = file.readAll(); // 读取源文件的内容
}

void FileSys::copyWrite() // 写入目标文件
{
    auto len = file.write(tmp, nowFileEntry->address); // 写到当前的i-node拥有的block里面
    nowFileEntry->length = len; // 更新文件长度
    file.setInode(&rootDir); // 绑定到根节点
    file.writeSelf(user.inodeAddress);            // 将本身i-node重新写入i-node表
    file.writeDir(fileEntrys, user.inodeAddress); //写inode为目录
}

void FileSys::appendFile() 
{
    if (nowFileEntry == NULL || nowFileEntry->fileName != fileName)
    {
        printf("请先打开该文件！\n");
        return;
    }
    copyRead();
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
    res = res.substr(0, res.size() - 1);
    tmp = tmp.substr(0, tmp.size() - 1);
    // cout<<tmp<<" "<<res<<endl;
    res = tmp + res;
    // res=res.substr(0,res.size()-1);
    // cout<<"res="<<res<<endl;
    auto len = file.write(res, nowFileEntry->address); // 写到当前的i-node拥有的block里面
    nowFileEntry->length = len;
    file.setInode(&rootDir);
    file.writeSelf(user.inodeAddress);            // 将本身i-node重新写入i-node表
    file.writeDir(fileEntrys, user.inodeAddress); //写inode为目录
    tmp = "";
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
    ofstream sysfile(MAINFILE, ios::binary);                           //写入二进制文件man.dat
    size_t i = 0;                                                      // 文件指针置为文件开头
    sysfile.write(reinterpret_cast<const char *>(&i), sizeof(size_t)); //将从文件开头开始size_t大小的内容写入sysfile
    sysfile.close();                                                   // 关闭二进制文件

    sysfile.open(DATAFILE, ios::binary); //打开二进制文件data.dat
    bool tempTable[200] = {0}; // 全部为零的bool数组
    sysfile.seekp(0); // 文件指针指向开头
    sysfile.write(reinterpret_cast<const char *>(tempTable), INODE_BIT_SIZE); //初始化二进制文件data.dat
    Bitmap tempBitmap; // 实例化临时的位示图
    tempBitmap.init(); // 初始化临时的位示图
    sysfile.seekp(INODE_TABLE_SIZE); // 调整文件指针
    sysfile.write(reinterpret_cast<const char *>(&tempBitmap), BITMAP_SIZE); //写到临时的位示图中
    sysfile.close(); // 关闭二进制文件data.dat

    file.readBitmap(); //读取位示图
    inodeTable = InodeTable(); //实例化索引表
}

string FileSys::pcToBinary(int n)
{
    string res = "";
    auto convert = [&res](int i) // lambda表达式
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
    printf("\
- info      列出文件系统信息\n\
- login     用户登录\n\
- dir       列出文件夹和文件目录\n\
- create    创建文件\n\
- delete    删除文件\n\
- open      打开文件\n\
- close     关闭文件\n\
- copy      拷贝文件\n\
- read      读文件\n\
- append    在文件末尾追加\n\
- overwrite 覆盖原文件\n\
- mkdir     新建目录\n\
- cd        进入目录\n\
");
}

void FileSys::readnum()
{
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

void FileSys::add(int a, int b)
{
    e[id] = b;
    ne[id] = h[a];
    h[a] = id++;
}

void FileSys::mkdir()
{
    string folderName;
    cin >> folderName;
    total++;
    depth[total] = depth[current] + 1;
    add(current, total);
    add(total, current);
    hash[total] = folderName;
    rhash[folderName] = total;
}

void FileSys::cddir(string dst)
{
    for (int i = h[current]; ~i; i = ne[i])
    {
        int j = e[i];
        if (hash[j] == dst)
        {
            current = rhash[dst];
            string x = prefix.substr(0, prefix.size() - 2);
            prefix = x + "/" + dst + "$ ";
            return;
        }
    }
    printf("目录不存在！\n");
}

void FileSys::cdback()
{
    if (current == 0)
    {
        printf("您已在根目录，无法回退！\n");
        return;
    }
    for (int i = h[current]; ~i; i = ne[i])
    {
        int j = e[i];
        if (depth[j] < depth[current])
        {
            current = j;
            for (int i = prefix.size(); i >= 0; i--)
            {
                if (prefix[i] == '/')
                {
                    prefix = prefix.substr(0, i);
                    prefix = prefix + "$ ";
                    return;
                }
            }
        }
    }
    printf("回退失败！\n");
    return;
}