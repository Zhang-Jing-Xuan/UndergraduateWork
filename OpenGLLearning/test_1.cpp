//
//  main.cpp
//  test_1
//
//  Created by admin on 2020/5/30.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <cmath>
const int N=50;
const GLfloat R=0.5,PI=3.1415926535897932384626;
const GLfloat factor=0.1f;
const int day=180;
void myDisplay1(void) {//画圆
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);//实心
    //glBegin(GL_LINE_LOOP);//空心
    //glBegin(GL_POINTS);//离散点
    //glBegin(GL_LINE_STRIP);//离散点相连
    //glBegin(GL_QUADS);//四边形
    for(int i=0;i<N;i++){
        glVertex2f(R*cos(2*PI/N*i),R*sin(2*PI/N*i));
    }
    glEnd();
    glFlush();
}

void myDisplay2(){//画正弦函数
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);//x轴
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);//y轴
    glBegin(GL_LINE_STRIP);
    for(float i=-1.0f/factor;i<=1/factor;i+=0.01){
        glVertex2f(i*factor, sin(i)*factor);
    }
    glEnd();
    glFlush();
}

void myDisplay3(){//画虚线
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glEnd();
    
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x0F0F);
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    
    glFlush();
}

void myDisplay4(){//画多边形
   glClear(GL_COLOR_BUFFER_BIT);//把屏幕上的颜色清空
   glClearColor(1.0f, 0.0f, 0.0f, 0.0f);//设置清空颜色为红色
   glPolygonMode(GL_FRONT, GL_FILL); // 设置正面为填充模式
   glPolygonMode(GL_BACK, GL_LINE); // 设置反面为线形模式
   glFrontFace(GL_CCW); // 设置逆时针方向为正面
   glColor3f(0.0f, 1.0f, 1.0f);//浅蓝色
   glBegin(GL_POLYGON); // 按逆时针绘制一个正方形，在左下方
   glVertex2f(-0.5f, -0.5f);
   glVertex2f(0.0f, -0.5f);
   glVertex2f(0.0f, 0.0f);
   glVertex2f(-0.5f, 0.0f);
   glEnd();
    
   glBegin(GL_POLYGON);// 按顺时针绘制一个正方形，在右上方
   glVertex2f(0.0f, 0.0f);
   glVertex2f(0.0f, 0.5f);
   glVertex2f(0.5f, 0.5f);
   glVertex2f(0.5f, 0.0f);
   glEnd();
   glFlush();
}

void myDisplay5(){
    glClear(GL_COLOR_BUFFER_BIT);//把屏幕上的颜色清空
    int i;
    //glShadeModel(GL_FLAT);//单色
    glShadeModel(GL_SMOOTH);//平滑，有渐变效果
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    for(i=0; i<=8; ++i)
    {
        glColor3f(i&0x04, i&0x02, i&0x01);
        glVertex2f(cos(i*PI/4),sin(i*PI/4));
    }
    glEnd();
    glFlush();
}

void myDisplay6(void)//静态的天体
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);
    // 绘制红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // 绘制蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // 绘制黄色的“月亮”
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day/30.0*360.0 - day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第一个 OpenGL 程序");
    //glutDisplayFunc(&myDisplay1);
    //glutDisplayFunc(&myDisplay2);
    //glutDisplayFunc(&myDisplay3);
    //glutDisplayFunc(&myDisplay4);
    //glutDisplayFunc(&myDisplay5);
    glutDisplayFunc(&myDisplay6);
    glutMainLoop();
    return 0;
}
