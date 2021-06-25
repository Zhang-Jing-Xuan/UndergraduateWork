#ifndef File_h
#define File_h

//文件表项，实际储存于inode中
#define FILENAME 0
#define ADDRESS 1
#define PROTECTCODE 2
#define LENGTH 3

#include "Base.h"
#include "InodeTable.h"
#include "Bitmap.h"
#include "DictionaryTree.h"

class FileEntry{
public:
    //文件名
    char fileName[30];
    //文件地址
    size_t address;
    //保护位
    int protectCode;
    //文件长度
    size_t length;
    FileEntry(){
        fileName[0]=0;
        length=0;
    }
};

//文件类，集成了处理inode的各种方法
class File{
public:
    File(Inode* _i):inode(_i){readBitmap();}
    File(){readBitmap();}
    ~File(){}
    //绑定inode到当前类
    void setInode(Inode* i){inode=i;}
    //得到该inode
    Inode* getInode(){return inode;}
    //得到当前位图
    Bitmap* getBitmap(){return &bitmap;}
    //如inode为目录，解析内容成表项数组形式
    vector<FileEntry> getDir();
    //写inode为目录
    void writeDir(const vector<FileEntry>& dir, size_t inode_address);
    //读取inode所有内容
    string readAll();
    //写inode的内容
    size_t write(const string& towrite,size_t);
    //将inode本身写入磁盘
    void writeSelf(size_t address);
    //将字符串分成块的形式
    vector<string> split(const string& now);
    //从文件读取位图
    void readBitmap();
    //该文件是普通文件还是文件夹
    bool dir;
private:
    Inode* inode;
    Bitmap bitmap;
};
#endif