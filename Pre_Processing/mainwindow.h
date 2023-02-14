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
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Calibration *calibration;
    Stitching *stitching;

private slots:


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
