//
//  main.cpp
//  运算符的重载——"="
//
//  Created by admin on 2019/9/9.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
//#include <string>
using namespace std;

class MyString{
private:
    char *str;//指向被分配的存储空间
public:
    ~MyString();
    MyString():str(new char[1]){str[0]=0;}
    const char* c_str(){return str;};
    MyString& operator =(const char* s);
    MyString  &  operator = (const MyString & s) {
        if(this==&s){
            return *this;
        }
        delete [] str;
        str = new char[strlen(s.str)+1];
        strcpy( str,s.str);
        return * this;
    }
    MyString(MyString &s){
        if(s.str){
            str=new char[strlen(s.str)+1];
            strcpy(str,s.str);
        }else{
            str=NULL;
        }
    }
};

MyString::~MyString(){
    delete []str;
}

MyString& MyString::operator =(const char *s){
    delete [] str;
    str = new char[strlen(s)+1];
    strcpy( str, s);
    return *this;
}


int main(int argc, const char * argv[]) {
    MyString s1,s2,s3;
    s1="GoodLuck!";
    s2="ABCDEFGHILKLMNOPQRSTUVWXYZ";
    (s3=s2)=s1;
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl;
    cout<<s3.c_str()<<endl;
    MyString s4(s1);
    cout<<s4.c_str()<<endl;
    return 0;
}
