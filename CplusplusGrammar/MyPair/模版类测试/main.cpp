//
//  main.cpp
//  模版类测试
//
//  Created by admin on 2019/12/16.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template<class T1,class T2>
class Pair{
public:
    T1 first;
    T2 second;
  //Pair(T1 k,T2 v):first(),second(v){};
    bool operator<(const Pair<T1,T2>&p)const;
    void make_Pair(T1 k,T2 v);
};
template<class T1,class T2>
bool Pair<T1,T2>::operator<(const Pair<T1, T2> &p)const{//常成员函数（只读函数）
    return first<p.first;
}
template<class T1,class T2>
void Pair<T1,T2>::make_Pair(T1 k,T2 v){
    first=k;second=v;
}
int main(int argc, const char * argv[]) {
    Pair<int,string>p[10];
    p[0].make_Pair(16,"a");
    p[1].make_Pair(12, "b");
    p[2].make_Pair(10, "c");
    sort(p,p+3);
    for(int i=0;i<3;i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    return 0;
}
