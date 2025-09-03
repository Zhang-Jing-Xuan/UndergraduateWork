#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

const int MAXNT = 50, MAXT = 50; // 最大非终结符和终结符个数

struct Production // 产生式，2型文法（上下文无关文法，左部只有一个非终结符）
{
    char left; // 产生式左部
    vector<char> right; // 产生式右部符号串
};

struct Grammar // 文法
{
    int num, numT, numNT; // 产生式个数，终结符个数，非终结符个数
    vector<char> T; // 终结符
    vector<char> NT; // 非终结符
    vector<Production> productions; // 产生式
    Grammar() // 构造函数请空
    {
        num = numT = numNT = 0; 
        T.clear();
        NT.clear();
        productions.clear();
    }
} * G;

map<char, set<char>> First, Follow; // first,follow集
string str; // 待分析符号串
char stk[MAXT]; // 分析栈
int top = -1; // 栈顶指针
vector<char> table[MAXNT][MAXT]; // 预测分析表

bool flag=true; // 标识是否为LL(1)文法

int isT(char c) // 判断是否为终结符，若是返回序号
{
    for (int i = 0; i < G->numT; i++)
    {
        if (G->T[i] == c)
            return i + 1;
    }
    return 0;
}

int isNT(char c) // 判断是否为非终结符，若是返回序号
{
    for (int i = 0; i < G->numNT; i++)
    {
        if (G->NT[i] == c)
            return i + 1;
    }
    return 0;
}

void init() // 输入并初始化
{
    freopen("LL1.txt", "r", stdin);
    G = new (Grammar);
    cin >> G->num; // 输入产生式个数
    for (int i = 0; i < G->num; i++)
    {
        static char proc[50];
        cin >> proc; // 输入产生式,其中episilon用&代替，文法开始符号所在的产生式默认在第一个
        int len = strlen(proc);
        Production tmp;
        tmp.left = proc[0]; // 产生式左部
        for (int j = 3; j < len; j++) // 产生式右部
        {
            tmp.right.push_back(proc[j]);
        }
        G->productions.push_back(tmp);
    }
    char tmp = '\0'; // 输入非终结符，以#结尾
    while (cin >> tmp && tmp != '#')
    {
        G->NT.push_back(tmp);
        G->numNT++;
    }
    while (cin >> tmp && tmp != '#') // 输入终结符，以#结尾
    {
        G->T.push_back(tmp);
        G->numT++;
    }
    G->T.push_back('#'); // 将#看成是终结符
    G->numT++;
    cin >> str; // 输入待分析句子
    str += '#'; // 句子最后添加#
    stk[++top] = '#'; // 分析栈加入#
    stk[++top] = G->NT[0]; // 分析栈加入文法开始符号
}

