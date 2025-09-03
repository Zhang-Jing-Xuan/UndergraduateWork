//
//  main.cpp
//  word_analyse
//
//  Created by admin on 2021/1/9.
//  Copyright © 2021年 admin. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

int aa;// fseek的时候用来接着的
string  word="";
string  reserved_word[70];//保留字
char buffer;//每次读进来的一个字符
int num=0;//每个单词中当前字符的位置
int line_=1; //行数
int row=1; //列数，就是每行的第几个
bool flag; //文件是否结束了
int flag2;//单词的类型
int reservedn=0;// 保留字个数

//设置保留字
int set_reserve()
{
    ifstream fin;
    fin.open("baoliuzi.txt");
    int i=0;
    while(!fin.eof()){//这是注释
        getline(fin,reserved_word[i]);/*注释*/
        i++;
    }
    fin.close();
    return i-1;
}

//看这个字是不是字母
bool judge_word(char x)
{
    if((x>='a' && x<='z') || (x>='A' && x<='Z') ){
        return true;
    }
    else return false;
}

//看这个字是不是数字
bool judge_number(char x)
{
    if(x>='0' && x<='9'){
        return true;
    }
    else return false;
}

//看这个字符是不是界符
bool judge_jiefu(char x)
{
    if(x=='('||x==')'||x==','||x==';'||x=='{'||x=='}'||x=='['||x==']'
       ||x=='\''||x=='\"'||x=='.' ){
        return true;
    }
    else return false;
}


//+ - * !
bool judge_yunsuanfu1(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='!')
    {
        return true;
    }
    else return false;
}

//等于 赋值，大于小于 大于等于，小于等于，大于小于
bool judge_yunsuanfu2(char x)
{
    if(x=='='|| x=='>'||x=='<'){
        return true;
    }
    else return false;
}

// || &&
bool judge_yunsuanfu3(char x)
{
    if(x=='|'|| x=='&'){
        return true;
    }
    else return false;
}



//这个最大的函数的总体作用是从文件里读一个单词
int scan(FILE *fp)//一个指向文件的指针
{
    buffer=fgetc(fp);//从文件指针fp指向的文件中读取一个字符并返回,指针自动后移
    if(feof(fp)){      //文件结束：返回非0值；文件未结束：返回0值
        flag=0;return 0;
    }
    //用line_和row给词语定位
    else if(buffer==' '||buffer=='\t')//有的人喜欢用tab
    {
        row++;
        return 0;
    }
    else if(buffer=='\n'||buffer=='\r')
    {
        line_++;
        row=1;
        return 0;
    }
    
    //如果是字母开头或'_' 看关键字还是普通单词
    else if(judge_word(buffer) || buffer=='_')
    {
        word+=buffer;row++;//字符串加上ascll码值相当于字符串拼接
        while((buffer=fgetc(fp)) && (judge_word(buffer) || judge_number(buffer) || buffer=='_'))
        {
            word+=buffer;row++;
        }//读完了一个单词
        if(feof(fp)){
            flag=0;return 1;
        }
        //这个函数的意义是 因为保留字不区分大小写 要把大写字母全变成小写再比较
        string temp=word;
        for(int j=0;j<temp.length();j++)
        {
            if(temp[j]>='A' && temp[j]<='Z')
            {
                temp[j]+=32;
            }
        }
        
        for(int i=0;i<reservedn;i++){//扩展保留字
            if(temp==reserved_word[i]){  //由于取到空串后指针再往后移，所以回退一字节
                aa=fseek(fp,-1,SEEK_CUR);//将指针从当前位置后退一字节(一个字符)，成功返回0
                //cout<<fgetc(fp)<<endl;
                return 3;
            }
        }
        aa=fseek(fp,-1,SEEK_CUR);//如果之前return，此句不执行
        return 1;
    }
    
    //开始是加减乘 一定是类型4
    else if(judge_yunsuanfu1(buffer))
    {
        //接收到+ - * !后
        word+=buffer;row++;
        word+=fgetc(fp);row++;//再接收一个看是不是等于号
        if(word=="+="||word=="*="||word=="-="||word=="!="||word=="--"||word=="++"){
            return 4;
        }
        else{  //如果不是等于号，至少它还是个运算符，记得指针回退一下
            aa=fseek(fp,-1,SEEK_CUR);
            row--;
            return 4;
        }
    }
    
    // 判断 && ||
    else if(judge_yunsuanfu3(buffer))
    {
        //接收到 & |后
        word+=buffer;row++;
        word+=fgetc(fp);row++;//再接收一个看
        if(word=="||"||word=="&&"){
            return 4;
        }
        else{  //如果不是
            aa=fseek(fp,-1,SEEK_CUR);
            row--;
            return 4;
        }
    }
    
    
    
    //开始是数字就一定是数字
    else if(judge_number(buffer))
    {
        word+=buffer;row++;
        while((buffer=fgetc(fp)) && judge_number(buffer))
        {
            word+=buffer;row++;
        }
        if(feof(fp)){
            flag=0;return 2;
        }
        aa=fseek(fp,-1,SEEK_CUR);
        return 2;
    }
    
    //检验界符
    else if(judge_jiefu(buffer))
    {
        word+=buffer;row++;
        return 6;
    }
    
    //检验 <=、  >=、  <>、  == =、 <、>
    else if(judge_yunsuanfu2(buffer))
    {
        row++;
        word+=buffer;
        if(buffer=='<')   //为了检验<> <=
        {
            buffer=fgetc(fp);
            if(buffer=='>' || buffer=='=')
            {
                word+=buffer;
                row++;
                return 5;
            }
        }
        //检验  >= ==
        else{
            buffer=fgetc(fp);
            if(buffer=='=')
            {
                word+=buffer;
                row++;
                return 5;
            }
        }
        if(feof(fp)){
            flag=0;
        }
        //如果再接收一个字符并不是> = <，说明是单运算符返回4，指针要回退
        aa=fseek(fp,-1,SEEK_CUR);
        return 4;
    }
    
    //首字符是/ 有可能是除号 也有可能是注释
    else if(buffer=='/')
    {
        row++;word+=buffer;
        buffer=fgetc(fp);
        //这种情况是除号
        if(buffer!='*' && buffer !='/')
        {
            aa=fseek(fp,-1,SEEK_CUR);
            return 4;
        }
        // 这一行剩下的全被注释了
        if(buffer=='/')
        {
            word.clear();
            while((buffer=fgetc(fp)) && buffer!='\n' &&!feof(fp))
            {
                //真的什么也没有做，指针自动往后移动
            }
            if(feof(fp)){
                flag=0;return 0;
            }
            else{
                aa=fseek(fp,-1,SEEK_CUR);
            }
            line_++;row=1;
            return 0;
        }
        if(buffer=='*')
        {
            bool flag5=1;
            while(flag5)
            {
                word.clear();
                buffer=fgetc(fp);
                row++;
                if(buffer=='\n'){line_++;row=1;}
                if(buffer!='*')continue;
                else {//接收到*
                    buffer=fgetc(fp);
                    row++;if(buffer=='\n'){line_++;row=1;}
                    if(buffer=='/'){//接收到*/
                        flag5=0;
                    }
                    else continue;
                }
                if(feof(fp)){flag=0;return 0;}
            }
            
        }
        
    }
    
    else {
        word+=buffer;
        row++;
        return -1;
    }
    return 0;
}

