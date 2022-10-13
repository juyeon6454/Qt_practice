#include "brick.h"
#include <QPainter>

#define WIDTH 50
#define HEIGHT 12

Brick::Brick(QWidget *parent)
    : QWidget(parent)
{
    resize(WIDTH, HEIGHT);
   // setPixmap(QPixmap("brick.png").scaled(WIDTH,HEIGHT));
    setStyleSheet("background-color:rgba(0,0,0,0)");

}

void Brick::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);//컴파일시 사용하지 않는 변수에 대한 경고 메시지를 표시하지 않도록 함

    QPainter p(this);
    p.setBrush(QColor(Qt::cyan));
    p.drawRect(0,0,WIDTH,HEIGHT);
}
