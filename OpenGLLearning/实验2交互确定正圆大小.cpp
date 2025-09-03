//
//  main.cpp
//  交互确定正圆大小
//
//  Created by admin on 2020/4/11.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#define y1 Y1
using namespace std;
int iPointNum=0;//已确定点的数目
int x1=0,x2=0,y1=0,y2=0;
int winWidth=400,winHeight=300;
int iMod=1;//1表示画直线，2表示画矩形，3表示画椭圆

void init(){//初始化窗口背景颜色为白色
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void putPixel(int x,int y){
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();//强制刷新缓冲
}

void drawEllipse(int x0,int y0,int x,int y){//(x0,y0):椭圆中心,(x,y):椭圆上的点
    putPixel(x0+x,y0+y);
    putPixel(x0-x,y0+y);             //画对称点
    putPixel(x0+x,y0-y);
    putPixel(x0-x,y0-y);
}

void MidBresenhamEllipse(int x0,int y0,int a,int b){//椭圆中心,长半轴,短半轴
    int x,y;
    float d1,d2;
    x=0;y=b;
    d1=b*b+a*a*(-b+0.25);
    drawEllipse(x0,y0,x,y);
    while(b*b*(x+1)<a*a*(y-0.5)){
        if(d1<=0){
            d1+=b*b*(2*x+3);
            x++;
        }else{
            d1+=b*b*(2*x+3)+a*a*(-2*y+2);
            x++;y--;
        }
        drawEllipse(x0,y0,x,y);
    }
    d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y>0){
        if(d2<=0){
            d2+=b*b*(2*x+2)+a*a*(-2*y+3);
            x++;y--;
        }else{
            d2+=a*a*(-2*y+3);
            y--;
        }
        drawEllipse(x0,y0,x,y);
    }
}

void drawCircle(int x0,int y0,int x,int y){//(x0,y0):圆心,(x,y):圆上的点
    putPixel(x0+x,y0+y);putPixel(y0+y,x0+x);
    putPixel(x0-x,y0+y);putPixel(y0+y,x0-x);
    putPixel(x0+x,y0-y);putPixel(y0-y,x0+x);
    putPixel(x0-x,y0-y);putPixel(y0-y,x0-x);
}

void MidBresenhamCircle(int x0,int y0,int r){//圆心,b半径
    int x,y,d;
    x=0;y=r;d=1-r;
    while(x<=y){
        drawCircle(x0,y0,x,y);
        if(d<0){
            d+=2*x+3;
        }else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}
void ChangeSize(int w,int h){//窗体大小改变消息的回调函数
    if(iMod==1||iMod==2){
        winWidth=w;//保存当前窗口大小
        winHeight=h;
        glViewport(0,0,w,h);//指定窗口显示区域
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, winWidth, 0.0, winHeight);
    }else if(iMod==3){
        if(h==0)h=1;
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if (w <= h){
            glOrtho(0.0f,  250.0f,  0.0f,  250.0f*h/w,  1.0,  -1.0);
        }else{
            glOrtho(0.0f,  250.0f*w/h,  0.0f,  250.0f,  1.0,  -1.0);
        }
    }
}

void ProcessMenu(int value){//菜单回调函数
    iMod=value;//保留用户选择的菜单ID
    glutPostRedisplay();//程序发出窗口重绘信息
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
    if(iMod==1){//画直线
        if(iPointNum>=1){
            glBegin(GL_LINES);
            glVertex2i(x1,y1);
            glVertex2i(x2,y2);
            glEnd();
        }
    }else if(iMod==2){//画矩形
        glRecti(x1,y1,x2,y2);
    }else if(iMod==3){//画椭圆
        MidBresenhamEllipse(200,200,(y1-y2),(x2-x1));
    }else if(iMod==4){//画正圆
        MidBresenhamCircle( 200,200,0.5*sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)) );
    }
    glutSwapBuffers();
}

void MousePlot(GLint button,GLint action,GLint xMouse,GLint yMouse){
    if(button==GLUT_LEFT_BUTTON&&action==GLUT_DOWN){
        if(iPointNum==0||iPointNum==2){
            iPointNum=1;
            x1=xMouse;y1=winHeight-yMouse;
        }else{
            iPointNum=2;
            x2=xMouse;y2=winHeight-yMouse;
            glutPostRedisplay();
        }
    }
    if(button==GLUT_RIGHT_BUTTON&&action==GLUT_DOWN){
        iPointNum=0;
        glutPostRedisplay();
    }
}

void Key(unsigned char key,int xMouse,int yMouse){
    switch(key){
        case 'p':
            if(iPointNum==0||iPointNum==2){
                iPointNum=1;
                x1=xMouse;y1=winHeight-yMouse;
                int mod=glutGetModifiers();
                //cout<<(mod==GLUT_ACTIVE_CTRL)<<endl;
                if(mod==GLUT_ACTIVE_CTRL&&iMod==4){
                    MidBresenhamCircle( 200,200,0.5*sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)) );
                }
            }else{
                iPointNum=2;
                x2=xMouse;y2=winHeight-yMouse;
                
                glutPostRedisplay();
            }
            
            break;
        case 'c':
            iPointNum=0;
            glutPostRedisplay();
            break;
        default:break;
    }
}

void SpecialKeys(int key,int x,int y){
    int mod=glutGetModifiers();
    if(mod==GLUT_ACTIVE_SHIFT){
        MidBresenhamCircle( 200,200,0.5*sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)) );
    }
}

void PassiveMouse(GLint xMouse,GLint yMouse){
    if(iPointNum==1){
        x2=xMouse;
        y2=winHeight-yMouse;
        glutPostRedisplay();
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //使用双缓存及RGB模型
    glutInitWindowSize(400, 400); //指定窗口的尺寸
    glutInitWindowPosition(400, 400); //指定窗口在屏幕上的位置
    glutCreateWindow("橡皮筋技术");
    
    int nMainMenu = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("直线", 1);
    glutAddMenuEntry("矩形", 2);
    glutAddMenuEntry("椭圆", 3);
    glutAddMenuEntry("正圆", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);  //右键
    
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize); //指定窗口再整形回调函数
    glutMouseFunc(MousePlot); //指定鼠标响应函数
    glutKeyboardFunc(Key);
    glutSpecialFunc(SpecialKeys);
    glutPassiveMotionFunc(PassiveMouse); //指定鼠标移动响应函数
    
    init();
    glutMainLoop();
    return 0;
}
