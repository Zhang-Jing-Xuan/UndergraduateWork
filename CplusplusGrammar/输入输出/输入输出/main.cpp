//
//  main.cpp
//  输入输出
//
//  Created by admin on 2019/11/30.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    cout<<"请输入："<<endl;
    int x,y;
    while(cin>>x>>y){//control+D终止键盘输入
        freopen("in&out.txt","w",stdout);
        if(y==0){
            cerr<<"error"<<endl;
        }else{
            cout<<x/y<<" "<<x*y<<endl;
        }
    }
    freopen("in&out.txt","r",stdin);
    cin>>x>>y;
    cout<<x<<","<<y<<endl;
    
    return 0;
}
