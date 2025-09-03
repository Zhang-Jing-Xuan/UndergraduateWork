//
//  main.cpp
//  四则运算
//
//  Created by admin on 2019/3/14.
//  Copyright © 2019年 admin. All rights reserved.
//

#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
double expression_value();
double factor_value();
double term_value();
int main(int argc, const char * argv[]) {
    //cout<<"A"<<endl;
    cout.setf(ios::fixed);//cout.unsetf(ios::fixed);
    cout<<fixed<<setprecision(2)<<expression_value()<<endl;
    return 0;
}
double expression_value(){
    double result=term_value();
    bool more=true;
    while(more){
        char c=cin.peek();
        if(c=='+'||c=='-'){
            cin.get();
            if(c=='+')result+=term_value();
            if(c=='-')result-=term_value();
            
        }else{
            more=false;
        }
    }
    return result;
}

double term_value(){
    double result=factor_value();
    bool more=true;
    while(more){
        char c=cin.peek();
        if(c=='*'||c=='/'){
            cin.get();
            if(c=='*')result*=factor_value();
            if(c=='/')result/=factor_value();
            
        }else{
            more=false;
        }
    }
    return result;
}

double factor_value(){
    double result=0;
    double next=10;
    bool flag=0;
    char c=cin.peek();
    if(c=='('){
        cin.get();
        result=expression_value();
        cin.get();
    }else{
        while(isdigit(c)||c=='.'){
        if(c=='.'){
            next=1;
            flag=1;
            cin.get();
            c=cin.peek();
        }
        if(flag){
            next*=0.1;
            result+=next*(c-'0');
            cin.get();
            c=cin.peek();
        }else{
            result=result*next+c-'0';
            cin.get();
            c=cin.peek();
        }
    }
    }
    return result;
}
