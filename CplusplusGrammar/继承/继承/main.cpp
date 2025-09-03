#include <iostream>
using namespace std;

class A{
protected:
    int a1,a2;
public:
    A(int aa1=0,int aa2=0):a1(aa1),a2(aa2){
        cout<<"A created"<<endl;
    }
    void f1(){
        cout<<"A::f1()"<<endl;
        cout<<"A.a1="<<a1<<endl;
        cout<<"A.a2="<<a2<<endl;
    }
    ~A(){
        cout<<"A died"<<endl;
    }
};

class B:public A{
protected:
    int b1;
public:
    B(int aa1=0,int aa2=0,int bb1=0):A(aa1,aa2),b1(bb1){
        cout<<"B created"<<endl;
    }
    void g1(){
        cout<<"B::g1()"<<endl;
        cout<<"B.a1="<<a1<<endl;
        cout<<"B.a2="<<a2<<endl;
        cout<<"B.a2="<<b1<<endl;
    }
    ~B(){
        cout<<"B died"<<endl;
    }
};

class C:public B{
protected:
    int c1;
public:
    C(int a11=0,int a22=0,int b11=0,int c11=0):B(a11,a22,b11),c1(c11){cout<<"C created"<<endl;}
    void h1(){
        cout<<"C::h1()"<<endl;
        cout<<"C.a1="<<a1<<endl;
        cout<<"C.a2="<<a2<<endl;
        cout<<"C.a2="<<b1<<endl;
        cout<<"C.c1="<<c1<<endl;
    }
    ~C(){
        cout<<"C died"<<endl;
    }
};
int main(){
    C c1(6,7,8,9);
    A &a1=c1;
    B &b1=c1;
    a1.f1();
    b1.g1();
    c1.h1();
    
    return 0;
}
