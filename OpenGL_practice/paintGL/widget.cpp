#include <math.h>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    bEdge = GL_FALSE;

    radius = 0.05;
    delta_theta = 2*M_PI/20;
    theta = 0.0;
    cord_length = 0.5;

    setWindowTitle("OpenGL Animation");
    resize(600,600);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(timerFunction()));
    timer->start(1000/60);

}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

}
void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0,1.0,1.0);

//    glShadeModel(GL_FLAT); //안쓰면 블랜딩

//    glBegin(GL_TRIANGLE_STRIP);
//    GLfloat x = -0.8;
//    GLfloat y = 0.4;

//    for(int i = 0; i < 6; i++) {
//        glVertex2f(x,y);
//        x += 0.3;
//        y *= -1;
//    };

//    for(int i = 0; i < 6; i++) {
//        if(i % 2 == 0) {
//            glColor3f(1.0,0.0,0.0);
//        }else {
//            glColor3f(0.0,1.0,0.0);
//        }
//        glVertex2f(x,y);
//        x += 0.3;
//        y *= -1;
//    };


//    glBegin(GL_TRIANGLES);
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5, 0.0);
//    glVertex2f(0.0, 0.0);

//    glVertex2f(0.0, 0.0);
//    glVertex2f(0.5, 0.0);
//    glVertex2f(0.0, -0.5);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEdgeFlag(TRUE);

    glBegin(GL_TRIANGLES);
    if(bEdge)
        glEdgeFlag(TRUE);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.5, -0.5);
    if(bEdge)
        glEdgeFlag(FALSE);
        glVertex2f(-0.5, -0.5);

    glVertex2f(0.0, 0.0);
    if(bEdge)
        glEdgeFlag(TRUE);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);

    if(bEdge)
        glEdgeFlag(FALSE);
    glVertex2f(0.0, 0.0);
    if(bEdge)
        glEdgeFlag(TRUE);
    glVertex2f(-0.5, -0.5);
    if(bEdge)
        glEdgeFlag(FALSE);
    glVertex2f(0.5, -0.5);


    glEnd();
    glFlush();
}

void Widget::timerFunction()
{
    atime++;
    update();

  }

void Widget::keyPressEventㅇㄹㄹ(QKeyEvent* event)
{
    switch(event->key()){
    case Qt::Key_Up:
        bEdge = GL_TRUE;
        break;

    case Qt::Key_Down:
        bEdge = GL_FALSE;
        break;
    };

    update();
}
