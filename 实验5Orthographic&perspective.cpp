//
//  main.cpp
//  Orthographic&perspective
//
//  Created by admin on 2020/6/2.
//  Copyright © 2020年 admin. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
using namespace std;
GLuint shape,axis;
int winHeight=400,winWidth=800;
static GLsizei iMode=1;
static GLfloat Rot=45.0f;

//
//void drawString(const char* str,GLfloat x,GLfloat y,GLfloat z ){
//    //按x,y,z为起始位置，显示字符串str
//    static GLuint lists;
//    lists = glGenLists(128);
//    wglUseFontBitmaps(wglGetCurrentDC(),0,MAX_CHAR,lists);
//    glListBase(lists);
//    glRasterPos3f(x,y,z); //起始位置
//    glCallLists(strlen(str),GL_UNSIGNED_BYTE,str);
//}

void* bitmap_fonts[7] = {
    GLUT_BITMAP_9_BY_15,
    GLUT_BITMAP_8_BY_13,
    GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24,
    GLUT_BITMAP_HELVETICA_10,
    GLUT_BITMAP_HELVETICA_12,
    GLUT_BITMAP_HELVETICA_18
    
};

void print_bitmap_string(void* font,const char* s)
{
    if (s && strlen(s)) {
        while (*s) {
            glutBitmapCharacter(font, *s);
            s++;
        }
    }
}

int TextOut(float x,float y,float z,const char* cstr)
{
    glRasterPos3f(x, y,z);
    print_bitmap_string(bitmap_fonts[3], cstr);
    return 1;
}

void init(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);//设置背景颜色为白色
    shape=glGenLists(1);
    glNewList(shape, GL_COMPILE);
    glBegin(GL_TRIANGLES);
    
    glColor4f(0.0f,0.6f,1.0f,0.5f);
    glVertex3f(2.0f,0.0f,0.0);
    glVertex3f(2.0f,1.0f,0.0);
    glVertex3f(1.0f,1.0f,1.0);
    
    glColor4f(0.6f,0.0f,1.0f,0.5f);
    glVertex3f(2.0f,0.0f,0.0);
    glVertex3f(2.0f,1.0f,0.0);
    glVertex3f(0.0f,1.0f,0.0);
    
    glColor4f(0.6f,1.0f,0.0f,0.5f);
    glVertex3f(2.0f,0.0f,0.0);
    glVertex3f(0.0f,1.0f,0.0);
    glVertex3f(1.0f,1.0f,1.0);
    glEnd();
    glEndList();
    axis=glGenLists(1);
    glNewList(axis, GL_COMPILE);
    glBegin(GL_LINES);
    glColor4f(1.0f,0.0f,0.0f,1.0f);
    glVertex3f(-3.0f,0.0f,0.0f);
    glVertex3f(3.0f,0.0f,0.0f);

    glColor4f(0.0f,1.0f,0.0f,1.0f);
    glVertex3f(0.0f,-3.0f,0.0f);
    glVertex3f(0.0f,3.0f,0.0f);

    glColor4f(0.0f,0.0f,1.0f,1.0f);
    glVertex3f(0.0f,0.0f,-3.0f);
    glVertex3f(0.0f,0.0f,3.0f);
    glEnd();
    glEndList();
}

void ChangeSize(GLsizei w,GLsizei h){
    winWidth=w;
    winHeight=h;
    glutPostRedisplay();
}

void SpecialKeys(int key,int x,int y){
    if(key==GLUT_KEY_UP)Rot+=3.0f;
    if(key==GLUT_KEY_DOWN)Rot-=3.0f;
    if(Rot>360.0f)Rot=0.0f;
    if(Rot<-0.0f)Rot=360.0f;
    glutPostRedisplay();
}

void ProcessMenu(int value){
    iMode=value;
    Rot=0.0f;
    glutPostRedisplay();
}

void triangle(GLsizei mode){
    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT,vp);
    int w=vp[2],h=vp[3];
    float x;
    if(w>h){
        x=1.0*(float)(h)/(float)(w);
    }else{
        x=1.0*(float)(w)/(float)(h);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(mode==1){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        switch(iMode){
            case 1:
                gluLookAt(0,5,0,0,0,0,0,0,1);
                break;
            case 2:
                gluLookAt(0,0,5,0,0,0,0,-1,0);
                break;
            case 3:
                gluLookAt(5,0,0,0,0,0,0,0,1);
                break;
        }
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //glOrtho(-5.0,5.0,-5.0,5.0,0.0,5.0);
        glOrtho(-2.2, 2.2, -2.2, 2.2, -20, 20);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
    }else{
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        gluLookAt(5,5,-5,0,0,0,0,0,1);
        glOrtho(-2.2, 2.2, -2.2, 2.2, -20, 20);
        switch(iMode){
            case 1:
                gluLookAt(5,5,-5,0,0,0,0,1,0);
                glRotatef(Rot,0,1,0);
                break;
            case 2:
                gluLookAt(5,5,-5,0,0,0,1,0,0);
                glRotatef(Rot,1,0,0);
                break;
            case 3:
                gluLookAt(5,5,-5,0,0,0,0,0,1);
                glRotatef(Rot,0,0,1);
                break;
        }
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, x, 0.0f, 5.0f);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
    }
    //坐标轴
    TextOut(2,0,0,"x");
    TextOut(0,2,0,"y");
    TextOut(0,0,2,"z");
    glCallList(shape);
    glPopMatrix();
    glPushMatrix();
    glCallList(axis);
    glPopMatrix();
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glViewport(0,0,winWidth/2,winHeight);
    triangle(1);
    glColor3f(1.0,0.0,0.0);
    glViewport(winWidth/2,0,winWidth/2,winHeight);
    triangle(2);
    glFlush();
}


int main(int argc,  char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(600, 600);
    glutInitWindowSize(winWidth,winHeight);
    glutCreateWindow("正交投影&透视投影");
    int nGlutPolyMenu=glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("正视图XOZ(V)",1);
    glutAddMenuEntry("侧视图YOZ(V)",2);
    glutAddMenuEntry("俯视图XOY(V)",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    init();
    
    glutDisplayFunc(&Display);
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    
    glutMainLoop();
    return 0;
}
