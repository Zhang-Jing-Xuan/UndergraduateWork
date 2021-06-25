#ifndef Bitmap_h
#define Bitmap_h

#include "Base.h"

#define DATAFILE "data.dat"//该文件预留前十个块存放用户根目录inode节点
#define BLOCK_NUM 8192  //块数量
#define BLOCK_SIZE 1024 //块大小
#define BITMAP_SIZE sizeof(Bitmap)  //磁盘块位图的大小

//块的位图
class Bitmap{
public:
    void init();
    //得到下一个可用的块的地址
    size_t getNext();
    //释放该块
    void release(size_t add);
private:
    //块的位图，false为可用，true为已占用
    bool bitmap[BLOCK_NUM];
    //将位图写到磁盘
    void write();
};
#endif