#ifndef DictionaryTree_h
#define DictionaryTree_h

static const int N=100010,M=30;
static int son[N][M],idx,cnt[N];

void insert(const char str[]); // 字典树插入
int query(const char str[]); // 字典树查询
void dicInit(); // 字典树初始化
#endif