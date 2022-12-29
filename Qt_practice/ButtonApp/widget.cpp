#include "widget.h"
#include <QPushButton>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton("Quit", this);
    button->setObjectName("button1");
    button->move(width()/2, height()/2);

    QPushButton *button2 = new QPushButton("Quit2", this);
    button2->setObjectName("button2");
    button->move(width()/2, height()/2 - 50);
#if 1
    connect(button, SIGNAL(clicked()), qApp, SLOT(quit()));
    //button->dumpObjectInfo();
    button->dumpObjectTree();

    connect(button2, SIGNAL(clicked()), qApp, SLOT(quit()));
    //button2->dumpObjectInfo();
    button2->dumpObjectTree();
#else
    connect(button, cl)
#endif



}

Widget::~Widget()
{
}
