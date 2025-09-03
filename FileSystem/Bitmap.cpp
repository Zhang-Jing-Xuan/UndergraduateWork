#include "Bitmap.h"
#include "InodeTable.h"

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
