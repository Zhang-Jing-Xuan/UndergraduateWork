//
//  main.cpp
//  运算符的重载——"+ -"
//
//  Created by admin on 2019/9/9.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Complex{
public:
    double real,imag;
    Complex(double r=0.0,double i=0.0):real(r),imag(i){};
    Complex operator -(const Complex &c);
    Complex operator +(const Complex &c);
    friend Complex operator +(double r,const Complex &c);
};
Complex Complex::operator-(const Complex &c){
    return Complex(real-c.real,imag-c.imag);
}
Complex Complex::operator+(const Complex &c){
    return Complex(real+c.real,imag+c.imag);
}

Complex operator +(double r,const Complex &c){
    return Complex(r+c.real,c.imag);
}
int main(int argc, const char * argv[]) {
    Complex a(4,4),b(1,1),c;
    c=a+b;
    cout<<c.real<<" "<<c.imag<<endl;
    cout<<(a-b).real<<" "<<(a-b).imag<<endl;
    cout<<"---------------------------"<<endl;
    c=1.5+a;
    cout<<c.real<<" "<<c.imag<<endl;
    return 0;
}


/*Complex operator +(const Complex &a,const Complex &b){
 return Complex(a.real+b.real,a.imag+b.imag);
 }*/
