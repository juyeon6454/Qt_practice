#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = 120, yAngle = 30, zAngle = 75;
    setWindowTitle("OpenGL ColorArray");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
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
    static GLfloat vert[] = {
        0, 0, -0.8, //중앙
        0.5, 0.5, 0, //우상
        -0.5, 0.5, 0, //좌상
        -0.5, -0.5, 0, //좌하
        0.5, -0.5, 0, //우하
    };

    static GLfloat color[] = {
        1.0, 1.0, 1.0, //중앙
        0.0, 0.0, 1.0, //우상
        1.0, 0.0, 0.0, //좌상
        1.0, 1.0, 0.0, //좌하
        0.0, 1.0, 0.0, //우하
    };


    static GLubyte index[] = {
        0, 1, 2, //90도
        0, 2, 3, //180도
        0, 3, 4, //270도
        0, 4, 1, //360도
    };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1,1,1);
    glRectf(-0.5, 0.5, 0.5, -0.5);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vert);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, color);

    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, index);
    glPopMatrix();
    glFlush();

}


//==============================================
//#include "widget.h"

//Widget::Widget(QWidget *parent)
//    : QOpenGLWidget(parent)
//{
//    xAngle = 120, yAngle = 30, zAngle = 75;
//    setWindowTitle("OpenGL VertexArrayIndex");
//    resize(600, 600);
//}

//Widget::~Widget()
//{

//}

//void Widget::initializeGL()
//{
//    initializeOpenGLFunctions();
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//}

//void Widget::resizeGL(int w, int h)
//{
//    glViewport(0, 0, (GLint)w, (GLint)h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-1, 1, -1, 1, -1, 1);
//}

//void Widget::paintGL()                  // 반시계방향으로 그려진다.(반시계방향 : 앞면)
//{
//    static GLfloat vertcolor[] = {
//        1,1,1, 0, 0, -0.8,  //중앙
//        0,0,1, 0.5, 0.5, 0, //우상
//        1,0,0, -0.5, 0.5, 0, //좌상
//        1,1,0, -0.5, -0.5, 0,//좌하
//        0,1,0, 0.5, -0.5, 0,//우하
//    };

//    static GLubyte index[] = {
//        0, 1, 2,                // 90도
//        0, 2, 3,                // 180도
//        0, 3, 4,                // 270도
//        0, 4, 1,                // 360도
//    };

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST);
//    glShadeModel(GL_FLAT);

//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
//    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
//    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

//    glColor3f(1, 1, 1);
//    glRectf(-0.5, 0.5, 0.5, -0.5);

//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*6, &vertcolor[3]);
//    glEnableClientState(GL_COLOR_ARRAY);
//    glColorPointer(3, GL_FLOAT, sizeof(GLfloat)*6, vertcolor);

//    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, index);
//    glPopMatrix();
//    glFlush();
//}


