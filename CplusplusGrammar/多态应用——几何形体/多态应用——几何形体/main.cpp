//
//  main.cpp
//  多态应用——几何形体
//
//  Created by admin on 2019/10/2.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double pai=3.14159265;
const int N=1000;

class CShape{
public:
    virtual double Area()=0;
    virtual void PrintInf()=0;
    virtual ~CShape();
};//基类

class CCircle:public CShape{
public:
    double r;
    virtual double Area();
    virtual void PrintInf();
};

class CRectangle:public CShape{
public:
    double h,w;
    virtual double Area();
    virtual void PrintInf();
};

class CTriangle:public CShape{
public:
    double a,b,c;
    virtual double Area();
    virtual void PrintInf();
};

double CCircle::Area(){
    return pai*r*1.0*r;
}
double CRectangle::Area(){
    return h*1.0*w;
}
double CTriangle::Area(){
    double p=(a+b+c)*1.0/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void CCircle::PrintInf(){
    cout<<"Circle:"<<Area()<<endl;
}
void CRectangle::PrintInf(){
    cout<<"Rectangle:"<<Area()<<endl;
}
void CTriangle::PrintInf(){
    cout<<"Triangle:"<<Area()<<endl;
}

int Compare(const void *s1,const void *s2);
CShape *pShapes[N];

int main(int argc, const char * argv[]) {
    cout<<"A"<<endl;
    CCircle * pc;
    CRectangle *pr;
    CTriangle *pt;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        switch(c){
            case 'C':
                pc=new CCircle;
                cin>>pc->r;
                pShapes[i]=pc;
                break;
            case 'R':
                pr=new CRectangle;
                cin>>pr->h>>pr->w;
                pShapes[i]=pr;
                break;
            case 'T':
                pt=new CTriangle;
                cin>>pt->a>>pt->b>>pt->c;
                pShapes[i]=pt;
                break;
        }
    }
    qsort(pShapes,n,sizeof(CShape*),Compare);
    for(int i=0;i<n;i++){
        pShapes[i]->PrintInf();
    }
    return 0;
}
int Compare(const void *s1,const void *s2){
    double a1,a2;
    CShape ** p1;
    CShape ** p2;
    p1=(CShape **)s1;
    p2=(CShape **)s2;
    a1=(*p1)->Area();
    a2=(*p2)->Area();
    if(a1<a2){
        return -1;
    }else if(a1==a2){
        return 0;
    }
    return 1;
}
