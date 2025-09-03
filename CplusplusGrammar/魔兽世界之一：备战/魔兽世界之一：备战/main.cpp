//
//  main.cpp
//  魔兽世界之一：备战
//
//  Created by admin on 2019/9/9.
//  Copyright © 2019年 admin. All rights reserved.
//

/*
 红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
 蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int WarriorNum=5;//5种武士

class CHeadquarter;//司令部类
class CWarrior{//武士类
private:
    CHeadquarter *pHeadquarter;//哪个司令部的武士
    int nNo;//武士出场编号
    int nKindNo;//武士种类
public:
    static char * Names[WarriorNum];//武士名称
    static int InitialLifeValue[WarriorNum];//各武士初始生命值
    CWarrior(CHeadquarter *p,int nNo_,int nKindNo_);//武士类的构造函数
    void PrintResult(int nTime);//打印在nTime时刻武士降临的消息
};

class CHeadquarter{
private:
    bool bStopped;//司令部是否还能继续生成武士
    int nTotalLifeValue;//司令部一开始的生命元
    int nTotalWarriorNum;//司令部目前共生成武士数量
    int nColor;//司令部的种类
    int nCurMakingSeqIdx;//当前要制造的武士是制造序列中的第几个
    int aWarriorNum[WarriorNum];//存放每种武士的数量
    CWarrior *pWarriors[1000];//构造司令部的武士类
public:
    friend class CWarrior;//为了在CWarrior的PrintResult函数中使用CHeaquarter的aWarriorNum
    static int MakingSeq[2][WarriorNum];//武士制作顺序序列
    void Init(int nColor_,int lv);//初始化，nColor：司令部种类，lv：司令部生命元
    ~CHeadquarter();//析构函数
    void GetColor(char * szColor);//标明司令部的种类
    int Produce(int nTime);//司令部在nTime时刻生成武士
};
//CWarrior
CWarrior::CWarrior(CHeadquarter *p,int nNo_,int nKindNo_){//武士类的构造函数
    pHeadquarter=p;
    nNo=nNo_;
    nKindNo=nKindNo_;
}

void CWarrior::PrintResult(int nTime){//打印在nTime时刻武士降临的消息
    char szColor[20];
    pHeadquarter->GetColor(szColor);
    printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n" ,
           nTime, szColor, Names[nKindNo], nNo,
           InitialLifeValue[nKindNo],
           pHeadquarter->aWarriorNum[nKindNo],Names[nKindNo],szColor);
}

//CHeadquarter
void CHeadquarter::GetColor(char *szColor){//标明司令部的种类
    if(nColor==0){
        strcpy(szColor,"red");
    }else{
        strcpy(szColor,"blue");
    }
}

void CHeadquarter::Init(int nColor_, int lv){//初始化，nColor：司令部种类，lv：司令部生命元
    nColor=nColor_;
    nTotalLifeValue=lv;
    bStopped=false;
    nTotalWarriorNum=0;
    nCurMakingSeqIdx=0;
    for(int i=0;i<WarriorNum;i++){
        aWarriorNum[i]=0;
    }
}

CHeadquarter::~CHeadquarter(){//析构函数
    for(int i=0;i<nTotalWarriorNum;i++){
        delete pWarriors[i];
    }
}

int CHeadquarter::Produce(int nTime){//司令部在nTime时刻生成武士
    if( bStopped ) return 0;
    int nSearchingTimes = 0;
    while( CWarrior::InitialLifeValue[MakingSeq[nColor][nCurMakingSeqIdx]] > nTotalLifeValue &&
          nSearchingTimes < WarriorNum ) {
        nCurMakingSeqIdx = ( nCurMakingSeqIdx + 1 ) % WarriorNum ;
        nSearchingTimes ++;
    }
    int nKindNo = MakingSeq[nColor][nCurMakingSeqIdx];
    if( CWarrior::InitialLifeValue[nKindNo] > nTotalLifeValue ) {
        bStopped = true;
        if( nColor == 0)
            printf("%03d red headquarter stops making warriors\n",nTime);
        else
            printf("%03d blue headquarter stops making warriors\n",nTime);
        return 0;
    }
    nTotalLifeValue -= CWarrior::InitialLifeValue[nKindNo];
    nCurMakingSeqIdx = ( nCurMakingSeqIdx + 1 ) % WarriorNum ;
    pWarriors[nTotalWarriorNum] = new CWarrior( this,nTotalWarriorNum+1,nKindNo);
    aWarriorNum[nKindNo]++;
    pWarriors[nTotalWarriorNum]->PrintResult(nTime);
    nTotalWarriorNum ++;
    return 1;
}

char* CWarrior::Names[WarriorNum] = { "dragon","ninja","iceman","lion","wolf" };
int CWarrior::InitialLifeValue [WarriorNum];//声明静态成员函数
int CHeadquarter::MakingSeq[2][WarriorNum] = { { 2,3,4,1,0 },{3,0,1,2,4} };//两个司令部武士的制作序列

int main(int argc, const char * argv[]) {
    //printf("A\n");
    int t=0;//测试数据共t组
    int m=0;//司令部一开始生命元为m
    CHeadquarter RedHead,BlueHead;
    int case_num=1;
    scanf("%d",&t);
    while(t--){
        printf("Case:%d\n",case_num++);
        scanf("%d",&m);
        for(int i=0;i<WarriorNum;i++){
            scanf("%d",&CWarrior::InitialLifeValue[i]);
        }
        RedHead.Init(0,m);
        BlueHead.Init(1,m);
        int nTime=0;
        while(true){
            int tmp1=RedHead.Produce(nTime);
            int tmp2=BlueHead.Produce(nTime);
            if(tmp1==0&&tmp2==0)break;
            nTime++;
        }
    }
    return 0;
}
