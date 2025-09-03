//
//  main.cpp
//  C->C++
//
//  Created by admin on 2019/9/4.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n=4;

void swap(int &a,int &b){
    if(a==b)return;
    a=a^b;
    b=a^b;
    a=a^b;
}

int &get_value(){
    return n;
}
int main(int argc, const char * argv[]) {
    int a=4,b=5;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    get_value()=40;
    cout<<"n="<<n<<endl;
    cout<<"--------------"<<endl;
    const int &r=a;
    a=100;
    //r=1000;编译错误
    cout<<a<<" "<<r<<endl;
    cout<<"--------------"<<endl;
    int *p=new int;
    *p=5;
    int *pn;
    pn=new int[30];
    pn[0]=0;pn[29]=29;
    cout<<*p<<" "<<*(pn+29)<<endl;
    delete p;
    delete []pn;
    cout<<*p<<" "<<*(pn+29)<<endl;
    cout<<"20190921"<<endl;
    int *p1=new int[10];
    for(int i=0;i<10;i++){
        p1[i]=i;
    }
    for(int i=0;i<10;i++){
        cout<<p1[i]<<" ";
    }
    cout<<endl;
    delete []p1;
    return 0;
}
