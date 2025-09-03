//
//  main.cpp
//  实验1  橡皮筋技术的实现（指针_折线）
//
//  Created by admin on 2020/3/12.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdlib.h>

int iPointNum=0;
int x=0,y=0;//当前鼠标位置
int winWidth=400,winHeight=300;
struct Point{
    GLint x;
    GLint y;
    Point(GLint x=0,GLint y=0):x(x),y(y){};
};
struct Node{
    struct Point point;
    struct Node *next;
};
struct Node *head;

void add(GLint x,GLint y){
    struct Node *n=new(struct Node);
    (n->point).x=x;
    (n->point).y=y;
    n->next=head->next;
    head->next=n;
}

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
    
    struct Node *p=head->next;
    while(p!=NULL){
        Point j=p->point;
        int x1=j.x,y1=j.y;
        if(p->next==NULL)break;
        int x2=p->next->point.x,y2=p->next->point.y;
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glEnd();
        p=p->next;
    }
    struct Node *k=head;
    if(k->next!=NULL){
        Point j=k->next->point;
        int x1=j.x,y1=j.y;
        if(iPointNum!=0){
            glBegin(GL_LINES);
            glVertex2i(x1,y1);
            glVertex2i(x,y);
            glEnd();
        }
    }
    glutSwapBuffers();
}

void MousePlot(GLint button,GLint action,GLint xMouse,GLint yMouse){
    if(button==GLUT_LEFT_BUTTON&&action==GLUT_DOWN){
        if(iPointNum==0){
            iPointNum=1;
            add(xMouse,winHeight-yMouse);
        }else{
            add(xMouse,winHeight-yMouse);
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
                add(xMouse,winHeight-yMouse);
            }else{
                add(xMouse,winHeight-yMouse);
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
    head=new(struct Node);
    head->next=NULL;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //使用双缓存及RGB模型
    glutInitWindowSize(400, 300); //指定窗口的尺寸
    glutInitWindowPosition(100, 100); //指定窗口在屏幕上的位置
    glutCreateWindow("橡皮筋技术");
    
    
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize); //指定窗口再整形回调函数
    //glutMouseFunc(MousePlot); //指定鼠标响应函数
    glutKeyboardFunc(Key);
    glutPassiveMotionFunc(PassiveMouse); //指定鼠标移动响应函数
    
    init();
    glutMainLoop();
    return 0;
}
