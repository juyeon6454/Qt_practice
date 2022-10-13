#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleSpinBox>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scratchPad = new ScratchPad(ui->tabWidget);                                           //멤버변수로 선언
    ui->tabWidget->addTab(m_scratchPad, tr("Scratch Pad"));                                 //QTabWidget::addTab(QWidget *page, const QString &label)
    ui->actionsave->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));            //actionsave ui에 아이콘 설정
    ui->actioncolor->setIcon(style()->standardIcon(QStyle::SP_DriveCDIcon));                //actioncolor ui에 아이콘 설정

    QDoubleSpinBox* spinBox = new QDoubleSpinBox(this);                                     //선 굵기를 spinBox에 표현
    spinBox->setValue(10.0f);                                                               //spinBox에 표현되는 paintSize 값을 설정해줌
    connect(spinBox, SIGNAL(valueChanged(double)),m_scratchPad, SLOT(setPaintSize(qreal))); //spinBox에서 값을 변화시키면 scratchPad에서 선의 굵기를 새로 넣어줌
    ui->toolBar->addWidget(spinBox);                                                        //ui toolBar에 spinbox 추가
    resize(1024, 800);                                                                      //처음 보여지는 창크기
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionsave_triggered()
{
    m_scratchPad->saveImage();                 //scartchpad image 저장 액션
}

void MainWindow::on_actioncolor_triggered()
{
    m_scratchPad->setPaintColor();             //scartchpad 색상 변경 액션
}

