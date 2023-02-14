#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calibration.h"
#include "stitching.h"
#include <QTableWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Pre-Precessing");

    calibration = new Calibration(this);
    stitching = new Stitching(this);
    stitching -> setWindowTitle("Stitching");

    /* calibration, stitching tab widget 추가 */
    ui->tabWidget->addTab(calibration, "Calibration");
    ui->tabWidget->addTab(stitching, "Stitching");
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

}

MainWindow::~MainWindow()
{

    delete ui;
}


