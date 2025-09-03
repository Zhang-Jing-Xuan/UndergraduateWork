#ifndef User_h
#define User_h
#include "Base.h"
//用户
class User{
public:
    //用户名
    char username[30];
    //密码
    char password[30];
    //根目录的inode地址
    size_t inodeAddress;
    void setUsername(string name);
};

#endif