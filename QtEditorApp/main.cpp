#include "qteditor.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("hello_ko");
    a.installTranslator(&translator);
    QtEditor w;
    w.show();
    return a.exec();
}

