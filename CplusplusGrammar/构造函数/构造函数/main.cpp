//
//  main.cpp
//  构造函数
//
//  Created by admin on 2019/9/4.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int z=0;

class Complex{
    private:
        int real,imag;
        friend class Real;
    public:
        Complex(int r,int i);
    
        Complex(int r){
            real=r;
            cout<<"Int_Copy constructor called"<<endl;
        }
        void print();
        /*Complex(const Complex &c){
            real=c.real;
            imag=c.imag;
            cout<<"Copy constructor "<<z++<<"called"<<endl;
        }*/
};

Complex::Complex(int r,int i){
    real=r;imag=i;
}
void Complex::print(){
    cout<<real<<" "<<imag<<endl;
}

void Fun(Complex c){
    
}

Complex cz(1,2);
Complex Fun1(){
    return cz;
}

class Real{
    public:
        Complex cx=cz;
        void modify(){
            cx.real++;
        }
};

int main(int argc, const char * argv[]) {
    Complex c(1,2);
    c.print();
    Complex *cp[2]={new Complex(1),new Complex(2,3)};
    
    for(int i=0;i<1;i++){
        (*cp[i]).print();
    }
    cout<<"-------------"<<endl;
    Complex c1(2,5);
    Complex c2(c1);
    c2.print();
    Complex c3=c2;
    c3.print();
    Fun(c1);
    Fun1().print();
    cout<<"-------------"<<endl;
    c1=9;
    c1.print();
    return 0;
}
