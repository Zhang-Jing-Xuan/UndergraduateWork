//
//  main.cpp
//  vector容器
//
//  Created by admin on 2019/12/14.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> v(10);
    vector<int>::iterator i;
    for(i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }
    puts("");
    v.insert(v.begin()+4,13);
    for(i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }
    puts("");
    v.erase(v.begin());
    vector<int>v2(4,100);
    v.insert(v.begin(),v2.begin(),v2.end());
    for(i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }
    puts("");
    return 0;
}
