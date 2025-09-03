//
//  main.cpp
//  运算符重载综合
//
//  Created by admin on 2019/12/14.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Complex{
public:
    int real,imag;
    Complex(int r=0,int i=0):real(r),imag(i){};
    
    Complex operator+(const Complex &c);
    friend Complex operator-(const Complex &c1,const Complex &c2);
    
    friend ostream& operator<<(ostream& os,const Complex &c);
    friend istream& operator<<(istream& is,Complex &c);
};
Complex Complex::operator+(const Complex &c){
    return Complex(real+c.real,imag+c.imag);
}
Complex operator-(const Complex &c1,const Complex &c2){
    return Complex(c1.real-c2.real,c1.imag-c2.imag);
}

ostream& operator<<(ostream&os,const Complex&c){
    if(c.imag<0){
        cout<<c.real<<'-'<<c.imag<<'i';
    }else{
        cout<<c.real<<'+'<<c.imag<<'i';
    }
    return os;
}

istream& operator>>(istream&is,Complex&c){
    string sc;
    cin>>sc;
    int pos1=(int)sc.find('+',0);
    if(pos1!=sc.npos){
        string s1=sc.substr(0,pos1);
        c.real=atof(s1.c_str());
        s1=sc.substr(pos1+1,sc.length()-pos1-2);
        c.imag=atof(s1.c_str());
    }
    return is;
}
int main(int argc, const char * argv[]) {
    cout<<"Please input a complex:"<<endl;
    Complex c1,c2(1,2);
    int i=0;
    while(cin>>c1){
        cout<<"第"<<++i<<"次输出:"<<endl;
        cout<<c1<<endl;
        cout<<(c1-c2)<<endl;
        cout<<(c1+c2)<<endl;
    }
    return 0;
}
