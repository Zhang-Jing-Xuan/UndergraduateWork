#include "DictionaryTree.h"

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