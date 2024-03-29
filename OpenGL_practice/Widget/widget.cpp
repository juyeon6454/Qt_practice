#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)

{

    rectPosX = 0.0f;
    rectPosY = 0.0f;
    rectSize = 250;

    xStep = 5.0f;
    yStep = 5.0f;

    setWindowTitle("Hello OpenGL");
    resize(600,600);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(timerFunction()));
    timer->start(1000/60);
}

Widget::~Widget()
{

}

void Widget::initializeGL() {
    //initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,0.0);
}

void Widget::resizeGL(int w, int h)
{
//    windowWidth = w;
//    windowHeight = h;

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    //glOrtho(0, w/this->size().width(), 0, h/this->size().height(), -1, 1);
//    glViewport(0, 0, (GLint)w, (GLint)h);

//    glOrtho(-1*w, w, -1*h, h, -1.0, 1.0);

    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);

}

void Widget::paintGL()
{
    GLushort arPat[] = {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa, 0x33ff, 0x33ff, 0x33ff, 0x57ff, 0x57ff};
    GLint arFac[] = {1,2,3,4,1,2,3,1,2,};

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0); //r,g,b 색상 : 흰색

    //glBegin(GL_POLYGON);
    //glPointSize(10.0);
   // glEnable(GL_POINT_SMOOTH);

//    GLfloat w = 1,y;
//    for(y=0.8; y > -0.8; y -= 0.2) {
//        glLineWidth(w++);
//        glBegin(GL_LINES);
//        glVertex2f(-0.8, y);
//        glVertex2f(0.8,y);
//        glEnd();

//    }; //선 굵기


//    GLfloat x = -0.8;
//    GLfloat y = 0.4;
//    for(int i = 0; i < 6; i++){
//        glVertex2f(x,y);
//        x += 0.3;
//        y *= -1;
//    }; //직선3개



//    glVertex3f(rectPosX, rectPosY, 0.0);
//    glVertex3f(rectPosX, rectPosY - rectSize, 0.0);
//    glVertex3f(rectPosX + rectSize, rectPosY - rectSize, 0.0);
//    glVertex3f(rectPosX + rectSize, rectPosY, 0.0); //움직이는 사각형

//    glVertex2f(0.0,0.6);
//    glColor3f(1.0,0.0,0.0);
//    glVertex2f(-0.6,0.0);
//    glVertex2f(-0.4, -0.6);
//    glColor3f(0.0,1.0,0.0);
//    glVertex2f(0.4, -0.6);
//    glColor3f(0.0,0.0,1.0);
//    glVertex2f(0.6,0.0); //오각형

//    glVertex2f(0.0,0.5);
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5); // 삼각형

//      glVertex2f(0.0, 0.0);
//      glVertex2f(1.0, 0.0);
//      glVertex2f(0.0, 1.0);
//      glVertex2f(1.0, 1.0);
//      glVertex2f(0.5, 0.5);

    glEnable(GL_LINE_STIPPLE);
    GLfloat y;
    GLint idx = 0;
    for(y = 0.8; y > -0.8; y -= 0.2) {
        glLineStipple(arFac[idx], arPat[idx]);
        glBegin(GL_LINES);
        glVertex2f(-0.8, y);
        glVertex2f(0.8, y);
        glEnd();
        idx++;
    };
    glEnd();

    glFlush();

}

void Widget::timerFunction()
{
    if(rectPosX > windowWidth - rectSize || rectPosX < -windowWidth)
        xStep = -xStep;

    if(rectPosY > windowHeight || rectPosY < -windowHeight + rectSize)
        yStep = -yStep;

    rectPosX += xStep;
    rectPosY += yStep;


   if(rectPosX > (windowWidth-rectSize + xStep))
       rectPosX = windowWidth-rectSize-1;
   else if(rectPosX < -(windowWidth + xStep))
       rectPosX = -windowWidth-1;

   if(rectPosY > (windowHeight + yStep))
       rectPosY = windowHeight -1;
   else if(rectPosY <-(windowHeight - rectSize + yStep))
       rectPosY = -windowHeight + rectSize - 1;

   repaint();
}

