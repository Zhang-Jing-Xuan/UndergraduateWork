//
//  main.cpp
//  运算符重载——自增自减
//
//  Created by admin on 2019/10/3.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class CDemo{
private:
    int n;
public:
    CDemo(int i=0):n(i){}
    CDemo &operator++();//++x;
    CDemo operator++(int);//x++;
    friend CDemo &operator--(CDemo&);//--x;
    friend CDemo operator--(CDemo&,int);//x--;
    operator int(){return n;}
};
CDemo&CDemo::operator++(){
    n++;
    return *this;
}
CDemo CDemo::operator++(int){
    CDemo CTmp(*this);
    n++;
    return CTmp;
}
CDemo&operator--(CDemo&d){
    d.n--;
    return d;
}
CDemo operator--(CDemo&d,int){
    CDemo CTmp(d);
    d.n--;
    return CTmp;
}
int main(int argc, const char * argv[]) {
    CDemo d(5);
    cout<<d++<<",";
    cout<<d<<",";
    cout<<++d<<",";
    cout<<d<<endl;
    
    cout<<d--<<",";
    cout<<d<<",";
    cout<<--d<<",";
    cout<<d<<endl;
    return 0;
}
