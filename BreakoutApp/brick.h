#ifndef BRICK_H
#define BRICK_H

#include <QLabel>
#include <QWidget>

class Brick : public QWidget
{
public:
    Brick(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *e);

signals:

};

#endif // BRICK_H
