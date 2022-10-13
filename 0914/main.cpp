//#include "lcdnumber.h"

#include <QApplication>
//#include <QLCDNumber>

//int main(int argc, char **argv)
//{
//    QApplication app(argc, argv);

//    QWidget* widget = new QWidget(0);

//    QLCDNumber *lcd1 = new QLCDNumber(widget);
//    lcd1->setSegmentStyle(QLCDNumber::Flat);
//    lcd1->display(2014);
//    lcd1->move(10, 10);

//    QLCDNumber *lcd2 = new QLCDNumber(widget);
//    lcd2->setSegmentStyle(QLCDNumber::Flat);
//    lcd2->display(2014);
//    lcd2->setHexMode();
//    lcd2->move(10, 40);


//    widget->resize(120,80);
//    widget->show();

//    return app.exec();
//}

//#include <QProgressBar>

//int main(int argc, char **argv)
//{
//    QApplication app(argc, argv);

//    QProgressBar *pb = new QProgressBar();
//    pb->setRange(0,60);
//    pb->setValue(20);
//   // pb->setInvertedAppearance(true);
//    pb->show();

//    return app.exec();
//}

//=======================================
//#include <QTimer>

//int main(int argc, char **argv)
//{
//    QApplication app(argc, argv);

//    QProgressBar *proBar = new QProgressBar();
//    //proBar->
////    pb->setRange(0,60);
////    pb->setValue(20);
////    pb->setInvertedAppearance(true);
////    pb->show();

//    return app.exec();
//}
//============================

//#include <QTextBrowser>
//#include <QUrl>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QTextBrowser *tb = new QTextBrowser();
//    tb->setSource(QUrl("index.html"));
//    tb->show();

//    return a.exec();
//}
//=====================================

#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton *pushButton = new QPushButton("Push&Button",0);
    QObject::connect(pushButton, SIGNAL(clicked()),&a,SLOT(quit()));
    pushButton->show();

    return a.exec();
}
