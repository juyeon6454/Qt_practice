#include "widget.h"

#ifdef _APPLE_ //MAC OS X인 경우
#include <GLUT/glut.h>
#else          //Linux 등의 OS인 경우
#include <GL/glut.h>
#endif

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Matrix");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,0.0);

}

void Widget::resizeGL(int w, int h)
{

    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

}

void Widget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    GLfloat trans[16] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0.5, 0.5, 0, 1
    };
    glMultMatrixf(trans);

//    GLfloat scale[16] = {
//        1.5, 0, 0, 0,
//        0, 1.5, 0, 0,
//        0, 0, 1, 0,
//        0, 0, 0, 1
//    };
//    glMultMatrixf(scale);

//    GLfloat sheer[16] = {
//        1,0,0,0,
//        0.5, 1, 0, 0,
//        0, 0, 1, 0,
//        0, 0, 0, 1
//    };
//    glMultMatrixf(sheer);
    glutWireTeapot(0.2);

    glPopMatrix();
    glFlush();
}





