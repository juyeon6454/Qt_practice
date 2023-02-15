#include "mainwindow.h"
#include <QApplication>

/* mainWidow 창을 띄움 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
