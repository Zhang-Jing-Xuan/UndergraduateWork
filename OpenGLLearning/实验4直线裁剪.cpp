//
//  main.cpp
//  直线裁剪
//
//  Created by admin on 2020/5/22.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int iPointNum=0;//键盘'p'确定直线段端点的数目：0-无、1-起始点、2-终止点
int iMouseNum= 0;    //鼠标单击确定裁剪窗口点的数目：0-无、1-起始点、2-终止点
int x1=0,x2=0,y1=0,y2=0;
int xKey=0,yKey=0;                     //直线段橡皮筋时，保留鼠标移动时的坐标值
int xMouse=0,yMouse=0;                //裁剪窗口橡皮筋时，保留鼠标移动时的坐标值
int winWidth=400,winHeight=300;
static int iMod=1;//1表示画直线，2表示画矩形
typedef struct Point{
    int x,y;
    Point(int a=0,int b=0){
        x=a;y=b;
    }
}point;
typedef struct Rectangle{
    float w_xmin,w_ymin;
    float w_xmax,w_yman;
    Rectangle(float xmin = 0.0, float ymin = 0.0,float xmax=0.0,float yman=0.0){
        w_xmin = xmin;w_ymin = ymin;
        w_xmax = xmax;w_yman = yman;
    }
}rect;
rect winObj;    //存放标准矩形裁剪窗口的四条边
vector<point>pointVertex;
vector<point>pointRect;

