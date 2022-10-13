#ifndef PADDLE_H
#define PADDLE_H

#include <QWidget>
#include <QLabel>

class Paddle : public QWidget
{
public:
    Paddle(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *e);

signals:

};

#endif // PADDLE_H
