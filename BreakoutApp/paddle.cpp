#include "paddle.h"
#include <QPainter>

#define WIDTH 50
#define HEIGHT 12

Paddle::Paddle(QWidget *parent)
    : QWidget(parent)
{
    resize(WIDTH, HEIGHT);
   // setPixmap(QPixmap("paddle.png").scaled(WIDTH, HEIGHT));
    setStyleSheet("background-color:rgba(0,0,0,0)");
}

void Paddle::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);//컴파일시 사용하지 않는 변수에 대한 경고 메시지를 표시하지 않도록 함

    QPainter p(this);
    p.setPen(QColor(Qt::transparent));//외각선/브러쉬는 채워지는 면을 의미
    p.setBrush(QColor(Qt::blue));
    p.drawRoundedRect(0,0,WIDTH,HEIGHT, 5, 5);
}

