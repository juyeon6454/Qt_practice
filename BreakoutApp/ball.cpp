#include "ball.h"
#include <QPainter>
#define RADIUS 10

Ball::Ball(QWidget *parent)
    : QWidget(parent)
{
    resize(RADIUS, RADIUS);
    //setPixmap(QPixmap("ball.png"));
    setStyleSheet("background-color: rgba(0,0,0,0)");//투명한 배경을 설정
}

void Ball::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);//컴파일시 사용하지 않는 변수에 대한 경고 메시지를 표시하지 않도록 함

    QPainter p(this);
    p.setPen(QColor(Qt::transparent));//외각선/브러쉬는 채워지는 면을 의미
    p.setBrush(QColor(Qt::red));
    p.drawEllipse(0,0,RADIUS,RADIUS);
}
