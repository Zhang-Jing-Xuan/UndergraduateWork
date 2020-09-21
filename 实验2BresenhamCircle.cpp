//
//  main.cpp
//  BresenhamCircle
//
//  Created by admin on 2020/4/11.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
using namespace std;

void init(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);//设置背景颜色为白色
    glMatrixMode(GL_PROJECTION);//设置投影参数
}

void putPixel(int x,int y){
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();//强制刷新缓冲
}

void draw(int x0,int y0,int x,int y){//(x0,y0):圆心,(x,y):圆上的点
    putPixel(x0+x,y0+y);putPixel(y0+y,x0+x);
    putPixel(x0-x,y0+y);putPixel(y0+y,x0-x);
    putPixel(x0+x,y0-y);putPixel(y0-y,x0+x);
    putPixel(x0-x,y0-y);putPixel(y0-y,x0-x);
}

void MidBresenhamCircle(int x0,int y0,int r){//圆心,b半径
    int x,y,d;
    x=0;y=r;d=1-r;
    while(x<=y){
        draw(x0,y0,x,y);
        if(d<0){
            d+=2*x+3;
        }else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

void ChangeSize(GLsizei w,GLsizei h){
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

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    int x0=120,y0=120,r=60;
    MidBresenhamCircle(x0,y0,r);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400,400);
    glutInitWindowSize(400,400);
    glutCreateWindow("My_circle");
    glutDisplayFunc(display);
    glutReshapeFunc(ChangeSize);
    init();
    glutMainLoop();
    return 0;
}
