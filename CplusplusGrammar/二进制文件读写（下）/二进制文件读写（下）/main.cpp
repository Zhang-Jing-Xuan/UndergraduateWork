//
//  main.cpp
//  二进制文件读写（下）
//
//  Created by admin on 2019/11/30.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
struct Student{
    char name[20];
    int score;
};
int main(int argc, const char * argv[]) {
    cout<<"please input:"<<endl;
    Student s;
    ofstream OutFile("/Users/admin/Desktop/测试文件/学生",ios::out|ios::binary);
    while(cin>>s.name>>s.score){
        OutFile.write((char*)&s, sizeof(s));
    }
    OutFile.close();
    ifstream inFile("学生",ios::in|ios::binary);
    if(!inFile){
        cout<<"error"<<endl;
        return 0;
    }
    int readBytes=0;
    while(inFile.read((char*)&s,sizeof(s))){
        readBytes=(int)inFile.gcount();//看刚才读了多少字节
        cout<<s.name<<" "<<s.score<<endl;
    }
    //cout<<readBytes<<endl;
    inFile.close();
    fstream iofile("学生",ios::in|ios::out|ios::binary);
    if(!iofile){
        cout<<"error"<<endl;
        return 0;
    }
    iofile.seekp(2*sizeof(s),ios::beg);//定位写指针到第三条记录
    iofile.write("Mike",strlen("Mike")+1);
    iofile.seekg(0,ios::beg);//定位写指针到开头
    while(iofile.read((char*)&s,sizeof(s))){
        cout<<s.name<<" "<<s.score<<endl;
    }
    iofile.close();
    return 0;
}
/*输入数据：
Tom 60
Jack 80
Jane 40
*/
