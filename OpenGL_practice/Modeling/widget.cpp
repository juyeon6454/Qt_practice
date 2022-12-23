#include "widget.h"
#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    Action = 0;
    Rotation = 0;

    setWindowTitle("OpenGL Modeling");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    //glLoadIdentity();
//    glutWireTeapot(0.2);

//    glTranslatef(0.6, 0.0, 0.0);
//    glutWireTeapot(0.2);

//    glLoadIdentity();
//    glTranslatef(0.0,0.6, 0.0);
//    glutWireTeapot(0.2);
//    glFlush();


//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);

//    glPushMatrix();
//    glutWireTeapot(0.2);
//    glPushMatrix();
//    glTranslatef(0.6,0.0,0.0);
//    glutWireTeapot(0.2);
//    glPopMatrix();
//    glTranslatef(0.0, 0.6, 0.0);
//    glutWireTeapot(0.2);
//    glPopMatrix();
//    glFlush();
//=============================================
//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//    //glRotated(Rotation++, 1.0, 1.0, 1.0);
//    glRotatef(0.0,1.0,1.0,1.0);
//    glScalef(-2.0, 3.0, 1.0);
//    glutWireTeapot(0.2);
//    glPopMatrix();
//    glFlush();

//    update();

    //==========================================


    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();

    glTranslatef(0.5, 0.5, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.5, -0.5, 0.0);


    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);


    glEnd();

    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
//    glMatrixModel(GL_MODELVIEW);
//    glLoadIdentity();
//    glColorf3f(1.0, 1.0, 1.0);

//    switch(event->key( )) {

//    case Qt::Key_Z:
//        ex += 0.1;
//        break;
//    case Qt::Key_1:
//        yAngle += 2;
//        break;
//    case Qt::Key_2:
//        yAngle -= 2;
//        break;
//    case Qt::Key_3:
//        xAngle += 2;
//        break;
//    case Qt::Key_4:
//        xAngle -= 2;
//        break;
//    case Qt::Key_5:
//        zAngle += 2;
//        break;
//    case Qt::Key_6:
//        zAngle -= 2;
//    case Qt::Key_7:
//        ex += 0.1;
//        break;
//    case Qt::Key_8:
//        ex -= 0.1;
//        break;
//    case Qt::Key_9:
//        ey -= 0.1;
//        break;
//    case Qt::Key_0:
//        xAngle = yAngle = zAngle = 0.0;
//        break;

//      };

//    update();




}

