#include "widget.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *hello = new QLabel("Hello Qt!",0,Qt::FramelessWindowHint);
    //hello->showMaximized();
    hello->showMinimized();//작게 나옴
    hello->setCursor(QCursor(Qt::OpenHandCursor));
    //hello->setCursor(QCursor(Qt::ArrowCursor));//기존 커서
    Widget w;
    w.show();
    return a.exec();
}
