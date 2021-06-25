#ifndef InodeTable_h
#define InodeTable_h

#define INODE_BIT_SIZE 200*sizeof(bool) //inode表项的大小
#define INODE_TABLE_SIZE INODE_BIT_SIZE+10*BLOCK_SIZE   //整个inode表的大小

#include "Base.h"
#include "Bitmap.h"

//Inode 节点
class Inode{
public:
    Inode(size_t BN):blockNum(BN){}
    Inode(){}
    //存储iNode的磁盘块的地址
    size_t blockAddress[10];
    //该iNode磁盘块的个数
    size_t blockNum;
};

//Inode 表
class InodeTable{
public:
    InodeTable();
    //添加一个节点，返回其地址
    size_t add(Inode * i);
    //使用inode地址获取一个inode指针，废弃需delete
    Inode* getInode(size_t add);
    //输入地址，释放该inode的所有块以及该inode本身
    void release(size_t add,Bitmap* bitmap);
private:
    //inode表，false表示空闲，true为占用
    bool entry[200];
    //得到一个可以用的inode索引
    size_t getAvailable();
    //将表写入到磁盘
    void write();
};

#endif