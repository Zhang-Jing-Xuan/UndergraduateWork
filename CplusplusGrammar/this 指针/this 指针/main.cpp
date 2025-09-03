//
//  main.cpp
//  this 指针
//
//  Created by admin on 2019/9/4.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

class A{
    int i;
    public:
    void hello(){
        cout<<"hello"<<endl;
    }
};

class B{
    int a,b;
public:
    void print();
    B(int a1,int b1);
};
void B::print(){
    cout<<this->a<<" "<<this->b<<endl;
}
B::B(int a1,int b1){
    a=a1;b=b1;
}
int main(int argc, const char * argv[]) {
    A*p =NULL;
    p->hello();
    cout<<"20190921"<<endl;
    B q(1,2);
    q.print();
    return 0;
}
