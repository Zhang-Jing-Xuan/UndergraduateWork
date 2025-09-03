//
//  main.cpp
//  构造函数与析构函数
//
//  Created by admin on 2019/9/4.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

class String{
    private:
        char *p;
    public:
        String(){
            p=new char[10];
            cout<<"constructor"<<endl;
        }
        ~String();
};
String::~String(){
    cout<<"destructor"<<endl;
    delete []p;
}
int main(int argc, const char * argv[]) {
    String s[2];
    cout<<"endl"<<endl;
    return 0;
}