void getFirst() // 求单个字符的first集
{
    for (int i = 0; i < G->numT; i++) // 终结符的first集就是它自己
    {
        char x = G->T[i];
        set<char> tmp;
        tmp.insert(x);
        First[x] = tmp;
    }
    bool change = true; // 是否改变
    while (change)
    {
        change = false;
        for (int i = 0; i < G->num; i++) // 遍历所有产生式
        {
            auto P = G->productions[i];
            char pLeft = P.left, pRight = P.right[0];
            if (pRight == '&' || isT(pRight)) // 如果该产生式右部是空或者第一个是终结符号
            {
                auto pos = First[pLeft].find(pRight);
                if (pos == First[pLeft].end()) // 判断是否已经加入到first中
                {
                    First[pLeft].insert(pRight);
                    change = true;
                }
            }
            else
            {   // 如果是非终结符A，并且A可以推导出episilon，则还要看后一个符号
                bool next = true; // 是否要看后一个符号
                int idx = 0, size = P.right.size();
                auto pRight = P.right;

                while (next && idx < size)
                {
                    next = false;
                    auto firstPRight = First[pRight[idx]];
                    auto pos = firstPRight.find('&');
                    if (pos == firstPRight.end()) // 不能推导出episilon，不需要看后一个符号
                    {
                        for (auto f : firstPRight)
                        {
                            if (First[pLeft].find(f) == First[pLeft].end())
                            {
                                First[pLeft].insert(f);
                                change = true;
                            }
                        }
                    }
                    else
                    {
                        for (auto f : firstPRight) // 能推导出episilon，需要看后一个符号
                        {
                            if (f != '&' && First[pLeft].find(f) == First[pLeft].end())
                            {   // 添加时去掉episilon
                                First[pLeft].insert(f);
                                change = true;
                            }
                        }
                        next = true;
                        idx++;
                    }
                }
                if(next&&First[pLeft].find('&') == First[pLeft].end()){
                    First[pLeft].insert('&');
                    change=true;
                }
            }
        }
    }
    cout << "First:" << endl;
    for (int i = 0; i < G->numNT; i++)
    {
        cout << G->NT[i] << " : ";
        for (auto f : First[G->NT[i]])
        {
            cout << f << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void getAlphaFirst(vector<char> s, set<char> &ans)
{
    bool next = true;
    int idx = 0, size = s.size();
    while (next && idx < size)
    {
        next = false;
        if (isT(s[idx]) || s[idx] == '&')
        {
            ans.insert(s[idx]);
        }
        else
        {
            if (First[s[idx]].find('&') == First[s[idx]].end())
            {
                for (auto i : First[s[idx]])
                {
                    if (ans.find(i) == ans.end())
                    {
                        ans.insert(i);
                    }
                }
            }
            else
            {
                for (auto i : First[s[idx]])
                {
                    if (i != '&' && ans.find(i) == ans.end())
                    {
                        ans.insert(i);
                    }
                }
                next = true;
                idx++;
            }
        }
    }
    if (next)
    {
        ans.insert('&');
    }
}

void getFollow()
{
    Follow[G->NT[0]].insert('#');
    bool change = true;
    while (change)
    {
        change = false;
        for (int i = 0; i < G->num; i++)
        {
            auto P = G->productions[i];
            char pLeft = P.left;
            vector<char> pRight = P.right;
            int size = pRight.size();
            for (int j = 0; j < size; j++)
            {
                if (isNT(pRight[j]))
                {
                    vector<char> tmp(pRight.begin() + j + 1, pRight.end());
                    set<char> S;
                    getAlphaFirst(tmp, S);
                    for (char k : S)
                    {
                        if (k != '&' && Follow[pRight[j]].find(k) == Follow[pRight[j]].end())
                        {
                            // if(pRight[j]=='A'&&(k=='*'||k=='/'))cout<<pLeft<<" ！"<<endl;
                            Follow[pRight[j]].insert(k);
                            change = true;
                        }
                    }
                    if (S.find('&') != S.end() || j + 1 >= size)
                    {
                        for (char k : Follow[pLeft])
                        {
                            if (k != '&' && Follow[pRight[j]].find(k) == Follow[pRight[j]].end())
                            {
                                // if(pRight[j]=='A'&&(k=='*'||k=='/'))cout<<pLeft<<endl;
                                Follow[pRight[j]].insert(k);
                                change = true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Follow:" << endl;
    for (int i = 0; i < G->numNT; i++)
    {
        cout << G->NT[i] << " : ";
        for (auto f : Follow[G->NT[i]])
        {
            cout << f << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void putProductionToTable(char NT, char T, Production proc)
{
    int row = isNT(NT) - 1, col = isT(T) - 1;
    if(table[row][col].size()){
        // cout<<NT<<" "<<T<<endl;
        flag=false;
    }
    table[row][col].push_back(proc.left);
    table[row][col].push_back('-');
    table[row][col].push_back('>');
    for (char c : proc.right)
    {
        table[row][col].push_back(c);
    }
    // cout<<row<<" "<<col<<" "<<NT<<" "<<T<<endl;
}

void getPridictTable()
{
    for (int i = 0; i < G->num; i++)
    {
        auto p = G->productions[i];
        auto pRight = p.right;
        set<char> S;
        getAlphaFirst(pRight, S);
        bool hasEpsilon = false;
        for (char c : S)
        {
            if (c == '&')
                hasEpsilon = true;
            if (c != '&')
            {
                putProductionToTable(p.left, c, p);
            }
        }
        if (hasEpsilon)
        {
            // cout<<"!!!!"<<endl;
            for (char c : Follow[p.left])
            {
                putProductionToTable(p.left, c, p);
            }
        }
    }
    if(!flag){
        cout<<"该文法不是LL(1)文法！"<<endl;
        return ;
    }
    cout << "Prediction table:" << endl;
    cout << "\t";
    for (char t : G->T)
    {
        cout << t << "\t";
    }
    cout << endl;
    for (char nt : G->NT)
    {
        cout << nt << "\t";
        for (char t : G->T)
        {
            vector<char> tmp = table[isNT(nt) - 1][isT(t) - 1];
            // cout<<tmp.size()<<"\t";
            for (char tt : tmp)
            {
                cout << tt;
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// string getString(int ip,string str){
//     string res;
//     int tmp=top;
//     while(tmp>=0)res+=stk[tmp--];
//     return res;
// }

void LL1()
{
    if(!flag){
        // cout<<"该文法不是LL(1)文法！"<<endl;
        return ;
    }
    int step = 1, ip = 0;
    // cout<<"Step\t"<<"Stack\t"<<"String\t"<<"Action"<<endl;
    do
    {
        if (isT(stk[top]) || stk[top] == '#')
        {
            if (stk[top] != str[ip])
            {
                cout << "Error 1" << endl;
                return;
            }
            else
            {
                cout << str[ip] << "匹配成功！" << endl;
                top--;
                ip++;
            }
        }
        else
        {
            vector<char> tmp = table[isNT(stk[top]) - 1][isT(str[ip]) - 1];
            if (tmp.size() == 0)
            {
                cout << "Error 2" << endl;
                return;
            }
            for (char c : tmp)
            {
                cout << c;
            }
            cout << endl;
            top--;
            if (tmp[3] != '&')
            {
                for (int i = tmp.size() - 1; i >= 3; i--)
                {
                    stk[++top] = tmp[i];
                }
            }
        }
    } while (top >= 0 && stk[top] != '#');
}

void solve()
{
    getFirst();
    getFollow();
    getPridictTable();
    LL1();
}

int main()
{
    init();
    solve();
    return 0;
}