//
//  main.cpp
//  二进制文件读写
//
//  Created by admin on 2019/11/30.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
//向文件中写入和读取一个整数
int main(int argc, const char * argv[]) {
    ofstream fout("bin.txt",ios::out|ios::binary);
    int x=65;
    fout.write((const char*)&x, sizeof(int));
    //第一个参数是x的内存地址
    fout.close();
    ifstream fin("bin.txt",ios::in|ios::binary);
    int y;
    fin.read((char*)&y,sizeof(int));
    fin.close();
    cout<<y<<endl;
    return 0;
}
