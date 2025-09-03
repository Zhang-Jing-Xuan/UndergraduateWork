//
//  main.cpp
//  友元函数
//
//  Created by admin on 2019/9/5.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
using namespace std;

class CCar;
class CDriver{
    public:
        void modify_car(CCar*pcar);
        //friend class CCar;
};
class CCar{
    private:
        int price;
        friend int most_expensive_car(CCar cars[],int total);
        friend void CDriver::modify_car(CCar *pcar);
    public:
    friend void print(CCar &c);
    CCar(int p);
};

CCar::CCar(int p){
    price=p;
}
void print(CCar &c){
    cout<<c.price<<endl;
}
void CDriver::modify_car(CCar *pcar){
    pcar->price+=1000;
}
int main(int argc, const char * argv[]) {
    CCar c(1000);
    print(c);
    
    return 0;
}
