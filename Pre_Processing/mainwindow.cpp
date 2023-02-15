#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calibration.h"
#include "stitching.h"
#include <QTableWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);                  // ui 파일이 만들어짐 (this) 현재 class에 ui 파일 올림
    setWindowTitle("Pre-Precessing");   // windowtitle 설정

    calibration = new Calibration(this);
    stitching = new Stitching(this);

    /* calibration, stitching tab widget 추가 및 순서, 크기 설정  */
    ui->tabWidget->addTab(calibration, "Calibration");
    ui->tabWidget->addTab(stitching, "Stitching");
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

}

MainWindow::~MainWindow()
{
    delete ui;              // ui delete
}


