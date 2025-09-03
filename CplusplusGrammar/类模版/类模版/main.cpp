//
//  main.cpp
//  类模版
//
//  Created by admin on 2019/12/7.
//  Copyright © 2019年 admin. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template<class T1,class T2>
class Pair{
public:
    T1 key;
    T2 value;
    Pair(T1 k,T2 v):key(k),value(v){}
    bool operator<(const Pair<T1,T2>&p)const;
};

template<class T1,class T2>
bool Pair<T1,T2>::operator <(const Pair<T1,T2>&p)const{
    return key<p.key;
}

class A{
public:
    template <class T>
    void print(T x){
        cout<<x<<endl;
    }
};

template<class T,int size>
class B{
private:
    T array[size];
public:
    void print(){
        for(int i=0;i<size;i++){
            cout<<array[i]<<" ";
        }
        puts("");
    }
};

template <class T>
class C{
private:
    static int cnt;
public:
    C(){cnt++;}
    ~C(){cnt--;}
    C(C&){cnt++;}
    static void printcnt(){cout<<cnt<<endl;}
};
template<> int C<int>::cnt=0;
template<> int C<double>::cnt=0;
int main(int argc, const char * argv[]) {
    Pair<string,int>s1("Tom",19);
    cout<<s1.key<<" "<<s1.value<<endl;
    cout<<"--------------------"<<endl;
    A a1;
    a1.print("I am a.");
    a1.print("200");
    cout<<"--------------------"<<endl;
    B<double,10>b1;
    b1.print();
    cout<<"--------------------"<<endl;
    C<int>c1;
    C<double>c2;
    c1.printcnt();
    c2.printcnt();
    C<double>c3(c2);
    c2.printcnt();
    c3.printcnt();
    return 0;
}
