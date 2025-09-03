//
//  main.cpp
//  随机数生成器以及时间函数
//
//  Created by admin on 2019/3/21.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

void fill_random_int(vector<int>&v,int cnt){
    v.clear();
    for(int i=0;i<cnt;i++){
        v.push_back(rand());
    }
}

void test_sort(vector<int>&v){
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++){
        assert(v[i]<v[i+1]);
    }
}
int main(int argc, const char * argv[]) {
    srand((unsigned)time(0));
    vector<int>v;
    fill_random_int(v,1000);
    test_sort(v);
    for(int i=0;i<v.size();i++){
        cout<<i<<" ";
    }
    cout<<endl;
    cout.unsetf(ios::fixed);
    cout<<fixed<<setprecision(2)<<(double)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
