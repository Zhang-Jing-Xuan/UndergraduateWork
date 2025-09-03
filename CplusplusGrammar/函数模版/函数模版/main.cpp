//
//  main.cpp
//  函数模版
//
//  Created by admin on 2019/12/7.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
void Swap(T&x,T&y){
    int t;
    t=x;x=y;y=t;
}

template <class T>
T Inc(T x){
    return x+1;
}

template<class T1,class T2>
void Swap2(T1 x,T2 y){
    T1 t;
    t=x;x=y;y=t;
}

int main(int argc, const char * argv[]) {
    int n1=1,m1=2;
    Swap(n1,m1);
    cout<<n1<<" "<<m1<<endl;
    cout<<Inc<double>(4)/2<<endl;//实例化
    int n2=3;double m2=3.4;
    Swap2(n2,m2);
    cout<<n2<<" "<<m2<<endl;
    return 0;
}
