//
//  main.cpp
//  橡皮筋技术——折线、矩形
//
//  Created by admin on 2020/3/5.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdlib.h>

#define NUM 100 //折线的最大折线段

int Flag = 0; //标记是否已经开始绘制折线
int RFlag = 0; //标记是否已经完成一个矩形
int Function = 1; //标记选择的功能是画折线还是矩形
int winWidth = 800, winHeight = 600; //窗口的宽度和高度
int Mousex, Mousey; //用于记录当前鼠标的位置
int n = 0; //用于记录折线有几段
int m = 0; //用于记录矩形个数
//线性结构体
struct LineNode {
    int x1;
    int y1;
    int x2;
    int y2;
}Line[NUM];
//矩形结构体
struct Rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
}Rect[NUM];

static GLsizei iMode = 1;


void Initial(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //设置窗口背景颜色
}

void ChangeSize(int w, int h)
{
    //保存当前窗口的大小
    winWidth = w;
    winHeight = h;
    glViewport(0, 0, w, h); //指定窗口显示区域
    glMatrixMode(GL_PROJECTION); //指定设置投影参数
    glLoadIdentity(); //调用单位矩阵，去掉以前的投影参数设置
    gluOrtho2D(0.0, winWidth, 0.0, winHeight); //设置投影参数
}

void ProcessMenu1(int value)
{
    Function = value; //接收选择
    
    n = 0;
    Flag = 0;
    m = 0;
    RFlag = 0;
    glutPostRedisplay();
}

void ProcessMenu2(int value)
{
    iMode = value;
    
    n = 0;
    Flag = 0;
    m = 0;
    RFlag = 0;
    glutPostRedisplay();
}

void Display()
{
    //默认画笔是红色，是线性模式，不填充
    int i, j;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //线性模式画图
    
    glClear(GL_COLOR_BUFFER_BIT); //用当前背景色填充窗口
    
    glColor3f(1.0f, 0.0f, 0.0f); //指定当前的绘图颜色
    
    switch(iMode)
    {
        case 3:
            glColor3f(1.0f, 0.0f, 0.0f); //红色
            break;
        case 4:
            glColor3f(0.0f, 1.0f, 0.0f); //绿色
            break;
        case 5:
            glColor3f(0.0f, 0.0f, 1.0f); //蓝色
            break;
        case 6:
            glColor3f(0.0f, 0.0f, 0.0f); //黑色
            break;
        case 7:
            glLineWidth(2); //像素增大
            break;
        case 8:
            glLineWidth(1); //像素减小
            break;
        case 9:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        case 10:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //线性模式画图
            break;
            
        case 11://退出
            exit(0);
            break;
            
        case 12://清屏
            glClear(GL_COLOR_BUFFER_BIT); //用当前背景色填充窗口
            break;
    }
    
    if (Function == 1) {
        for (i = 0; i < n; i++) {
            glBegin(GL_LINES); //绘制直线段
            glVertex2i(Line[i].x1, Line[i].y1);
            glVertex2i(Line[i].x2, Line[i].y2);
            glEnd();
        }
        //动态绘制鼠标动作
        if (Flag == 1) {
            glBegin(GL_LINES);
            glVertex2i(Line[i].x1, Line[i].y1);
            glVertex2i(Mousex, Mousey);
            glEnd();
        }
    }
    else {
        //绘制矩形
        for (j = 0; j < m; j++) {
            glRecti(Rect[j].x1, Rect[j].y1, Rect[j].x2, Rect[j].y2);
        }
        //动态绘制鼠标动作
        if (RFlag == 1) {
            glRecti(Rect[j].x1, Rect[j].y1, Mousex, Mousey);
        }
    }
    glutSwapBuffers(); //交换缓冲区
}

void MousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (Function == 1) {
        if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
            if (Flag == 0) {
                Flag = 1;
                Line[n].x1 = xMouse;
                Line[n].y1 = winHeight - yMouse;
            }
            else {
                Line[n].x2 = xMouse;
                Line[n].y2 = winHeight - yMouse;
                n++;
                //折线的第二点作为下一段线的第一个的点
                Line[n].x1 = Line[n-1].x2;
                Line[n].y1 = Line[n-1].y2;
            }
        }
    }
    else {
        //矩形处理
        if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
            if (RFlag == 0) {
                RFlag = 1;
                Rect[m].x1 = xMouse;
                Rect[m].y1 = winHeight - yMouse;
            }
            else {
                RFlag = 0;
                Rect[m].x2 = xMouse;
                Rect[m].y2 = winHeight - yMouse;
                m++;
                glutPostRedisplay();
            }
        }
    }
}

void PassiveMouseMove(GLint xMouse, GLint yMouse)
{
    Mousex = xMouse;
    Mousey = winHeight - yMouse;
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //使用双缓存及RGB模型
    glutInitWindowSize(400, 300); //指定窗口的尺寸
    glutInitWindowPosition(100, 100); //指定窗口在屏幕上的位置
    glutCreateWindow("橡皮筋技术");
    
    
    int nFunctionMenu=glutCreateMenu(ProcessMenu1);
    glutAddMenuEntry("画折线", 1);
    glutAddMenuEntry("画矩形", 2);
    
    int nColorMenu = glutCreateMenu(ProcessMenu2);
    glutAddMenuEntry("Red",3);               //创建右键颜色菜单
    glutAddMenuEntry("Green",4);
    glutAddMenuEntry("Blue",5);
    glutAddMenuEntry("Black",6);
    
    int nPixelMenu = glutCreateMenu(ProcessMenu2);  //创建右键像素菜单
    glutAddMenuEntry("increase pixel size",7);
    glutAddMenuEntry("decrease pixel size",8);
    
    int nFilleMenu = glutCreateMenu(ProcessMenu2);  //创建右键填充菜单
    glutAddMenuEntry("fill on",9);
    glutAddMenuEntry("fill off",10);
    
    int nMainMenu = glutCreateMenu(ProcessMenu2);
    glutAddSubMenu("功能",nFunctionMenu);
    glutAddSubMenu("颜色", nColorMenu);
    glutAddSubMenu("像素大小", nPixelMenu);
    glutAddSubMenu("填充", nFilleMenu);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);  //右键
    
    glutCreateMenu(ProcessMenu2);
    glutAddMenuEntry("退出", 11);
    glutAddMenuEntry("清屏", 12);
    
    glutAttachMenu(GLUT_MIDDLE_BUTTON);  //中间键
    
    glutDisplayFunc(Display);
    
    glutReshapeFunc(ChangeSize); //指定窗口再整形回调函数
    
    glutMouseFunc(MousePlot); //指定鼠标响应函数
    
    glutPassiveMotionFunc(PassiveMouseMove); //指定鼠标移动响应函数
    
    Initial();
    
    glutMainLoop(); //启动主GLUT事件处理循环
    
    return 0;
}
