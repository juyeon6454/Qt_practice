#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Calibration;
class Stitching;

class MainWindow : public QMainWindow
{
    Q_OBJECT    // signal_slot을 위한 Q_OBJECT 상속

public:
    MainWindow(QWidget *parent = nullptr);  // 생성자
    ~MainWindow();                          // 소멸자

    Calibration *calibration;
    Stitching *stitching;

private:
    Ui::MainWindow *ui;

private slots:

};
#endif // MAINWINDOW_H
