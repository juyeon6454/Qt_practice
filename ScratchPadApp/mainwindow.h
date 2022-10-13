#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "scratchpad.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT                                     //slot을 사용

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actioncolor_triggered();             //색상 변경을 위한 action
    void on_actionsave_triggered();              //저장을 위한 action


private:
    Ui::MainWindow *ui;
    ScratchPad *m_scratchPad;                    //멤버변수로 선언
};
#endif // MAINWINDOW_H



//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//#include "scratchpad.h"
//#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT    //slot을 사용하기 위해 Q_OBJECT로 상속

//public:
//    MainWindow(QWidget *parent = nullptr); //생성자
//    ~MainWindow();  //소멸자

//private slots:
//    void on_actioncolor_triggered();    //color를 action과 연결 (triggered)
//    void on_actionsave_triggered();     //save를 action과 연결 (triggered)


//private:
//    Ui::MainWindow *ui;

//    ScratchPad *m_scratchPad; //멤버변수로 선언
//};
//#endif // MAINWINDOW_H

