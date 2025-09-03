//
//  main.cpp
//  友元
//
//  Created by admin on 2019/9/5.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

class CCar{
    private:
        int price;
        friend class CDriver;
};

class CDriver{
    public:
        CCar mycar;
        void modify_car();
};
void CDriver::modify_car(){
    mycar.price+=1000;
    
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
