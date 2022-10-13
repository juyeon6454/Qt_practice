#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QMediaPlayer>

#include "ball.h"
#include "brick.h"
#include "paddle.h"

class QLabel;

class Breakout : public QWidget
{
    Q_OBJECT

private:
    static const int NO_OF_BRICKS = 30;

//    QLabel *ball;
//    QLabel *paddle;
//    QLabel *bricks[NO_OF_BRICKS];

    Ball *ball;
    Paddle *paddle;
    Brick *bricks[NO_OF_BRICKS];

    QMediaPlayer *bgPlayer;
    QMediaPlayer *effectPlayer;

    int timerId;
    int xDir,yDir;

public:
   Breakout(QWidget *parent = nullptr);
   ~Breakout();

protected:
    void keyPressEvent(QKeyEvent*);
    void mouseMoveEvent(QMouseEvent *e);
    void timerEvent(QTimerEvent *);
    void moveObjects();
    void checkCollision();
//    void paintEvent(QPaintEvent *e);

protected:
    static const int MOVE_SPEED=3;

};
#endif // BREAKOUT_H
