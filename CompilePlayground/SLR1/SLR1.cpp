#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

const int MAXSTATE = 100;

bool flag=true;

struct Production
{
    char left;
    vector<char> right;
    bool operator==(const Production &p) const
    {
        if (left != p.left || right.size() != p.right.size())
        {
            return false;
        }
        int size = right.size();
        for (int i = 0; i < size; i++)
        {
            if (right[i] != p.right[i])
                return false;
        }
        return true;
    }
};

struct LR0Item
{
    Production production;
    int location;
};
struct LR0Items
{
    vector<LR0Item> items;
};

struct canonicalCollection
{
    vector<LR0Items> items;
    vector<pair<char, int>> g[MAXSTATE];
} * C;

queue<pair<LR0Items, int>> Q;
stack<pair<int, char>> stk;

pair<int, int> actionTable[MAXSTATE][MAXSTATE];
int gotoTable[MAXSTATE][MAXSTATE];

struct Grammar
{
    int num, numT, numNT;
    vector<char> T;
    vector<char> NT;
    vector<Production> productions;
    Grammar()
    {
        num = numT = numNT = 0;
        T.clear();
        NT.clear();
        productions.clear();
    }
} * G;

map<char, set<char>> First, Follow;
string str;

int isT(char c)
{
    for (int i = 0; i < G->numT; i++)
    {
        if (G->T[i] == c)
            return i + 1;
    }
    return 0;
}

int isNT(char c)
{
    for (int i = 0; i < G->numNT; i++)
    {
        if (G->NT[i] == c)
            return i + 1;
    }
    return 0;
}

void init()
{
    freopen("SLR1.txt", "r", stdin);
    G = new (Grammar);
    cin >> G->num;
    for (int i = 0; i < G->num; i++)
    {
        static char proc[50];
        cin >> proc;
        int len = strlen(proc);
        Production tmp;
        tmp.left = proc[0];
        for (int j = 3; j < len; j++)
        {
            tmp.right.push_back(proc[j]);
        }
        G->productions.push_back(tmp);
    }
    char tmp = '\0';
    while (cin >> tmp && tmp != '#')
    {
        G->NT.push_back(tmp);
        G->numNT++;
    }
    while (cin >> tmp && tmp != '#')
    {
        G->T.push_back(tmp);
        G->numT++;
    }
    G->T.push_back('#');
    G->numT++;
    C = new (canonicalCollection);
    cin >> str;
    str += '#';
    stk.push(make_pair(0, '#'));
}

