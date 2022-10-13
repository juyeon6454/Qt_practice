#include "pendulumitem.h"
#include <QPainter>
#define PENWIDTH 100

QRectF Pendulumitem::boundingRect() const{
   return QRectF(-20-PENWIDTH/2, -PENWIDTH/2, 40+PENWIDTH, 140+PENWIDTH);
}

void Pendulumitem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*){
    painter->setPen(QPen(Qt::black, 3));
    painter->drawLine(0,0,0,100);
    QRadialGradient g(0,120,20,-10,110);
    g.setColorAt(0.0, Qt::white);
    g.setColorAt(0.5, Qt::yellow);
    g.setColorAt(1.0, Qt::black);
    painter->setBrush(g);
    painter->drawEllipse(-20, 100, 40, 40);

}
