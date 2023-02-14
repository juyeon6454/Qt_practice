#include "stitching.h"
#include "ui_stitching.h"
#include <QProcess>
#include <QLabel>
#include <QImage>
#include <QFile>
#include <QFileDialog>
#include <QValidator>
#include <QDebug>
#include <QDataStream>
#include <QMessageBox>
#include <QTimer>
#include <QThread>

Stitching::Stitching(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stitching)
{
    ui->setupUi(this);

    /* splitter의 기본 사이즈 조절 */
    QList<int> sizes;
    sizes<<600 << 300;
    ui->splitter->setSizes(sizes);

    /* width, height lineEdit에 숫자만 입력 받음 */
    QIntValidator* intValidator = new QIntValidator;
    //ui->width_lineEdit_2->setValidator(intValidator);
    ui->height_lineEdit_2->setValidator(intValidator);

    resize(1000,600);

}

Stitching::~Stitching()
{
    delete ui;
}

int Stitching::on_Stitching_pushButton_clicked()
{

    /* lineEdit에서 받아온 경로, 해상도를 변수로 지정 */
    //QString file_path = "PATH=" + ui->path_lineEdit_2->text();
    //int width = ui->width_lineEdit_2->text().toInt();
    //int height = ui->height_lineEdit_2->text().toInt();

    /* lineEdit으로 받아온 변수를 실행파일 명령인자로 넣어줌 */
   // QProcess process;
    QStringList args;
     args << "DEVICE=T1" << "SENSOR=XID-C24DC" << "PATH=C:/calibration_mentoring/Ceph/Human1" << "FileNameFormat=%04d.raw";

         //<< QString::number(width) << QString::number(height) ;
   // process.start("C:/calibration_mentoring/exe_Ceph/CephImgProc.exe");

   // QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
   // env.insert("TMPDIR", "C:/calibration_mentoring/exe_Ceph"); // Add an environment variable
    //process.setProcessEnvironment(env);
    //QString word = process.readAllStandardOutput();
    //process.start("./exe_Ceph/CephImgProc.exe",args);

       QProcess *process = new QProcess();
       process->start("C:/calibration_mentoring/exe_Ceph/CephImgProc.exe",args);


       // wait for the process to start
       if (!process->waitForStarted()) {
           qDebug() << "Could not start process.";
           return 1;
       }

//       // wait for a certain amount of time
//       QThread::sleep(20);


       // write a newline to the process's standard input
//       QTextStream stream(process);
//       stream << Qt::endl;


//       // print the output of the process
//       qDebug() << process->readAll();
//       // terminate the process
//       process->terminate();


       // Check if the process is running
       if (process->state() == QProcess::Running) {
           qDebug() << "The process is running.";
       } else {
           qDebug() << "The process is not running.";
       }

       // Wait for the process to finish
       if (!process->waitForFinished()) {
           qDebug() << "The process failed to finish:" << process->errorString();
           return 1;
       }

       qDebug() << "The process finished successfully with exit code:" << process->exitCode();

       // wait for the process to finish
       if (!process->waitForFinished(50000)) {
           qDebug() << "Could not wait for process to finish.";
           return 1;
       }

      // process->waitForStarted();

       //qDebug() << "Process started, PID:";

       // Terminate the process after 5 seconds
       //QTimer::singleShot(50000, [process] {
           //if (process->state() == QProcess::Running) {
                       //qDebug() << "Process running for too long, forcing termination";
                       //process->kill();
                       //process->waitForFinished();
                   //}

           //qDebug() << "Process finished with exit code:" << process->exitCode();
       //});

          //process->waitForFinished();

          // return process->exec(
           //return process->kill();
           //return process->terminate();
       ////
       ///
       ///
//       process->waitForStarted();

//       qDebug() << "Process started, PID:" ;

//       // Terminate the process after 5 seconds
//       //QThread::sleep(40);
//       process->start(40000);
//       process->terminate();
//       //process->kill();
//      // process->waitForFinished();

//       qDebug() << "Process finished with exit code:" << process->exitCode();

       //return 0;

//    QTimer *killtimer = new QTimer(process);
//    killtimer->setTimeout(30000); // 5 seconds
//    killtimer->setSingleShot(true); // should happen only once per process start

//    // make the timer's timeout to terminate the process
//    killtimer->connect(killtimer->timeout(),process.terminate());



    /* 외부 프로그램 실행 후 바로 현재 프로그램의 이후 코드 진행 (외부와 현재 코드 병렬 실행시)*/
//    if (!process.waitForStarted(-1))
//    {
//    qDebug() << "Failed to start the process.";
//    return 1;
//    }
   // process.waitForReadyRead ();

    //process.killTimer();

//    if (!process.waitForFinished(30000))
//    {
//    qDebug() << "The process failed to finish.";
//    return 1;
//    }

    //process.kill();
    //process.terminate();

//    /* 성공적인 종료시 exitCode 0 */
//    if(process.exitCode()==0)
//    {
//    qDebug() << "Process finished with exit code:" << process.exitCode();
//    QMessageBox::information(this, "Calibration", "The process is finally complete.");
//    }


    /* lineEdit에서 받아온 경로, 해상도를 변수로 지정 */
    //QString raw_path = ui->path_lineEdit_2->text() + "/Result/result.raw";
    //QString bmp_path = ui->path_lineEdit_2->text() + "/Result/result2.bmp";
    /* test하기 위해서 파일 탐색기로 raw 파일 받아옴 (나중에 경로 지정해서 삭제) */
    //QString filename = QFileDialog::getOpenFileName(this, "Open file", "C:\\Users\\KOSA\\OneDrive\\바탕 화면");
    //QString filename = "C:/calibration_mentoring/exe_Ceph/Ceph_Stitched.raw";
    //QString bmp_path = "C:/calibration_mentoring/exe_Ceph/Ceph_Stitched.bmp";


// /* raw 파일 image를 변환해서 Label에 출력 */
//    QFile *file;

//    /* 파일이 존재할시 */
//    if(filename.length()) {
//        /* file open */
//        file = new QFile(filename);
//        file->open(QFile::ReadOnly);

//        /* byteArray로 file을 읽음 */
//        QByteArray byteArray;
//        byteArray = file->readAll();

//        /* byteArray size의 unsigned char 타입의 data 배열 선언 */
//        unsigned char* data = new unsigned char[ byteArray.size() ];
//        /* data 배열에 byteArray에 담긴 data를 byteArray size 만큼 복사 */
//        memcpy( data, byteArray.data(), byteArray.size() );

//        /* data를 해당 크기만큼 gray 16bit 형식으로 열어줌 */
//        QImage image;
//        QImage *temp = new QImage(data, 3000, 2400,QImage::Format_Grayscale16);
//        image = *temp;

//        /* 열어준 image를 bmp형식으로 저장해줌 */
//        image.save(bmp_path, "BMP");
//        QPixmap bmp_image;
//        bmp_image = QPixmap(bmp_path);

//        /* label에 비율 맞춰서 image 띄움 */
//        ui->View_label->setPixmap(bmp_image.scaled(800, 800, Qt::KeepAspectRatio));
//        //ui->View_label->setPixmap(QPixmap::fromImage(bmp_image).scaled(800, 800, Qt::KeepAspectRatio));
//        ui->View_label->show();

//        /* stitching 된 파일 경로를 띄워줌 (원래 전송하기 위해서 만들었음 - 삭제)*/
//        //ui->send_label->setText(raw_path);
//    }




/* raw 파일 이미지를 bmp로 변환해서 출력 (x) */

//    QFile file(raw_path);
//    if (!file.open(QFile::ReadOnly)){
//        qDebug("Could not open file");
//    } else {
//        qDebug() << file.fileName() << " opened";
//    }

//    QByteArray array =file.readAll();
//    unsigned char* Data = (unsigned char*)&array.data()[0];
//    QImage raw_image(Data,3693,1628,QImage::Format_Grayscale16);

//    //QImage raw_image(raw_path);
//    if (raw_image.isNull()){
//      qDebug() << "Failed to load the image.";
//      return 1;
//    }

//    // Copy the raw data into the image
//    memcpy(raw_image.bits(), array.constData(), array.size());
//    raw_image.save(bmp_path, "BMP");

//    QPixmap bmp_image;
//    bmp_image = QPixmap(bmp_path);

//    ui->View_label->setPixmap(bmp_image.scaled(3693, 1628, Qt::KeepAspectRatio));
//    ui->View_label->setPixmap(QPixmap::fromImage(raw_image).scaled(800, 800, Qt::KeepAspectRatio));
//    ui->View_label->show();
//    ui->send_label->setText(raw_path);

//    QString filename = QFileDialog::getOpenFileName(this, "Open file", "C:\\Users\\KOSA\\OneDrive\\바탕 화면");
//    QPixmap pixmap;
//    QFile *file;
//    QImage image(3000, 1628, QImage::Format_Grayscale16);

//    if(filename.length()) {          // 파일이 존재한다면
//        file = new QFile(filename);
//        file->open(QFile::ReadOnly);

//        QByteArray byteArray;
//        byteArray = file->readAll();

//        QImage image(3000, 1628, QImage::Format_RGB32);

//       // unsigned char* data = new unsigned char[ byteArray.size() ];
//        memcpy(image.bits(), byteArray.data(), byteArray.size());

//            // Convert the image to 8-bit grayscale format
//        image.convertToFormat(QImage::Format_Grayscale8);

//        //image.convertToFormat(QImage::Format_Indexed8);
//        image.save(bmp_path, "BMP");

//        ui->View_label->setPixmap(QPixmap::fromImage(image).scaled(800, 800, Qt::KeepAspectRatio));
//        ui->View_label->show();

//    }

//    return;

}


void Stitching::on_path_pushButton_2_clicked()
{
    /* button을 눌러서 파일 탐색기로 경로를 지정 */
    QString searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", QDir::homePath(),QFileDialog::ShowDirsOnly);
    qDebug() << searchLocation;
    ui->path_lineEdit_2->setText(searchLocation);
}




void Stitching::on_Clear_pushButton_2_clicked()
{
    /* lineEdit에 있는 text를 비움 */
    ui->path_lineEdit_2->clear();
    ui->width_lineEdit_2->clear();
    ui->height_lineEdit_2->clear();
}

