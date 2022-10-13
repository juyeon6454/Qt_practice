#include "widget.h"

#include <QSvgWidget>
#include <QSvgRenderer>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300,300);
    buffer = QImage(size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&buffer);
    painter.setViewport(0, 0, width(), height());
    painter.eraseRect(0,0,width(), height());

    QSvgWidget* svgw = new QSvgWidget("sample.svg");
    svgw->renderer()->render(&painter);
    delete svgw;
    //svgw->show();
//ㅋㅋ 이걸가?ㅋㅋ

    //    QSvgRenderer render("sample.svg");
    //    render.render(&painter);
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,buffer);
}

