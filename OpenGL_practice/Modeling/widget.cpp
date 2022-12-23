#include "widget.h"
#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    Action = 0;

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutWireTeapot(0.2);

    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    glMatrixModel(GL_MODELVIEW);
    glLoadIdentity();
    glColorf3f(1.0, 1.0, 1.0);

    switch(event->key( )) {

    case Qt::Key_Z:
        ex += 0.1;
        break;
    case Qt::Key_1:
        yAngle += 2;
        break;
    case Qt::Key_2:
        yAngle -= 2;
        break;
    case Qt::Key_3:
        xAngle += 2;
        break;
    case Qt::Key_4:
        xAngle -= 2;
        break;
    case Qt::Key_5:
        zAngle += 2;
        break;
    case Qt::Key_6:
        zAngle -= 2;
    case Qt::Key_7:
        ex += 0.1;
        break;
    case Qt::Key_8:
        ex -= 0.1;
        break;
    case Qt::Key_9:
        ey -= 0.1;
        break;
    case Qt::Key_0:
        xAngle = yAngle = zAngle = 0.0;
        break;

      };

    update();




}

