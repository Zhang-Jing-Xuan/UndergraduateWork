//
//  main.cpp
//  类的定义与访问
//
//  Created by admin on 2019/9/4.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

class Rectangle{
private:
    int w,h;
public:
    void init(int a,int b);
    int c();
    int s(){
        return w*h;
    }
};

void Rectangle::init(int a,int b){
    w=a;h=b;
}
int Rectangle::c(){
    return 2*(w+h);
}
int main(int argc, const char * argv[]) {
    cout<<"A"<<endl;
    int w,h;
    cin>>w>>h;
    Rectangle r;
    r.init(w,h);
    cout<<r.c()<<" "<<r.s()<<endl;
    cout<<"----------------"<<endl;
    Rectangle &r1=r;
    r.init(4,5);
    cout<<r1.c()<<" "<<r1.s()<<endl;
    return 0;
}
