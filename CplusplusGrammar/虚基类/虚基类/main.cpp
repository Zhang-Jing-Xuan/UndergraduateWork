//
//  main.cpp
//  虚基类
//
//  Created by admin on 2019/12/14.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
using namespace std;
class A{
public:
    int a1;
    A(int aa1=0):a1(aa1){
        a1=6;
        cout<<"a1="<<a1<<endl;
        
    }
};

class B:virtual public A{
public:
    int b1;
    B(int ba1=0,int bb1=0):A(ba1),b1(bb1){
        a1+=10;
        cout<<"B::a1="<<a1<<endl;
    }
};

class C:virtual public A{
public:
    int c1;
    C(int ca1=0,int cc1=0):A(ca1),c1(cc1){
        a1+=9;
        cout<<"C::a1="<<a1<<endl;
    }
};

class D:public B,public C{
public:
    int d1;
    D(int da1=0,int db1=0,int dc1=0,int dd1=0):B(da1,db1),C(da1,dc1),d1(dd1){
        
    }
};
int main(int argc, const char * argv[]) {
    D(1,2,3,4);
    return 0;
}
