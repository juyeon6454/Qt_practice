#include "mainwindow.h"

#include <QApplication>
//========================================================
//#include<QSPinBox>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QSpinBox *spinBox = new QSpinBox();
//    spinBox->setRange(0,100);
//    spinBox->setSuffix("%");
//    spinBox->setWrapping(true);
//    spinBox->setSpecialValueText("Percent");
//    spinBox->show();
//    return a.exec();
//}

//====================================================
//#include <QSlider>
//#include <QStyleFactory>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc,argv);

//    QSlider *slider = new QSlider();
//    slider->setOrientation(Qt::Horizontal);
//    slider->setTickPosition(QSlider::TicksAbove);
//    slider->setStyle(QStyleFactory::create("Fusion"));
//    slider->show();

//    return a.exec();
//}
//========================================================

//#include <QDial>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc,argv);

//    QDial *dial = new QDial();
//    dial->setWrapping(true);
//    dial->setNotchesVisible(true);
//    dial->setNotchTarget(10);
//    dial->show();

//    return a.exec();
//}

//========================================================
//#include <QTime>
//#include <QTimeEdit>
//#include <QDate>
//#include <QDateEdit>

//int main(int argc, char *argv[])
//{

//    QApplication a(argc,argv);

//    QTimeEdit* timeEdit = new QTimeEdit(0);
//    timeEdit->setTime(QTime::currentTime());
//    timeEdit->show();

//    QDateEdit* dateEdit = new QDateEdit(QDate::currentDate(),0);
//    dateEdit->setCalendarPopup(true);
//    dateEdit->show();

//    return a.exec();

//}
//===========================================================
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    lineEdit->setInputMask("099");
   // lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    lineEdit->setPlaceholderText("input thge number");
    lineEdit->show();

    return a.exec();

}
