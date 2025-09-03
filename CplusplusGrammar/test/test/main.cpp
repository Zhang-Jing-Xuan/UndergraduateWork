//
//  main.cpp
//  test
//
//  Created by admin on 2019/11/29.
//  Copyright © 2019年 admin. All rights reserved.
//
#include <iostream>
using namespace std;

class A{
public:
    int x;
    A(int xx=0):x(xx){};
    int &f(){
        return x;
    }
};

class B{
public:
    A a;
    int y;
    B(int yy):a(yy),y(yy){};
    B(B&x):a(a.x),y(a.x){};
};
int main(){
    A a(5);
    A b=a;
    cout<<a.x<<" "<<b.x<<endl;
    return 0;
}
