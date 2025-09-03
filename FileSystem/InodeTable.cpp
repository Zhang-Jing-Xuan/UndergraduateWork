#include "InodeTable.h"

// 200个inode节点，每个inode 10个block
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
