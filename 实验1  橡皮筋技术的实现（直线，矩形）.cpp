//
//  main.cpp
//  实验1  橡皮筋技术的实现（直线，矩形）
//
//  Created by admin on 2020/3/5.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdlib.h>


int iPointNum=0;//已确定点的数目
int x1=0,x2=0,y1=0,y2=0;
int winWidth=400,winHeight=300;
int iMod=1;//1表示画直线，2表示画矩形

void init(){//初始化窗口背景颜色为白色
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
    }else{//画矩形
        glRecti(x1,y1,x2,y2);
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
    glutInitWindowSize(400, 300); //指定窗口的尺寸
    glutInitWindowPosition(100, 100); //指定窗口在屏幕上的位置
    glutCreateWindow("橡皮筋技术");
    
    int nMainMenu = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("直线", 1);
    glutAddMenuEntry("矩形", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);  //右键
    
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize); //指定窗口再整形回调函数
    //glutMouseFunc(MousePlot); //指定鼠标响应函数
    glutKeyboardFunc(Key);
    glutPassiveMotionFunc(PassiveMouse); //指定鼠标移动响应函数
    
    init();
    glutMainLoop();
    return 0;
}
