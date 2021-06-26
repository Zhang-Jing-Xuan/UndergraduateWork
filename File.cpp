#include "File.h"

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
    // for (auto i : res)
    //  {
    //      insert(i.fileName);
    //  }
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
