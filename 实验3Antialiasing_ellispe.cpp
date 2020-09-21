//
//  main.cpp
//  Antialiasing_ellispe
//
//  Created by admin on 2020/5/2.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
using namespace std;

void init(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);//设置背景颜色为白色
    glLineWidth(12.0f);
    glMatrixMode(GL_PROJECTION);//设置投影参数
}

void putPixel(int x,int y){
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(12.0f);
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

void MidBresenhamEllipse(int x0,int y0,int a,int b){//椭圆中心,长半轴,短半轴
    int x,y;
    float d1,d2;
    x=0;y=b;
    d1=b*b+a*a*(-b+0.25);
    draw(x0,y0,x,y);
    while(b*b*(x+1)<a*a*(y-0.5)){
        if(d1<=0){
            d1+=b*b*(2*x+3);
            x++;
        }else{
            d1+=b*b*(2*x+3)+a*a*(-2*y+2);
            x++;y--;
        }
        draw(x0,y0,x,y);
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
        draw(x0,y0,x,y);
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

void displayt(){
    glClear(GL_COLOR_BUFFER_BIT);
    int x0=120,y0=120,a=100,b=60;
    MidBresenhamEllipse(x0,y0,a,b);
}

void displayw(){
    glClear(GL_COLOR_BUFFER_BIT);
    int x0=120,y0=120,a=100,b=60;
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    MidBresenhamEllipse(x0,y0,a,b);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //使用双缓存及RGB模型
    glutInitWindowSize(400, 400); //指定窗口的尺寸
    glutInitWindowPosition(400, 400); //指定窗口在屏幕上的位置
    glutCreateWindow("原始图形");
    glutDisplayFunc(displayt);
    glutReshapeFunc(ChangeSize);
    init();
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //使用双缓存及RGB模型
    glutInitWindowSize(400, 400); //指定窗口的尺寸
    glutInitWindowPosition(400, 400); //指定窗口在屏幕上的位置
    glutCreateWindow("反走样图形");
    glutDisplayFunc(displayw);
    glutReshapeFunc(ChangeSize);
    init();
    glutMainLoop();
    return 0;
}
