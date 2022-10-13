#ifndef PENDULUMITEM_H
#define PENDULUMITEM_H

#include <QWidget>
#include <QGraphicsItem>

class Pendulumitem : public QGraphicsItem
{
   //Q_OBJECT

public:
//    Pendulumitem(QWidget *parent = nullptr);
//    ~Pendulumitem();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*);
};
#endif // PENDULUMITEM_H
