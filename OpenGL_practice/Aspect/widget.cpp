#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Aspect");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0, 0.0, 0.0);

}

void Widget::resizeGL(int w, int h)
{

//*직교 투영 영역을 조정하여 종횡비 유지
    glViewport(0, 0, w, h);

    if(h==0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect = (GLfloat)w/(GLfloat)h;
    if(w>h){
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, -1.0, 1.0, -1.0);

    }else{
        glOrtho(-1.0, 1.0, -1.0/aspect, 1.0/aspect, 1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Widget::paintGL()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0);
    glRectf(-1.0, 1.0, 1.0, -1.0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}





