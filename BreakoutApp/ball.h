#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QLabel>

class Ball : public QWidget
{
public:
    Ball(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *e);

signals:

};

#endif // BALL_H