void getFirst()
{
    for (int i = 0; i < G->numT; i++)
    {
        char x = G->T[i];
        set<char> tmp;
        tmp.insert(x);
        First[x] = tmp;
    }
    bool change = true;
    while (change)
    {
        change = false;
        for (int i = 0; i < G->num; i++)
        {
            auto P = G->productions[i];
            char pLeft = P.left, pRight = P.right[0];
            if (pRight == '&' || isT(pRight))
            {
                auto pos = First[pLeft].find(pRight);
                if (pos == First[pLeft].end())
                {
                    First[pLeft].insert(pRight);
                    change = true;
                }
            }
            else
            {
                bool next = true;
                int idx = 0, size = P.right.size();
                auto pRight = P.right;

                while (next && idx < size)
                {
                    next = false;
                    auto firstPRight = First[pRight[idx]];
                    auto pos = firstPRight.find('&');
                    if (pos == firstPRight.end())
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
                        for (auto f : firstPRight)
                        {
                            if (f != '&' && First[pLeft].find(f) == First[pLeft].end())
                            {
                                First[pLeft].insert(f);
                                change = true;
                            }
                        }
                        next = true;
                        idx++;
                    }
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

bool isInItems(LR0Items &I, LR0Item &t)
{
    for (auto it = I.items.begin(); it != I.items.end(); it++)
    {
        LR0Item tmp = *it;
        if (tmp.location == t.location && tmp.production == t.production)
            return true;
    }
    return false;
}

int isInC(LR0Items &I)
{
    for (auto it = C->items.begin(); it != C->items.end(); it++)
    {
        bool flag = true;
        LR0Items tmp = *it;
        if (tmp.items.size() != I.items.size())
        {
            flag = false;
            continue;
        }
        for (auto itt = I.items.begin(); itt != I.items.end(); itt++)
        {
            LR0Item t = *itt;
            if (!isInItems(tmp, t))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return it - C->items.begin() + 1;
    }
    return false;
}

void printLR0Items(LR0Items &I)
{
    for (auto it = I.items.begin(); it != I.items.end(); it++)
    {
        Production tmpP = it->production;
        int tmpL = it->location;
        cout << tmpP.left << "->";
        int size = tmpP.right.size();
        for (int i = 0; i < size; i++)
        {
            if (i == tmpL)
                cout << ".";
            cout << tmpP.right[i];
        }
        if(tmpL==size)cout<<".";
        cout << endl;
    }
}

void getClosure(LR0Items &I)
{
    bool change = true;
    while (change)
    {
        change = false;
        LR0Items J;
        J.items.assign(I.items.begin(), I.items.end());
        for (auto it = J.items.begin(); it != J.items.end(); it++)
        {
            LR0Item t = *it;
            if (t.location < t.production.right.size())
            {
                char c = t.production.right[t.location];
                if (isNT(c))
                {
                    for (auto p : G->productions)
                    {
                        if (p.left == c)
                        {
                            LR0Item tmp;
                            tmp.production = p;
                            tmp.location = 0;
                            if (!isInItems(I, tmp))
                            {
                                change = true;
                                I.items.push_back(tmp);
                            }
                        }
                    }
                }
            }
        }
    }
}

void go(LR0Items &I, char c, LR0Items &J)
{
    for (auto i : I.items)
    {
        Production p = i.production;
        int l = i.location;
        if (l < p.right.size())
        {
            char x = p.right[l];
            if (x == c)
            {
                LR0Item tmp;
                tmp.location = l + 1;
                tmp.production = p;
                J.items.push_back(tmp);
            }
        }
    }
    if (J.items.size() > 0)
    {
        getClosure(J);
    }
}

void getDFA()
{
    LR0Item I;
    I.location = 0;
    I.production.left = G->productions[0].left;
    I.production.right.assign(G->productions[0].right.begin(), G->productions[0].right.end());
    LR0Items Is;
    Is.items.push_back(I);
    getClosure(Is);
    C->items.push_back(Is);
    Q.push(make_pair(Is, 0));
    while (Q.size())
    {
        LR0Items Is = Q.front().first;
        int stateIdx = Q.front().second;
        for (int i = 0; i < G->numT; i++)
        {
            LR0Items d;
            go(Is, G->T[i], d);
            if (d.items.size() > 0)
            {
                int idx = isInC(d);
                if (idx > 0)
                {
                    idx -= 1;
                }
                else
                {
                    idx = C->items.size();
                    C->items.push_back(d);
                    Q.push(make_pair(d, idx));
                }
                C->g[stateIdx].push_back(make_pair(G->T[i], idx));
            }
        }
        for (int i = 0; i < G->numNT; i++)
        {
            LR0Items d;
            go(Is, G->NT[i], d);
            if (d.items.size() > 0)
            {
                int idx = isInC(d);
                if (idx > 0)
                {
                    idx -= 1;
                }
                else
                {
                    idx = C->items.size();
                    C->items.push_back(d);
                    Q.push(make_pair(d, idx));
                }
                C->g[stateIdx].push_back(make_pair(G->NT[i], idx));
            }
        }
        Q.pop();
    }
    int cSize = C->items.size();
    cout << "The size of the carnonimal collections is " << cSize << endl;
    for (int i = 0; i < cSize; i++)
    {
        cout << "LR0Items " << i << " :"<<endl;
        printLR0Items(C->items[i]);
        for (int j = 0; j < C->g[i].size(); j++)
        {
            pair<char, int> t = C->g[i][j];
            cout << "To " << t.second << " by " << t.first << endl;
        }
    }
}

void getPredictionTable()
{
    int cSize = C->items.size();
    for (int i = 0; i < cSize; i++)
    {
        for (auto item : (C->items)[i].items)
        {
            Production p = item.production;
            int l = item.location;
            if (l < p.right.size())
            {
                char c = p.right[l];
                if (isT(c))
                {
                    for (int j = 0; j < C->g[i].size(); j++)
                    {
                        pair<char, int> tmp = C->g[i][j];
                        if (tmp.first == c)
                        {
                            // if(actionTable[i][isT(c) - 1].first)flag=false;
                            actionTable[i][isT(c) - 1].first = 1;
                            actionTable[i][isT(c) - 1].second = tmp.second;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (p.left == G->productions[0].left)
                {
                    // if(actionTable[i][G->numT - 1].first)flag=false;
                    actionTable[i][G->numT - 1].first = 3;
                }
                else
                {
                    char x = p.left;
                    for (auto c : Follow[x])
                    {
                        int j = isT(c) - 1;
                        for (int k = 0; k < G->productions.size(); k++)
                        {
                            if (G->productions[k] == p)
                            {
                                if(actionTable[i][j].first==1){
                                    cout<<"在状态"<<i<<"存在移进-归约冲突"<<endl;
                                    flag=false;
                                }else if(actionTable[i][j].first==2){
                                    cout<<"在状态"<<i<<"存在归约-归约冲突"<<endl;
                                    flag=false;
                                }
                                actionTable[i][j].first = 2;
                                actionTable[i][j].second = k;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < C->g[i].size(); j++)
        {
            pair<char, int> tmp = C->g[i][j];
            char c = tmp.first;
            if (isNT(c) > 0)
            {
                gotoTable[i][isNT(c) - 1] = tmp.second;
            }
        }
    }
    if(!flag){
        cout<<"该文法不是SLR(1)文法！"<<endl;
        return ;
    }
    cout<<"Prediction table:"<<endl;
    for (int i = 0; i < G->numT / 2; i++)
        cout << "\t";
    cout << "action";
    for (int i = 0; i < G->numT / 2 + G->numNT / 2; i++)
        cout << "\t";
    cout << "goto" << endl
         << "\t";
    for (int i = 0; i < G->numT; i++)
        cout << G->T[i] << "\t";
    cout << "|";
    for (int i = 1; i < G->numNT; i++)
        cout << G->NT[i] << "\t";
    cout << endl;
    for (int i = 0; i < cSize; i++)
    {
        cout << i << "\t";
        for (int j = 0; j < G->numT; j++)
        {
            if (actionTable[i][j].first == 1)
            {
                cout << "s" << actionTable[i][j].second << "\t";
            }
            else if (actionTable[i][j].first == 2)
            {
                cout << "r" << actionTable[i][j].second << "\t";
            }
            else if (actionTable[i][j].first == 3)
            {
                cout << "acc"
                     << "\t";
            }
            else
            {
                cout << "\t";
            }
        }
        cout << "|";
        for (int j = 1; j < G->numNT; j++)
        {
            if (gotoTable[i][j])
            {
                cout << gotoTable[i][j] << "\t";
            }
            else
            {
                cout << "\t";
            }
        }
        cout << endl;
    }
}

void SLR1()
{
    if(!flag)return ;
    int ip = 0;
    do
    {
        int st = stk.top().first;
        char c = str[ip];
        int j = isT(c) - 1;
        if (actionTable[st][j].first == 1)
        {
            int newst = actionTable[st][j].second;
            ip++;
            char newc = str[ip];
            stk.push(make_pair(newst, newc));
        }
        else if (actionTable[st][j].first == 2)
        {
            int procId = actionTable[st][j].second;
            Production p = G->productions[procId];
            cout << p.left << "->";
            int size = p.right.size();
            for (int i = 0; i < size; i++)
            {
                cout << p.right[i];
                stk.pop();
            }
            cout << endl;
            int j = isNT(p.left) - 1;
            int i = stk.top().first;
            if (gotoTable[i][j] > 0)
            {
                stk.push(make_pair(gotoTable[i][j], p.left));
            }
            else
            {
                cout << "error1" << endl;
            }
        }
        else if (actionTable[st][j].first == 3)
        {
            cout << "acc" << endl;
            return;
        }
        else
        {
            cout << "error2" << endl;
            return;
        }
    } while (true);
}

void solve()
{
    getFirst();
    getFollow();
    getDFA();
    getPredictionTable();
    SLR1();
}

int main()
{
    init();
    solve();
    return 0;
}

/*
4
A->S
S->iSeS
S->iS
S->a
A S #
i e a #
iae
*/