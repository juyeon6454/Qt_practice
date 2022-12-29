#include "widget.h"

#include <QCoreApplication>
#include <QTest>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Widget widget;
    //w.show();
    widget.setAge(0);
    QTest::qExec(&widget);
    return a.exec();
}
