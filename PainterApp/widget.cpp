#include "widget.h"
#include <QPainter>
#include <QFont>
#include <QFontDialog>
#include <QPainterPath>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

//    bool ok;
//    font = QFontDialog::getFont(&ok, this);
    resize(200,200);
}

void Widget::paintEvent(QPaintEvent*)
{
//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 4, Qt::DashLine));
//    painter->drawPoint(100,100);
//    delete painter;
    //=======================점=================

//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 5, Qt::DashLine));
//    painter->drawLine(20,20,160,160);
//    delete painter;

    //=====================선=================

//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 5, Qt::SolidLine));
//    painter->drawRect(20,20,160,160);
//    delete painter;

    //================= 사각형 ================

//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 5, Qt::SolidLine));
//    painter->drawRoundedRect(20,20,160,160,50,80);//x방향으로 50 y방향으로 80
//    delete painter;

    //================= 둥근 사각형 =============

//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 5, Qt::SolidLine));
//    //painter->drawEllipse(20,20,140,170);
//    painter->drawEllipse(QPoint(100,100),80,80);
//    delete painter;

    //================== 원 =====================

//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 5, Qt::DotLine));
//    painter->drawArc(20,20,160, 160, 30 *16, 150 *16);
//    delete painter;

    //=============== 원의 외각선 =================

//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 5, Qt::SolidLine));
//    painter->drawChord(20,20,160, 160, 30 *16, 150 *16);
//    delete painter;

    //================ 현 =========================

//    QPainter *painter = new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 5, Qt::SolidLine));
//    painter->drawPie(20,20,160, 160, 50 *16, 130 *16);
//    delete painter;

    //============== 파이 =========================



//    QPainter *painter = new QPainter(this);
 //===========다각형 그리기 배열 ===============아래
//    static const QPoint points[6] = {
//        QPoint(20,20),
//        QPoint(20,90),
//        QPoint(90,80),
//        QPoint(80,160),
//        QPoint(160,80),
//        QPoint(80,20)
//    };
//    painter->drawPolygon(points, 6);
 //===========다각형 그리기 벡터 ===============아래
//    QVector<QPoint> pointsVector;
//    pointsVector<<QPoint(20,20)\
//               <<QPoint(20,90)\
//              <<QPoint(90,80)\
//             <<QPoint(80,160)\
//            <<QPoint(160,80)\
//           <<QPoint(80,20);

//    painter->drawLines(pointsVector);
////==========================================
//    delete painter;


// ============= 문자 (Text) =================
//    QPainter *painter = new QPainter(this);

//    //bool ok;
//    // QFont seriFont("Times", 10, QFont::Bold);
//    //QFont font = QFontDialog::getFont(&ok, this);
//    painter->setFont(font);
//    painter->setPen(QPen(Qt::blue, 5, Qt::SolidLine));
//    painter->drawText(20,20, "Hello Qt!");
//    delete painter;

//============= 선형 Gradient ===============

//    QLinearGradient gradient(0,0,100,180);
//    gradient.setColorAt(0.0, Qt::yellow);
//    gradient.setColorAt(1.0, Qt::blue);//0.0지정 색부터 나옴//3.0하면 상대 색만 나옴

//    QPainter painter;
//    painter.begin(this);
//    painter.setBrush(gradient);
//    painter.drawRect(20,20,160,160);
//    painter.end();


//============= 원형 Gradient ===============

//    QRadialGradient gradient(102,102,85);
//    gradient.setColorAt(0.0, Qt::red);
//    gradient.setColorAt(0.5,Qt::blue);
//    gradient.setColorAt(1.0,Qt::green);

//    QPainter painter;
//    painter.begin(this);
//    painter.setBrush(gradient);
//    painter.drawEllipse(20,20,160,160);
//    painter.end();

//============= PainterPath 클래스 ================

    QPainterPath path;
    path.addRect(20, 20, 60, 60);

    path.moveTo(0, 0);
    path.cubicTo(99, 0,  50, 50,  99, 99);
    path.cubicTo(0, 99,  50, 50,  0, 0);

    QPainter painter(this);
    painter.fillRect(0, 0, 100, 100, Qt::white);
    painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                        Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QColor(122, 163, 39));

    painter.drawPath(path);


}


Widget::~Widget()
{
}

