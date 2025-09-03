//
//  main.cpp
//  Liang-Barsky_直线裁剪
//
//  Created by admin on 2020/5/15.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int iPointNum=0;//键盘'p'确定直线段端点的数目：0-无、1-起始点、2-终止点
int iMouseNum= 0;    //鼠标单击确定裁剪窗口点的数目：0-无、1-起始点、2-终止点
int x1=0,x2=0,y1=0,y2=0;
int xKey1=0,yKey1=0;                     //直线段橡皮筋时，保留鼠标移动时的坐标值
int xKey2=0,yKey2=0;
int xMouse=0,yMouse=0;                //裁剪窗口橡皮筋时，保留鼠标移动时的坐标值

int winWidth=400,winHeight=400;
int iMod=1;//1表示画直线，2表示画矩形
typedef struct Rectangle{
    float w_xmin,w_ymin;
    float w_xmax,w_yman;
    Rectangle(float xmin = 0.0, float ymin = 0.0,float xmax=0.0,float yman=0.0){
        w_xmin = xmin;w_ymin = ymin;
        w_xmax = xmax;w_yman = yman;
    }
}rect;
rect winObj;    //存放标准矩形裁剪窗口的四条边

int Clip_Top(float p,float q,float&umax,float&umin){
    float r=0.0;
    if(p<0.0){
        r=q/p;
        if(r>umin)return 0;
        else if(r>umax)umax=r;
    }else if(p>0.0){
        r=q/p;
        if(r<umax)return 0;
        else if(r<umin)umin=r;
    }else{
        if(q<0.0)return 0;
    }
    return 1;
}

void Line_Clipping(float x1,float y1,float x2,float y2,rect *pRect){
    float dx=x2-x1,dy=y2-y1;
    float umax=0.0,umin=1.0;
    if(pRect->w_xmin>pRect->w_xmax)swap(pRect->w_xmin,pRect->w_xmax);
    if(pRect->w_ymin>pRect->w_yman)swap(pRect->w_ymin,pRect->w_yman);
    if(Clip_Top(-dx, x1-pRect->w_xmin, umax, umin)){
        if(Clip_Top(dx,pRect->w_xmax-x1,umax, umin)){
            if(Clip_Top(-dy, y1-pRect->w_ymin, umax, umin)){
                if(Clip_Top(dy,pRect->w_yman-y1, umax, umin)){
                    glLineWidth(3);
                    glBegin(GL_LINES);
                    glColor3f(1.0f,1.0f,0.0f);//黄色
                    glVertex2i((int)(x1+umax*dx),(int)(y1+umax*dy));
                    glVertex2i((int)(x1+umin*dx),(int)(y1+umin*dy));
                    glEnd();
                    glFlush();
                }
            }
        }
    }
}

void init(){//初始化窗口背景颜色为白色
    iPointNum=0;
    iMouseNum=0;
    x1=0;x2=0;y1=0;y2=0;
    xKey1=0;yKey1=0;                     
    xKey2=0;yKey2=0;
    xMouse=0;yMouse=0;
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void ChangeSize(int w,int h){//窗体大小改变消息的回调函数
    winWidth=w;//保存当前窗口大小
    winHeight=h;
    glViewport(0,0,w,h);//指定窗口显示区域
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.98f, 0.625f, 0.12f);
    glRecti(x1,y1,x2,y2);
    winObj={(float)x1,(float)y1,(float)x2,(float)y2};
    glFlush();
}

void MousePlot(GLint button,GLint action,GLint xMouse,GLint yMouse){
    if(button==GLUT_LEFT_BUTTON&&action==GLUT_DOWN){
        if(iMouseNum==0||iMouseNum==2){
            iMouseNum=1;
            x1=xMouse;y1=winHeight-yMouse;
        }else{
            iMouseNum=2;
            x2=xMouse;y2=winHeight-yMouse;
            winObj={(float)x1,(float)y1,(float)x2,(float)y2};
            glutPostRedisplay();
        }
    }
    if(button==GLUT_RIGHT_BUTTON&&action==GLUT_DOWN){
        iMouseNum=0;
        glutPostRedisplay();
    }
}

void Key(unsigned char key,int xMouse,int yMouse){
    if(key=='p'){
        if(iPointNum==0||iPointNum==2){
            iPointNum=1;
            glColor3f(1,0,0);
            glBegin(GL_POINTS);
            glVertex2f(xMouse,winHeight-yMouse);
            xKey1 = xMouse;yKey1 = yMouse;//
            glEnd();
            glFlush();
        }else{
            iPointNum=2;
            glColor3f(1,0,0);
            glBegin(GL_POINTS);
            glVertex2f(xMouse,winHeight-yMouse);
            glEnd();
            xKey2 = xMouse;yKey2 = yMouse;//
            glBegin(GL_LINES);
            glColor3f(1.0,0.0,0.0);
            glVertex2f(xKey1,winHeight-yKey1);
            glVertex2f(xKey2,winHeight-yKey2);
            glEnd();
            glFlush();
            Line_Clipping(xKey1, winHeight-yKey1, xKey2, winHeight-yKey2,&winObj);
        }
    }
}

void PassiveMouse(GLint xMouse,GLint yMouse){
    if(iMouseNum==1){
        x2=xMouse;
        y2=winHeight-yMouse;
        glutPostRedisplay();
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //使用单缓存及RGB模型
    glutInitWindowSize(400, 400); //指定窗口的尺寸
    glutInitWindowPosition(200, 200); //指定窗口在屏幕上的位置
    glutCreateWindow("Liang-Barsky_直线裁剪");
    

    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize); //指定窗口再整形回调函数
    glutMouseFunc(MousePlot); //指定鼠标响应函数
    glutKeyboardFunc(Key);
    glutPassiveMotionFunc(PassiveMouse); //指定鼠标移动响应函数
    
    init();
    glutMainLoop();
    return 0;
}
