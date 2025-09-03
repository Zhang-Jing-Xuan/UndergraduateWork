//
//  main.cpp
//  运算符的重载——类型转换
//
//  Created by admin on 2019/10/3.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Complex{
private:
    double real,imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){};
    operator float(){
        return real;
    }
    /*operator double(){
        return sqrt(real*real+imag*imag);
    }*/
};
int main(int argc, const char * argv[]) {
    Complex c(1.1,2.2);
    double d=double(c);
    cout<<"d="<<d<<endl;
    d=c+1.5;
    cout<<"d="<<d<<endl;
    return 0;
}
