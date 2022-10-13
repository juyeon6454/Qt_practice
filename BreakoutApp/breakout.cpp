#include <QLabel>
#include <QApplication>
#include <QtMultimedia/QtMultimedia>

#include "breakout.h"


#define WIDTH   50
#define HEIGHT  12
#define SCR_WIDTH   300
#define SCR_HEIGHT  400

Breakout::Breakout(QWidget *parent)
    : QWidget(parent), xDir(1),yDir(-1)
{
//    ball = new QLabel(this);
//    ball -> setGeometry(SCR_WIDTH*0.8, SCR_HEIGHT*0.875, 10, 10);//ball size
//    ball -> setStyleSheet("QLabel {background-color:deeppink; border-radius:5px;}");//ball color, size?

//    paddle = new QLabel(this);
//    paddle->setGeometry(SCR_WIDTH*0.7, SCR_HEIGHT*0.9, WIDTH, HEIGHT);
//    paddle->setStyleSheet("QLabel {background-color:steelblue;}");

//    for (int y=0, i=0; y<5; y++)
//        for (int x=0; x<6; x++, i++) {
//            bricks[i] = new QLabel(this);
//            bricks[i]->setStyleSheet("QLabel{background-color:azure;"
//                                     "border:1px solid black}");
//            bricks[i]->setGeometry(x*WIDTH, y*HEIGHT+30, WIDTH, HEIGHT);
//        }

    ball = new Ball(this);
    ball -> setGeometry(SCR_WIDTH*0.8, SCR_HEIGHT*0.875, 10, 10);//ball size

    paddle = new Paddle(this);
    paddle->setGeometry(SCR_WIDTH*0.7, SCR_HEIGHT*0.9, WIDTH, HEIGHT);

    for (int y=0, i=0; y<5; y++)
        for (int x=0; x<6; x++, i++) {
            bricks[i] = new Brick(this);
            bricks[i]->setGeometry(x*WIDTH, y*HEIGHT+30, WIDTH, HEIGHT);
        }



    resize(SCR_WIDTH,SCR_HEIGHT);

    setMouseTracking(true);

    timerId = startTimer(7);//속도 기본 10

    /* 사운드 출력을 위한 미디어 플레이어의 초기화 */
    QAudioOutput *bgAudioOutput = new QAudioOutput;
    bgAudioOutput->setVolume(10);

    bgPlayer = new QMediaPlayer( );
    bgPlayer->setAudioOutput(bgAudioOutput);
    bgPlayer->setLoops(QMediaPlayer::Infinite);         /* 무한 반복 */
    bgPlayer->setSource(QUrl::fromLocalFile(QFileInfo("background.mp3" ).absoluteFilePath( )));
    bgPlayer->play( );
    /* 효과음 출력을 위한 플레이어 */
    QAudioOutput *bgEffectOutput = new QAudioOutput;
    bgEffectOutput->setVolume(200);

    effectPlayer = new QMediaPlayer( );
    effectPlayer->setAudioOutput(bgEffectOutput);
    effectPlayer->setLoops(QMediaPlayer::Once);
    effectPlayer->setSource(QUrl::fromLocalFile(QFileInfo("effect.mp3").absoluteFilePath( )));

    QPicture picture;
    QPainter painter;
    painter.begin(&picture);
    painter.drawEllipse(10,20,80,70);//원그리기
    painter.end();
    picture.save("drawing.pic");//저장

}

void Breakout::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()){
    case Qt::Key_Left:
        paddle->move(paddle->x()-MOVE_SPEED, paddle->y());
        break;
    case Qt::Key_Right:
        paddle->move(paddle->x()+MOVE_SPEED,paddle->y());
        break;
    case Qt::Key_Escape:
        qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(e);
                  }

}

void Breakout::mouseMoveEvent(QMouseEvent *e)
{
    int x=e->pos().x();
    x=(x<0)?0:(x+WIDTH>width())?width()-WIDTH:x;
    paddle->move(x,paddle->y());
}

void Breakout::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    moveObjects();
    checkCollision();
}

void Breakout::moveObjects()
{
    ball->move(ball->x() + xDir, ball->y() + yDir);

    if((ball->x()<=0)||(ball->x()+10>=SCR_WIDTH)){
        xDir *= -1;
    }
    if(ball->y()<=0)yDir=1;
}

void Breakout::checkCollision()
{
    if(ball->geometry().bottom()>height()){

        killTimer(timerId);
        qDebug("Game lost");
        effectPlayer->stop();
        effectPlayer->play();

    }
    //남은 블록이 없으면 게임 종료
    int j=0;
    for(int i=0; i<NO_OF_BRICKS; i++)
        if(bricks[i]->isHidden())j++;

    if(j==NO_OF_BRICKS){
        killTimer(timerId);
        qDebug("Victory");

        effectPlayer->stop();
        effectPlayer->play();
    }
    //사용자(패들)와 충돌을 처리
    if((ball->geometry()).intersects(paddle->geometry())){
        int paddleLPos=paddle->geometry().left();
        int ballLPos=ball->geometry().left();
        int first=paddleLPos+8;
        int second=paddleLPos+16;
        int third=paddleLPos+24;
        int fourth=paddleLPos+32;

        effectPlayer->stop();
        effectPlayer->play();
     //패들의 맞은 부분에 따라서 공의 반사되는 방향 조정
        if(ballLPos<first) xDir = -1; yDir = -1;
        if(ballLPos>=first&&ballLPos<second)xDir=-1;yDir*=-1;
        if(ballLPos>=second&&ballLPos<third)xDir=0;yDir*=-1;
        if(ballLPos>=third&&ballLPos<fourth)xDir=1;yDir*=-1;
        if(ballLPos>fourth)xDir=1; yDir=-1;
}
     //블록의 충돌을 처리
        for(int i=0; i<NO_OF_BRICKS; i++){
            if((ball->geometry()).intersects(bricks[i]->geometry())){
                int ballLeft=ball->geometry().left();
                int ballHeight=ball->geometry().height();
                int ballWidth=ball->geometry().width();
                int ballTop=ball->geometry().top();
     //현재 블록의 위치를 계산
         QPoint pointRight(ballLeft+ballWidth+1,ballTop);
         QPoint pointLeft(ballLeft -1, ballTop);
         QPoint pointTop(ballLeft, ballTop -1);
         QPoint pointBottom(ballLeft, ballTop + ballHeight +1);
         if(!bricks[i]->isHidden()){
             if(bricks[i]->geometry().contains(pointRight))xDir=-1;
                else if(bricks[i]->geometry().contains(pointLeft))xDir = 1;
             if(bricks[i]->geometry().contains(pointTop))yDir=1;
                else if(bricks[i]->geometry().contains(pointBottom))yDir = -1;
             bricks[i]->setHidden(true);

             //블록과 충돌했을 때 사운드 출력
             effectPlayer->stop();
             effectPlayer->play();


            }
        }
    }
}

//void Breakout::paintEvent(QPaintEvent *e)
//{
//    QPicture picture;
//    picture.load("drawing.pic");
//    QPainter painter;
//    painter.begin(this);
//    painter.drawPicture(0,0,picture);
//    painter.end();
//}

Breakout::~Breakout()
{
    delete ball;
    delete paddle;

    for(int i=0; i<NO_OF_BRICKS; i++){
        delete bricks[i];
    }
}

