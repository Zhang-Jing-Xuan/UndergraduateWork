#include <iostream>
using namespace std;

class A{
public:
    A(){}
    virtual void func(){
        cout<<"A::func"<<endl;
    }
    virtual void fund(){
        cout<<"A::fund"<<endl;
    }
    void fun(){
        cout<<"A::fun"<<endl;
    }
};

class B:public A{
public:
    B(){
        func();
    }
    void fun(){
        func();
    }
};

class C:public B{
public:
    C(){}
    void func(){
        cout<<"C::func"<<endl;
    }
    void fund(){
        cout<<"C::fund"<<endl;
    }
};
int main(){
    B*pb=new C();
    cout<<"up:pb created"<<endl;
    pb->fun();
    cout<<"up:pb->fun()"<<endl;
    pb->func();
    cout<<"up:pb->func()"<<endl;
    pb->fund();
    cout<<"up:pb->fund()"<<endl;
    return 0;
}