int main()
{
    reservedn = set_reserve();//设置保留字
    //cout<<"open "<<"code.txt"<<endl;
    
    //cout<<"_____________________"<<endl<<endl;
    
    flag=1;
    
    FILE *fp;
    if(!(fp=fopen("code.txt","r")))
    {
        cout<<"not found the file or other error "<<endl;
        flag=0;
    }
    
    while(flag==1)
    {
        //flag2 返回的类型
        flag2=scan(fp);//反复调用函数提取单词
        
        if(flag2==1)
        {
            cout<<"( 2 ,"<<" \" "<<word<<" \"  )"<<endl;
            if(word.length()>20)
                cout<<"ERROR Identifier length cannot exceed 20 characters"<<endl;
            word.clear();
        }
        else if(flag2==3)
        {
            cout<<"( 1 ,"<<" \" "<<word<<" \"  )"<<endl;
            word.clear();
        }
        else if(flag2==4)
        {
            cout<<"( 4 ,"<<" \" "<<word<<" \"  )"<<endl;
            word.clear();
        }
        else if(flag2==2)
        {
            cout<<"( 3 ,"<<" \" "<<word<<" \"  )"<<endl;
            if(word[0]=='0' && word[1])
                cout<<"ERROR: The first digit cannot be 0!"<<endl;
            word.clear();
        }
        else if(flag2==6)
        {
            cout<<"( 5 ,"<<" \" "<<word<<" \"  )"<<endl;
            word.clear();
        }
        else if(flag2==5)
        {
            cout<<"( 4 ,"<<" \" "<<word<<" \"  )"<<endl;
            word.clear();
        }
        //非法字符
        else if(flag2==-1)
        {
            cout<<"Illegal character      "<<"line "<<line_<<" row "<<row-1<<"  "<<word<<endl;
            word.clear();
        }
    }
    
    int a=fclose(fp);
    //cout<<"_____________________"<<endl;
    
//    system("pause");
    
    return 0;
}

