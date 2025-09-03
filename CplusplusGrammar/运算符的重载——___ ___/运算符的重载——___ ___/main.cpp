//
//  main.cpp
//  运算符的重载——">> <<"
//
//  Created by admin on 2019/10/3.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Complex {
private:
    double real,imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){};
    friend ostream& operator <<(ostream &os,const Complex &c);
    friend istream& operator >>(istream &is,Complex &c);
};
ostream& operator <<(ostream &os,const Complex &c){
    cout<<c.real<<"+"<<c.imag<<"i";
    return os;
}
istream& operator >>(istream&is,Complex &c){
    string s;
    cin>>s;
    int pos=(int)s.find('+',0);
    string sTmp=s.substr(0,pos);
    c.real=atof(sTmp.c_str());
    sTmp=s.substr(pos+1,s.length()-pos-2);
    c.imag=atof(sTmp.c_str());
    return is;
}
int main(int argc, const char * argv[]) {
    cout<<"A"<<endl;
    Complex c;
    int n;
    cin>>c>>n;
    cout<<c<<","<<n<<endl;
    return 0;
}
