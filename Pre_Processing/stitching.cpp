#include "stitching.h"
#include "ui_stitching.h"
#include <QProcess>
#include <QLabel>
#include <QImage>
#include <QFile>
#include <QFileDialog>
#include <QValidator>
#include <QDebug>
#include <QMessageBox>
#include <QDataStream>

Stitching::Stitching(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stitching)
{
    ui->setupUi(this);

    /* splitter의 기본 사이즈 조절 */
    QList<int> sizes;
    sizes<< 600 << 300;
    ui->splitter->setSizes(sizes);

    resize(1000,600);
}

Stitching::~Stitching()
{
    delete ui;    // ui delete
}


int Stitching::on_stitchingPushButton_clicked()
{
    /* 실행할 파일 경로를 변수로 지정 */
    QString panoPath = "C:/calibration_mentoring/exe_Pano/Regi_Based_EXE.exe";
    QString cephPath = "C:/calibration_mentoring/exe_Ceph/CephImgProc.exe";

    /* lineEdit으로 받아온 변수를 실행파일 명령인자로 넣어줌 */
    QStringList panoArgs;
    QStringList cephArgs;
    panoArgs << "sensor=3" << "exe_test_frame_path="+ui->filePathLineEdit->text();
    cephArgs << "DEVICE=T1" << "SENSOR=XID-C24DC" <<  "PATH="+ui->filePathLineEdit->text() << "FileNameFormat=%04d.raw";

    process = new QProcess(this);   //프로세스 생성

//    // Show the custom dialog widget
//    if(ui->filePathLineEdit!=nullptr){
//        dialog = new QProgressDialog("stitching,,,","Cancel",0,100, this);
//        dialog->setWindowModality(Qt::WindowModal);
//        dialog->setMinimumDuration(10);
//        dialog->setModal(true);
//        dialog->show();
//    }


    /* panorama radiobutton 클릭시 panorma 정합 파일 실행 */
    if(ui->panoRadioButton->isChecked()){

        process->start(panoPath,panoArgs);

        std::string _workingPath = (panoPath.toStdString()).substr(0, (panoPath.toStdString()).find_last_of('/'));
        process->setWorkingDirectory(QString::fromStdString(_workingPath));
    }

    /* cephalo radiobutton 클릭시 cephalo 정합 파일 실행 */
    else if(ui->cephRadioButton->isChecked()){

        process->start(cephPath,cephArgs);

        std::string _workingPath = (cephPath.toStdString()).substr(0, (cephPath.toStdString()).find_last_of('/'));
        process->setWorkingDirectory(QString::fromStdString(_workingPath));
    }



    /* 외부 프로그램 실행 후 바로 현재 프로그램의 이후 코드 진행 (외부와 현재 코드 병렬 실행시)
    * wait for the process to start */
    if (!process->waitForStarted()) {
        qDebug() << "Could not start process.";
        QMessageBox::information(this, "Calibration", "Please enter again");
        return 1;
    }

    /* Check if the process is running */
    if (process->state() == QProcess::Running) {
       qDebug() << "The process is running.";
    } else {
       qDebug() << "The process is not running.";
    }

    /* Wait for the process to finish */
    if (process->waitForFinished(10000) == false) {
        qDebug() << process->error();
        qDebug() << "The process failed  process->errorString();to finish:" <<
        QMessageBox::information(this, "Calibration", "The process is finally complete.");
    }


 /* raw 파일 image를 변환해서 Label에 출력 */
    QFile *file;    //파일 생성

    if(ui->cephRadioButton->isChecked())
    {
        //QString fileName = "C://calibration_mentoring//exe_Ceph//Ceph_ImgProged.raw";
        QString fileName = "./Ceph_ImgProged.raw";
        QString bmpPath = ui->filePathLineEdit->text()+"_Ceph_ImgProged.bmp";

        /* 파일이 존재할시 */
        if(fileName.length()) {
            /* file open */
            file = new QFile(fileName);
            file->open(QFile::ReadOnly);

            /* byteArray로 file을 읽음 */
            QByteArray byteArray;
            byteArray = file->readAll();

            /* byteArray size의 unsigned char 타입의 data 배열 선언 */
            unsigned char* data = new unsigned char[ byteArray.size() ];
            /* data 배열에 byteArray에 담긴 data를 byteArray size 만큼 복사 */
            memcpy( data, byteArray.data(), byteArray.size() );

            /* data를 해당 크기만큼 gray 16bit 형식으로 열어줌 */
            QImage image;
            QImage *temp = new QImage(data, 3000, 2400,QImage::Format_Grayscale16);
            image = *temp;

            /* 열어준 image를 bmp형식으로 저장해줌 */
            image.save(bmpPath, "BMP");
            QPixmap bmpImage;
            bmpImage = QPixmap(bmpPath);

            /* label에 비율 맞춰서 image 띄움 */
            ui->viewLabel->setPixmap(bmpImage.scaled(700, 650, Qt::KeepAspectRatio));
            ui->viewLabel->show();

            ui-> resultLabel->setText(fileName);
        }
    }

        if(ui->panoRadioButton->isChecked()){

            QString fileName = "./_calibration_mentoring_pano_SkullResult_u16_post_d1_p7.raw";
            QString bmpPath = ui->filePathLineEdit->text()+"_Pano_Stitched.bmp";

            /* 파일이 존재할시 */
            if(fileName.length()) {
                /* file open */
                file = new QFile(fileName);
                file->open(QFile::ReadOnly);

                /* byteArray로 file을 읽음 */
                QByteArray byteArray;
                byteArray = file->readAll();

                /* byteArray size의 unsigned char 타입의 data 배열 선언 */
                unsigned char* data = new unsigned char[ byteArray.size() ];
                /* data 배열에 byteArray에 담긴 data를 byteArray size 만큼 복사 */
                memcpy( data, byteArray.data(), byteArray.size() );

                /* data를 해당 크기만큼 gray 16bit 형식으로 열어줌 */
                QImage image;
                QImage *temp = new QImage(data, 3000, 1628,QImage::Format_Grayscale16);
                image = *temp;

                /* 열어준 image를 bmp형식으로 저장해줌 */
                image.save(bmpPath, "BMP");
                QPixmap bmpImage;
                bmpImage = QPixmap(bmpPath);

                /* label에 비율 맞춰서 image 띄움 */
                ui->viewLabel->setPixmap(bmpImage.scaled(800, 400, Qt::IgnoreAspectRatio));
                ui->viewLabel->show();
                ui-> resultLabel->setText(fileName);
            }
        }
    return 0;

}

/* lineEdit에 있는 text를 비움 */
void Stitching::on_clearPushButton_clicked()
{
    ui->filePathLineEdit->clear();
    ui->viewLabel->clear();
    ui->resultLabel->clear();
}

/* button을 눌러서 파일 탐색기로 경로를 지정 */
void Stitching::on_filePathPushButton_clicked()
{
    QString searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", "C://calibration_mentoring" ,QFileDialog::ShowDirsOnly);
    qDebug() << searchLocation;
    ui->filePathLineEdit->setText(searchLocation);
}

