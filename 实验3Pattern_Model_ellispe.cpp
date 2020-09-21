//
//  main.cpp
//  Pattern_Model_ellispe
//
//  Created by admin on 2020/5/2.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int iPointNum=0;//已确定点的数目
int x1=0,x2=0,y1=0,y2=0;
int winWidth=400,winHeight=300;
int iMod=1;//1表示画直线，2表示画矩形，3表示画椭圆
typedef struct Point {
    int x,y;
    Point(int a=0,int b=0){
        x=a;
        y=b;
    }
}point;
vector<point>pointVertex;
bool isFill=0;
GLubyte fly[]={
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,
    0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00
};

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

void draw(int x0,int y0,int x,int y){//(x0,y0):椭圆中心,(x,y):椭圆上的点
    putPixel(x0+x,y0+y);
    putPixel(x0-x,y0+y);             //画对称点
    putPixel(x0+x,y0-y);
    putPixel(x0-x,y0-y);
}

void  OnMidpointellispe(int a,int b,vector<point>&pointVertex){//长半轴,短半轴
    int x,y;
    float d1,d2;
    x=0;y=b;
    d1=b*b+a*a*(-b+0.25);
    pointVertex.push_back({x,y});
    //draw(x0,y0,x,y);
    while(b*b*(x+1)<a*a*(y-0.5)){
        if(d1<=0){
            d1+=b*b*(2*x+3);
            x++;
        }else{
            d1+=b*b*(2*x+3)+a*a*(-2*y+2);
            x++;y--;
        }
        pointVertex.push_back({x,y});
        //draw(x0,y0,x,y);
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
        pointVertex.push_back({x,y});
        //draw(x0,y0,x,y);
    }
}

void drawEllispe(vector<point> &pointVertex,bool isFill){
    isFill=true;
    if(isFill==true){
        glBegin(GL_POLYGON);
        for(vector<point>::iterator i=pointVertex.begin();i!=pointVertex.end();i++){
            glVertex2i((*i).x,(*i).y);
            glVertex2i(-(*i).x,(*i).y);
            glVertex2i((*i).x, -(*i).y);
            glVertex2i(-(*i).x,-(*i).y);
        }
        glEnd();
    }else{
        glPolygonMode(GL_FRONT_AND_BACK ,GL_LINE );
        glBegin(GL_POLYGON);
        for(vector<point>::iterator i=pointVertex.begin();i!=pointVertex.end();i++){
            glVertex2i((*i).x,(*i).y);
            if(i==pointVertex.end()-1){
                glEdgeFlag(false);
                glVertex2i((*i).x,(*i).y);
            }
            glEdgeFlag(true);
        }
        glEnd();
        glBegin(GL_POLYGON);
        for(vector<point>::iterator i=pointVertex.begin();i!=pointVertex.end();i++){
            glVertex2i(-(*i).x,(*i).y);
            if(i==pointVertex.end()-1){
                glEdgeFlag(false);
                glVertex2i(-(*i).x,(*i).y);
            }
            glEdgeFlag(true);
        }
        glEnd();
        glBegin(GL_POLYGON);
        for(vector<point>::iterator i=pointVertex.begin();i!=pointVertex.end();i++){
            glVertex2i(-(*i).x,-(*i).y);
            if(i==pointVertex.end()-1){
                glEdgeFlag(false);
                glVertex2i(-(*i).x,-(*i).y);
            }
            glEdgeFlag(true);
        }
        glEnd();
        glBegin(GL_POLYGON);
        for(vector<point>::iterator i=pointVertex.begin();i!=pointVertex.end();i++){
            glVertex2i((*i).x,-(*i).y);
            if(i==pointVertex.end()-1){
                glEdgeFlag(false);
                glVertex2i((*i).x,-(*i).y);
            }
            glEdgeFlag(true);
        }
        glEnd();
    }
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
    }else if(iMod==2){//画矩形
        glRecti(x1,y1,x2,y2);
    }else if(iMod==3){//画椭圆
        //        glPolygonMode(GL_FRONT_AND_BACK ,GL_LINE );
        //        if(iPointNum==1)glRecti(x1,y1,x2,y2);
        glTranslated((x1+x2)/2, (y1+y2)/2, 0);
        int a,b;
        if(x1>x2){
            a=(x1-x2)/2;
        }else{
            a=(x2-x1)/2;
        }
        if(y1>y2){
            b=(y1-y2)/2;
        }else{
            b=(y1-y2)/2;
        }
        glEnable(GL_POLYGON_STIPPLE);
        glPolygonStipple(fly);
        OnMidpointellispe(a,b,pointVertex);
        drawEllispe(pointVertex,true);
        glTranslated(-(x1+x2)/2, -(y1+y2)/2, 0);
        pointVertex.clear();
        
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
        case 'F':
        case 'f':
            isFill=true;
            glutPostRedisplay();
            break;
        case 'L':
        case 'l':
            isFill=false;
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
    glutInitWindowSize(400, 400); //指定窗口的尺寸
    glutInitWindowPosition(400, 400); //指定窗口在屏幕上的位置
    glutCreateWindow("橡皮筋技术");
    
    int nMainMenu = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("直线", 1);
    glutAddMenuEntry("矩形", 2);
    glutAddMenuEntry("椭圆", 3);
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
