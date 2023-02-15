#include "calibration.h"
#include "ui_calibration.h"
#include <QProcess>
#include <QLabel>
#include <QImage>
#include <QFile>
#include <QFileDialog>
#include <QValidator>
#include <QMessageBox>
#include <QDialog>
/* 생성자 */
Calibration::Calibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calibration)
{
    ui->setupUi(this);

    /* width, height lineEdit에 숫자만 입력받도록 제한*/
    QIntValidator* intValidator = new QIntValidator;
    ui->widthLineEdit->setValidator(intValidator);
    ui->heightLineEdit->setValidator(intValidator);

    resize(1000,600);
}

/* 소멸자 */
Calibration::~Calibration()
{
    delete ui;       // ui delete
}

/* calibration push button 눌렀을 때 */
int Calibration::on_calibrationPushButton_clicked()
{
    /* lineEdit에 입력받은 내용을 변수로 지정 */
    QString rawFilepath = ui->rawFilePathLineEdit->text();
    QString darkFilepath = ui->darkFilePathLineEdit->text();
    QString gainFilepath = ui->gainFilePathLineEdit->text();
    int width = ui->widthLineEdit->text().toInt();
    int height = ui->heightLineEdit->text().toInt();

    /* lineEdit에 내용이 없으면 파일이 없다는 메세지 박스 알림 */
    if(ui->rawFilePathLineEdit==nullptr){
        QMessageBox::critical(this, "Calibration Filepath", "Please enter the path.");
    }
    if(ui->darkFilePathLineEdit==nullptr){
        QMessageBox::critical(this,"Dark Filepath","No File");
    }

    /* lineEdit으로 받아온 변수를 실행파일 명령인자로 넣어줌 */
    QProcess process;
    QStringList darkArgs;
    darkArgs << rawFilepath << darkFilepath << QString::number(width) << QString::number(height) ;
    QStringList gainArgs;
    gainArgs << rawFilepath << darkFilepath << gainFilepath << QString::number(width) << QString::number(height) ;

    /* dark calibration, gain calibration 선택에 따라 다른 파일 실행 */
    if(ui->calibrationComboBox->currentIndex()==0){
    process.start("C://Dark_output//x64//Release//cudaRuntime1.exe", darkArgs);
    }
    else if(ui->calibrationComboBox->currentIndex()==1){
    process.start("C:\\Gain_Calibration\\x64\\Release\\Gain_Calibration.exe", gainArgs);
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
    QDir dir(rawFilepath + "Result/");
    foreach(QFileInfo item, dir.entryInfoList()){
        if(item.isFile()){
            ui->pathListWidget->insertItem(0,item.absoluteFilePath());
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
void Calibration::on_clearPushButton_clicked()
{
    /* lineEdit text clear(); */
    ui->rawFilePathLineEdit->clear();
    ui->darkFilePathLineEdit->clear();
    ui->gainFilePathLineEdit->clear();
    ui->widthLineEdit->clear();
    ui->heightLineEdit->clear();
    ui->pathListWidget->clear();

}

/* pano 선택시 80-1628, ceph 선택시 80-2400 */
void Calibration::on_sizeComboBox_activated(int index)
{
    /* panorama */
    if(index==0){
    ui->widthLineEdit->setText("80");
    ui->heightLineEdit->setText("1628");
    ui->gainFilePathLineEdit->clear();
    }
    /* ceph */
    if(index==1){
    ui->widthLineEdit->setText("80");
    ui->heightLineEdit->setText("2400");
    }
}

/* combobox에서 dark calibration 선택시
 * gain 경로 입력 lineEdit에 내용을 입력하지 못하게 설정
   gain calibration 선택시 다시 입력 가능하도록 설정 */
void Calibration::on_calibrationComboBox_activated(int index)
{
    if(index==0){
        ui->gainFilePathLineEdit->setReadOnly(true);
    }
    else{
        ui->gainFilePathLineEdit->setReadOnly(false);
    }
}

/* PathButton을 누르면 파일 탐색기로 경로를 지정할 수 있도록 설정 */
void Calibration::on_rawFilePathPushButton_clicked()
{
    QString raw_searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", "C://calibration_mentoring//pano", QFileDialog::ShowDirsOnly);
    qDebug() << raw_searchLocation;
    ui->rawFilePathLineEdit->setText(raw_searchLocation);
}

/* PathButton을 누르면 파일 탐색기로 경로를 지정할 수 있도록 설정 */
void Calibration::on_darkFilePathPushButton_clicked()
{
    QString dark_searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", "C://calibration_mentoring//pano",QFileDialog::ShowDirsOnly);
    qDebug() << dark_searchLocation;
    ui->darkFilePathLineEdit->setText(dark_searchLocation);
}

/* PathButton을 누르면 파일 탐색기로 경로를 지정할 수 있도록 설정 */
void Calibration::on_gainFilePathPushButton_clicked()
{
    /* PathButton을 누르면 파일 탐색기로 경로를 지정 */
    if(ui->calibrationComboBox->currentIndex()==1){
    QString gain_searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", "C://calibration_mentoring//pano",QFileDialog::ShowDirsOnly);
    qDebug() << gain_searchLocation;
    ui->gainFilePathLineEdit->setText(gain_searchLocation);

    /* dark calibration이 설정되어 있을 때, 파일 탐색기 기능을 사용하려고 할 때 메세지 박스로 알림 */
        if(ui->calibrationComboBox->currentIndex()==0){
        QMessageBox::critical(this, tr("Dark_Filepath"),
                              tr("Change to Options 'gain calibration'"));
        ui->gainFilePathLineEdit->clear();
        }
    }
}

