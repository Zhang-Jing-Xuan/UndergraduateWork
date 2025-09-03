//
//  main.cpp
//  产生式系统
//
//  Created by admin on 2020/9/23.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

const int N=50,M=25,MAX=100;//N为最大值,从M到m为动物

int n,m;//n为特征数量,m为规则数量

map<string,int> features;
map<int,string> mp;
vector<int>rules[N];//规则库
vector<int>db;//综合数据库
bool st[N];//标记每条规则是否被用过
bool back;//正向推理还是反向推理
bool vis[N];

void Pre_Treatment(){
    ifstream f1("feature.txt",ifstream::in);
    string s;
    while(f1>>s){
        features[s]=++n;
        mp[n]=s;
    }
    f1.close();
    ifstream f2("rules.txt",ifstream::in);
    while(getline(f2,s)){
        m++;
        stringstream ss;
        ss<<s;
        while(ss>>s){
            if(s=="IF"||s=="AND")continue;
            if(s=="THEN")break;
            rules[m].push_back(features[s]);
        }
        rules[m].push_back(-1);
        ss>>s;
        rules[m].push_back(features[s]);
    }
    f2.close();
}

set<int>S;
void Input(){
    string s;
    cout<<"请输入该动物的特征(以END结束):"<<endl;
    while(cin>>s){
        if(s=="END")break;
        if(back)S.insert(features[s]);
        db.push_back(features[s]);
    }
    
}

bool check(){
    for(int i:db)cout<<mp[i]<<" ";
    cout<<endl;
    for(int i:db){
        if(i>=M&&i<=n){
            cout<<"该动物是"<<mp[i]<<endl;
            return true;
        }
    }
    return false;
}

bool match_rules(int u){//尝试匹配第u条规则
    set<int>S;
    for(int i:db)S.insert(i);
    for(int i:rules[u]){
        if(i==-1)break;
        if(!S.count(i))return false;
    }
    return true;
}

bool Forward_Reasoning(){
    cout<<"正向推理过程如下："<<endl;
    while(true){
        if(check())return true;
        int i=1;
        for(i=1;i<=m;i++){
            if(st[i])continue;
            if(match_rules(i)){
                int Size=(int)rules[i].size();
                db.push_back(rules[i][Size-1]);
                st[i]=true;
                break;
            }
        }
        if(i==m+1)return false;
    }
    return false;
}

int h[MAX],e[MAX],ne[MAX],idx,id;

void add(int a,int b){
//    cout<<a<<" "<<b<<endl;
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}

void build(){
    for(int i=1;i<=m;i++){
        int Size=(int)rules[i].size();
        if(Size==3){
            add(rules[i][2],rules[i][0]);
        }else{
            id++;
            add(rules[i][Size-1],id);
            for(int j=0;j<Size-2;j++){
                if(rules[i][j]==0)cout<<"! "<<i<<endl;
                add(id,rules[i][j]);
            }
        }
    }
}

bool dfs(int u,bool flag){
//    cout<<u<<" "<<flag<<endl;
    if(!flag){
        for(int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if(j<=19&&S.count(j)){
                vis[j]=true;
                cout<<"该动物"<<mp[j]<<","<<"符合特征。"<<endl;
                return true;
            }
            else if(j>19&&j<=M-1&&dfs(j,0)){
                vis[j]=true;
                cout<<"该动物是"<<mp[j]<<","<<"符合特征。"<<endl;
                return true;
            }
            else if(j>n&&dfs(j,1)){
                for(int k=h[j];~k;k=ne[k]){
                    int t=e[k];
                    if(vis[t]&&t<n){
                        cout<<"该动物"<<mp[t]<<","<<"符合特征。"<<endl;
                    }
                }
                return true;
            }
        }
        return false;
    }else{
        for(int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if(j<=19&&!S.count(j)){
                cout<<"该动物没"<<mp[j]<<","<<"不符合特征。"<<endl;
                return false;
            }
            else if(j>19&&j<=M-1&&!dfs(j,0)){
                return false;
            }
            else if(j>n&&!dfs(j,1))
                return false;
        }
        for(int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if(j<n)cout<<"该动物"<<mp[j]<<","<<"符合特征。"<<endl;
        }
        return true;
    }
}

bool Back_Reasoning(){
    cout<<"反向推理过程如下："<<endl;
    for(int i=M;i<=n;i++){
        cout<<"假设该动物是"<<mp[i]<<"："<<endl;
        if(dfs(i,0)){
            cout<<"该动物是"<<mp[i]<<endl;
            return true;
        }
        cout<<"假设该动物是"<<mp[i]<<"不成立。"<<endl<<endl;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    cout<<"正向推理还是反向推理？（F/B）"<<endl;
    string s;
    cin>>s;
    if(s=="B")back=1;
    else back=0;
    Pre_Treatment();
    Input();
    if(!back){
        while(!Forward_Reasoning()){
            cout<<"无法确定该动物，是否继续输入该动物的特征？（Yes/No）"<<endl;
            string s;
            cin>>s;
            if(s=="No"){
                cout<<"无法确定该动物。"<<endl;
                break;
            }else{
                Input();
            }
        }
    }else{
        memset(h,-1,sizeof(h));
        idx=0;id=n;
        build();
        while(!Back_Reasoning()){
            cout<<"无法确定该动物，是否继续输入该动物的特征？（Yes/No）"<<endl;
            string s;
            cin>>s;
            if(s=="No"){
                cout<<"无法确定该动物。"<<endl;
                break;
            }else{
                Input();
            }
        }
    }
    return 0;
}


/*
输入样例1:
有暗斑点 有长脖子 有长腿 有奶 有蹄 END
 

输入样例2:
有暗斑点 有长脖子 有长腿 有奶 END
Yes
有蹄 END
 
输入样例3:
有羽毛 善飞 END
 */
