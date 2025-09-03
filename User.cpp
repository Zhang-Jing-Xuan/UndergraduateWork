#include "User.h"

void User::setUsername(string name) //设置用户名
{
    size_t len = name.size() < 30 ? name.size() : 29; // 限制用户名的大小最大30
    name.copy(username, len);                         // 将name拷贝到username中
    username[len] = '\0';                             // 标志字符串结束
}