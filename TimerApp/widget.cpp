#include "widget.h"
#include <QTimerEvent>
#include <QTimer>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QLabel(parent)
{

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(displayClock()));
   // displayClock();
    timer->start(1000);
    resize(90,40);

//    setText("Timer");

//    int id1 = startTimer(300);
//    int id2 = startTimer(500);
}

Widget::~Widget()
{

}

//void Widget::timerEvent(QTimerEvent *event)
//{
//    setText(QString::number(event->timerId()));
//}

void Widget::displayClock()
{
    setText(QTime::currentTime().toString());
}
