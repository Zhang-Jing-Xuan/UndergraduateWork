//
//  main.cpp
//  实验1  橡皮筋技术的实现（折线）
//
//  Created by admin on 2020/3/5.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdlib.h>

const int N=10000;
int iPointNum=0;
int x=0,y=0;//当前鼠标位置
int winWidth=400,winHeight=300;
struct Point{
    GLint x;
    GLint y;
};
Point e[N];
int ne[N],head,idx;

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


void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
    int k=head;
    for(int i=head;i!=-1;i=ne[i]){
        Point j=e[i];
        int x1=j.x,y1=j.y;
        if(ne[i]==-1)break;
        int x2=e[ne[i]].x,y2=e[ne[i]].y;
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glEnd();
    }
    Point j=e[k];
    int x1=j.x,y1=j.y;
    if(iPointNum!=0){
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x,y);
        glEnd();
    }
    glutSwapBuffers();
}

void MousePlot(GLint button,GLint action,GLint xMouse,GLint yMouse){
    if(button==GLUT_LEFT_BUTTON&&action==GLUT_DOWN){
        if(iPointNum==0){
            iPointNum=1;
            e[idx].x=xMouse;e[idx].y=winHeight-yMouse;
            ne[idx]=head;
            head=idx++;
        }else{
            e[idx].x=xMouse;e[idx].y=winHeight-yMouse;
            ne[idx]=head;
            head=idx++;
            glutPostRedisplay();
        }
    }
    if(button==GLUT_RIGHT_BUTTON&&action==GLUT_DOWN){
        //iPointNum=0;
        glutPostRedisplay();
    }
}

void Key(unsigned char key,int xMouse,int yMouse){
    switch(key){
        case 'p':
            if(iPointNum==0){
                iPointNum=1;
                e[idx].x=xMouse;e[idx].y=winHeight-yMouse;
                ne[idx]=head;
                head=idx++;
            }else{
                e[idx].x=xMouse;e[idx].y=winHeight-yMouse;
                ne[idx]=head;
                head=idx++;
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
        x=xMouse;
        y=winHeight-yMouse;
        glutPostRedisplay();
}

int main(int argc, char * argv[]) {
    head=-1;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //使用双缓存及RGB模型
    glutInitWindowSize(400, 300); //指定窗口的尺寸
    glutInitWindowPosition(100, 100); //指定窗口在屏幕上的位置
    glutCreateWindow("橡皮筋技术");
    
    
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize); //指定窗口再整形回调函数
    glutMouseFunc(MousePlot); //指定鼠标响应函数
    //glutKeyboardFunc(Key);
    glutPassiveMotionFunc(PassiveMouse); //指定鼠标移动响应函数
    
    init();
    glutMainLoop();
    return 0;
}
