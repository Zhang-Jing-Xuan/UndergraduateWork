//
//  main.cpp
//  固定矩形
//
//  Created by admin on 2020/5/15.
//  Copyright © 2020年 admin. All rights reserved.
//
#include <GLUT/GLUT.h>
#include <iostream>
using namespace std;
int x1,y1,x2,y2;                     //描述构成直线的两个端点
int wmin = 100 ,wmax = 300;//描述裁剪区间的大小
int hmin = 250 ,hmax = 350; //这里为了简化采用的是硬编码
int flag = 1;                         //用于记录用户点击的次数，单次画点，双次画线。
int window_size=600;           //这是我们显示界面的大小
int cut_judge(float p,float q, float&u1, float &u2);
void LYD_Barsky(float x1,float y1, float x2,float y2,float ytop,float ybuttom,float xleft,float xright){
    /*
     函数说明：仅需要除法、不需要浮点运算。实现对区域内
     的直线进行剪裁的操作。这里用到直线的参数方程。
     *其中我们正负dx dy就是p类参数
     *而x1 - wmin，wmax-x1....代表q类参数
     */
    float  u1 = 0.0,u2 = 1.0;
    float dx = x2 - x1,dy =  y2 - y1;
    if (cut_judge(-dx, x1 - xleft, u1,u2)) {
        if (cut_judge(dx,xright-x1 ,u1,u2)) {
            if (cut_judge(-dy, y1 - ybuttom, u1, u2)) {
                if (cut_judge(dy, ytop - y1, u1, u2)) {
                    if (u2< 1.0) {
                        x2 = x1 + u2*dx;
                        y2 = y1+  u2*dy;
                    }
                    if (u1>0.0) {
                        x1 = x1 + u1*dx;
                        y1 = y1+ u1*dy;
                    }
                    glBegin(GL_LINES);
                    glColor3f(0.0,1.0,0.0);
                    glVertex2f(x1, 400-y1+200);
                    glVertex2f(x2, 400-y2+200);
                    glEnd();
                    glFlush();
                }
            }
        }
    }
}

int cut_judge(float p,float q, float&u1, float &u2){
    /*
     函数说明：对p，q进行判断同时根据判断刷新u1 u2
     注意u1 u2是传值进入
     */
    float u;
    int res  =1;
    if (p > 0.0) {
        u = q/p;
        if (u < u1){
            res = 0;
        }
        else if(u<u2){
            u2 = u;
        }
    }
    else if(p < 0.0){
        u = q/p;
        if (u > u2){
            res =0;
        }
        else if (u >u1){
            u1 = u;
        }
    }
    else{
        if (q<0.0)
        {
            res = 0;
        }
    }
    return res;
}

void InitEnvironment()
{
    glClearColor(0.0,0.0,0.0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(7);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0,window_size,0,window_size);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // 首先绘制裁剪区域
    glColor3f(0.98f, 0.625f, 0.12f);
    //绘制矩形，第一对坐标表示左上角，第二对表示右下角
    glRectf(wmin, hmax, wmax , hmin);
    //刷新队列
    //在内部，openGL的命令和语句常常等待在队列里
    //直到openGL驱动程序同时处理几个“命令”
    glFlush();
    glFlush();
}

void OnMouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
        //点击左键
    {
        if (flag%2) {
            glColor3f(1,0,0);
            glBegin(GL_POINTS);
            glVertex2f(x,window_size-y);
            x1 = x;y1 = y;
            glEnd();
            glFlush();
        }else{
            glColor3f(1,0,0);
            glBegin(GL_POINTS);
            glVertex2f(x,window_size-y);
            glEnd();
            x2 = x;y2 = y;
            glBegin(GL_LINES);
            glColor3f(1.0,0.0,0.0);
            glVertex2f(x1,window_size-y1);
            glVertex2f(x2,window_size-y2);
            glEnd();
            glFlush();
            LYD_Barsky(x1, y1, x2, y2, hmax, hmin, wmin,wmax);
        }
        flag++;
    }
}

int main(int argc, char *argv[])
{
    cout << "begin"<<endl;
    glutInit(&argc, argv);   //初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(window_size, window_size);
    glutCreateWindow("hw1_cut_line");
    InitEnvironment();   //初始化
    glutMouseFunc(&OnMouse);  //注册鼠标事件
    glutDisplayFunc(&myDisplay);   //回调函数
    glutMainLoop();    //持续显示，当窗口改变会重新绘制图形
    return 0;
}
