//
//  main.cpp
//  流操纵算子
//
//  Created by admin on 2019/11/30.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <iomanip>//流操纵算子
using namespace std;

ostream& tab(ostream&output){//自定义流操纵算子
    return output<<'\t';
}

ostream& happy(ostream&output){
    return output<<"😀😜🤪"<<endl;
}

int main(int argc, const char * argv[]) {
    double a1=1234567.89,a2=12.34;
    cout<<setprecision(5)<<a1<<endl;//科学计数法
    cout<<a1<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(5)<<a1<<endl;
    cout<<resetiosflags(ios::fixed)<<a2<<endl;
    int w=4;
    char string[10];
    cout<<"please input:"<<endl;
    cin.width(5);
    while(cin>>string){
        cout.width(w++);
        cout<<string<<endl;
        cin.width(5);
    }
    cout<<4<<tab<<5<<endl;
    cout<<happy;
    return 0;
}
