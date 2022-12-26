#include "widget.h"
#ifdef _APPLE_ //MAC OS X인 경우
#include <GLUT/glut.h>
#else          //Linux 등의 OS인 경우
#include <GL/glut.h>
#endif

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    Widget w;
    w.show();
    return a.exec();
}
