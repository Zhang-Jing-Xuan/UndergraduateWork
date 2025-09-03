//
//  main.cpp
//  文件读写
//
//  Created by admin on 2019/11/30.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
//在in.txt中读数据，排序后在out.txt输出
int main(int argc, const char * argv[]) {
    vector<int>v;
    ifstream sf("in.txt",ios::in);
    ofstream df("out.txt",ios::out);
    int x;
    while(sf>>x){
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        df<<v[i]<<" ";
    }
    df.close();
    sf.close();
    return 0;
}
