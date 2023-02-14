#include "calibration.h"
#include "ui_calibration.h"
#include <QProcess>
#include <QLabel>
#include <QImage>
#include <QFile>
#include <QFileDialog>
#include <QValidator>
#include <QMessageBox>

/* 생성자 */
Calibration::Calibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calibration)
{
    ui->setupUi(this);

    /* width, height lineEdit에 숫자만 입력받도록 제한*/
    QIntValidator* intValidator = new QIntValidator;
    ui->width_LineEdit->setValidator(intValidator);
    ui->height_LineEdit->setValidator(intValidator);

    resize(1000,600);
}

/* 소멸자 */
Calibration::~Calibration()
{
    delete ui;
}

/* calibration push button 눌렀을 때 */
int Calibration::on_Calibration_pushButton_clicked()
{

    /* lineEdit에 입력받은 내용을 변수로 지정 */
    QString raw_Filepath = ui->raw_Filepath_LineEdit->text();
    QString dark_Filepath = ui->dark_Filepath_LineEdit->text();
    QString gain_Filepath = ui->gain_Filepath_LineEdit->text();
    int width = ui->width_LineEdit->text().toInt();
    int height = ui->height_LineEdit->text().toInt();

    /* lineEdit에 내용이 없으면 파일이 없다는 메세지 박스 알림 */
    if(ui->raw_Filepath_LineEdit==nullptr){
        QMessageBox::critical(this, tr("Calibration_Filepath"),
                              tr("No File"));
    }
    if(ui->dark_Filepath_LineEdit==nullptr){
        QMessageBox::critical(this, tr("Dark_Filepath"),
                              tr("No File"));
    }

    /* lineEdit으로 받아온 변수를 실행파일 명령인자로 넣어줌 */
    QProcess process;
    QStringList dark_args;
    dark_args << raw_Filepath << dark_Filepath << QString::number(width) << QString::number(height) ;

    QStringList gain_args;
    gain_args << raw_Filepath << dark_Filepath << gain_Filepath << QString::number(width) << QString::number(height) ;

    /* combobox index에 따라 실행되는 파일이 달라짐 */
    if(ui->calibration_comboBox->currentIndex()==0){
        qDebug() << "00000";
    process.start("C:\\CudaRuntime1\\x64\\Release\\CudaRuntime1.exe", dark_args);
    }
    else if(ui->calibration_comboBox->currentIndex()==1){
        qDebug() << "1111";
    process.start("C:\\Gain_Calibration\\x64\\Release\\Gain_Calibration.exe", gain_args);
    }

    /* 외부 프로그램 실행 후 바로 현재 프로그램의 이후 코드 진행 (외부와 현재 코드 병렬 실행시)*/
    if (!process.waitForStarted()){
    qDebug() << "Failed to start the process.";
    QMessageBox::critical(this, tr("Calibration"),
                          tr("Failed to start the process."));
    return 1;
    }

    /* 외부 프로그램 종료 시까지 waitForFinished() 함수에서 블로킹 */
    if (!process.waitForFinished())
    {
    qDebug() << "The process failed to finish.";

    QMessageBox::critical(this, tr("Calibration"),
                          tr("The process failed to finish."));
    return 1;
    }

    /* list widget에 calibration 된 결과 파일들 목록을 띄움 */
    QDir dir(raw_Filepath + "Result/");
    foreach(QFileInfo item, dir.entryInfoList()){
        if(item.isFile()){
            ui->path_listWidget->insertItem(0,item.absoluteFilePath());
            //ui->path_listWidget->addItems(item.absoluteFilePath());
        }
    }

    /* 성공적인 종료시 exitCode 0 */
    if(process.exitCode()==0){
    qDebug() << "Process finished with exit code:" << process.exitCode();
    QMessageBox::information(this, "Calibration", "The process is finally complete.");
    }
    return 0;

}

/* lineEdit에 있는 내용들을 clear해줌 */
void Calibration::on_Clear_pushButton_clicked()
{
    //칸 다 비어있을 때 예외처리 해주기
    /* lineEdit text clear(); */
    ui->raw_Filepath_LineEdit->clear();
    ui->dark_Filepath_LineEdit->clear();
    ui->gain_Filepath_LineEdit->clear();
    ui->width_LineEdit->clear();
    ui->height_LineEdit->clear();
    ui->path_listWidget->clear();
}

/* pano 선택시 80-1628, ceph 선택시 80-2400 */
void Calibration::on_size_comboBox_activated(int index)
{
    /* paanorama */
    if(index==0){
    ui->width_LineEdit->setText("80");
    ui->height_LineEdit->setText("1628");
    ui->gain_Filepath_LineEdit->clear();
    }
    /* ceph */
    if(index==1){
    ui->width_LineEdit->setText("80");
    ui->height_LineEdit->setText("2400");
    }
}

/* combobox에서 dark calibration 선택시
 * gain 경로 입력 lineEdit에 내용을 입력하지 못하게 설정
   gain calibration 선택시 다시 입력 가능하도록 설정 */
void Calibration::on_calibration_comboBox_activated(int index)
{
    if(index==0){
        ui->gain_Filepath_LineEdit->setReadOnly(true);
    }
    else{
        ui->gain_Filepath_LineEdit->setReadOnly(false);
    }

}

/* PathButton을 누르면 파일 탐색기로 경로를 지정할 수 있도록 설정 */
void Calibration::on_raw_Filepath_pushButton_clicked()
{
    QString raw_searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", QDir::homePath(),QFileDialog::ShowDirsOnly);
    qDebug() << raw_searchLocation;
    ui->raw_Filepath_LineEdit->setText(raw_searchLocation);
}

/* PathButton을 누르면 파일 탐색기로 경로를 지정할 수 있도록 설정 */
void Calibration::on_dark_Filepath_PushButton_clicked()
{
    QString dark_searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", QDir::homePath(),QFileDialog::ShowDirsOnly);
    qDebug() << dark_searchLocation;
    ui->dark_Filepath_LineEdit->setText(dark_searchLocation);
}

/* PathButton을 누르면 파일 탐색기로 경로를 지정할 수 있도록 설정 */
void Calibration::on_gain_Filepath_pushButton_clicked()
{

    if(ui->calibration_comboBox->currentIndex()==1){
    /* PathButton을 누르면 파일 탐색기로 경로를 지정 */
    QString gain_searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", QDir::homePath(),QFileDialog::ShowDirsOnly);
    qDebug() << gain_searchLocation;
    ui->gain_Filepath_LineEdit->setText(gain_searchLocation);

    /* dark calibration이 설정되어 있을 때, 파일 탐색기 기능을 사용하려고 할 때 메세지 박스로 알림 */
        if(ui->calibration_comboBox->currentIndex()==0){
        QMessageBox::critical(this, tr("Dark_Filepath"),
                              tr("Change to Options 'gain calibration'"));
        ui->gain_Filepath_LineEdit->clear();
        }
    }

}
