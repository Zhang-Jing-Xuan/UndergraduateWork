#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string file_address="C:\\Users\\zjx61\\Desktop\\1.txt";
    ifstream fin;
    fin.open(file_address);
    string s;
    while(getline(fin,s)){
        stringstream ss(s);
        string res;
        int i=0;
        while(ss>>res){
             if(i==1){
                int ca=stoi(res);
                printf("case %d:\n",ca);
             }
             if(i==3){
                cout<<"\t"<<"printf(\""<<res<<"\\n\");"<<endl;
                cout<<"\tbreak;"<<endl;
             }
             i++;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}