void init(){//初始化窗口背景颜色为白色
    iPointNum=0;
    iMouseNum=0;
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glLineStipple(1, 0x00FF);
    glDisable(GL_LINE_STIPPLE);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    pointVertex.clear();
    pointRect.clear();
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

void getRect(vector<point>&points,rect& winRect){
    if(points.size()<2){
        cout<<"点数不足"<<endl;
    }else{
        winRect.w_xmin=points[0].x;
        winRect.w_ymin=points[0].y;
        winRect.w_xmax=points[1].x;
        winRect.w_yman=points[1].y;
    }
}

void swap(rect& winRect){
    if(winRect.w_xmin>winRect.w_xmax)swap(winRect.w_xmin,winRect.w_xmax);
    if(winRect.w_ymin>winRect.w_yman)swap(winRect.w_ymin,winRect.w_yman);
}

void drawLine(vector<point>&points){//ok
    if(points.size()<2){
        cout<<"点数不足"<<endl;
    }else{
        glBegin(GL_LINES);
        for(int i=0;i<points.size();i++){
            glVertex2i(points[i].x, points[i].y);
        }
        glEnd();
    }
}

void drawLine(point &p1,point &p2,int x,int y){
    p2=point(x,y);
    glBegin(GL_LINES);
    glVertex2i(p1.x, p1.y);
    glVertex2i(p2.x, p2.y);
    glEnd();
}

void drawRectangle(point &p1,point &p2,bool isFill,int x,int y){//ok
    if(isFill){
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    p2=point(x,y);
    glRecti(p1.x,p1.y,p2.x,p2.y);
}

void drawRectangle(vector<point>&points,bool isFill=false){//ok
    if(isFill){
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    if(points.size()<2){
        cout<<"点数不足"<<endl;
    }else{
        for(int i=0;i<points.size();i+=2){
            glRecti(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
        }
    }
}

void drawRectangle(rect& Rect,bool isFill=false){
    if(isFill){
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    glRectf(Rect.w_xmin,Rect.w_ymin,Rect.w_xmax,Rect.w_yman);
}

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

void Line_Clipping(vector<point>&points,rect& winRect){
    if(points.size()<2){
        cout<<"点数不足"<<endl;
    }else{
        point &p1=points[0],&p2=points[1];
        float dx=p2.x-p1.x,dy=p2.y-p1.y;
        float umax=0.0,umin=1.0;
        point p=p1;
        swap(winRect);
        if(Clip_Top(-dx, p1.x-winRect.w_xmin, umax, umin)){
            if(Clip_Top(dx,winRect.w_xmax-p1.x,umax, umin)){
                if(Clip_Top(-dy, p1.y-winRect.w_ymin, umax, umin)){
                    if(Clip_Top(dy,winRect.w_yman-p1.y, umax, umin)){
                        p1.x=(int)(p.x+umax*dx);
                        p1.y=(int)(p.y+umax*dy);
                        p2.x=(int)(p.x+umin*dx);
                        p2.y=(int)(p.y+umin*dy);
                    }
                }
            }
        }
    }
}


void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
    point p;
    if(iPointNum==1){
        glEnable(GL_LINE_STIPPLE);
    }else{
        glDisable(GL_LINE_STIPPLE);
    }
    switch (iMod){
        case 1:
            switch(pointVertex.size()){
            case 1:
                    drawLine(pointVertex[0],p,xKey,yKey);
                    break;
            case 2:
                    drawLine(pointVertex);
                    switch (iMouseNum) {
                        case 0:
                            break;
                        case 1:
                            drawRectangle(pointVertex[0],p,false,xMouse,yMouse);
                            break;
                        case 2:
                            drawRectangle(pointRect,false);
                            getRect(pointRect,winObj);
                            Line_Clipping(pointVertex,winObj);
                            glColor3f(0.0f,1.0f,0.0f);
                            drawLine(pointVertex);
                            break;
                    }
                    break;
            }
            break;
        case 2:
            break;
    }
    glutSwapBuffers();
}

void MousePlot(GLint button,GLint action,GLint x,GLint y){//ok
    if(pointVertex.size()>=2){
        if(button==GLUT_LEFT_BUTTON&&action==GLUT_DOWN){
            if(iMouseNum==0||iMouseNum==2){
                iMouseNum=1;
                xMouse=x;
                yMouse=winHeight-y;
                pointRect.clear();
                pointRect.push_back(point(x,winHeight-y));
                glutPostRedisplay();
            }else{
                iMouseNum=2;
                pointRect.push_back(point(x,winHeight-y));
                glutPostRedisplay();
            }
        }
    }
}

void Key(unsigned char key,int x,int y){//ok
    switch(key){
        case 'P':
        case 'p':
            iMouseNum=0;
            if(iPointNum==0||iPointNum==2){
                iPointNum=1;
                pointVertex.clear();
                pointVertex.push_back({point(x,winHeight-y)});
                glutPostRedisplay();
            }else{
                iPointNum=2;
                pointVertex.push_back({point(x,winHeight-y)});
                glutPostRedisplay();
            }
            break;
        case 'C':
        case 'c':
            if(iMouseNum!=0){
                iMouseNum=0;
                pointRect.clear();
                glutPostRedisplay();
            }else{
                iPointNum=0;
                pointVertex.clear();
                glutPostRedisplay();
            }
            break;
        default:break;
    }
}
void PassiveMouse(GLint x,GLint y){//ok
    if(iPointNum==1){
        xKey=x;
        yKey=winHeight-y;
        glutPostRedisplay();
    }
    if(iMouseNum==1){
        xMouse=x;
        yMouse=winHeight-y;
        glutPostRedisplay();
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //使用双缓存及RGB模型
    glutInitWindowSize(400, 300); //指定窗口的尺寸
    glutInitWindowPosition(100, 100); //指定窗口在屏幕上的位置
    glutCreateWindow("直线裁剪");
    
    int nMainMenu = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("直线", 1);
    glutAddMenuEntry("矩形", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);  //右键
    
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize); //指定窗口再整形回调函数
    glutMouseFunc(MousePlot); //指定鼠标响应函数
    glutKeyboardFunc(Key);
    glutPassiveMotionFunc(PassiveMouse); //指定鼠标移动响应函数
    
    init();
    glutMainLoop();
    return 0;
}
