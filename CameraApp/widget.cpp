#include "widget.h"

#include <QVideoWidget>
#include <QMediaDevices>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QMediaRecorder>
#include <QAudioInput>
#include <QCamera>
#include <QUrl>
#include <QPushButton>
#include <QBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs( );
    for (const QCameraDevice &cameraDevice : cameras) {
        qDebug( ) << cameraDevice.description( );
    }

    camera = new QCamera(QMediaDevices::defaultVideoInput( ));
    QMediaCaptureSession captureSession;
    captureSession.setCamera(camera);
    QAudioInput audioInput;
    //session.setAudioInput(&input);
    captureSession.setAudioInput(&audioInput);

    QVideoWidget *preview = new QVideoWidget(this);
    preview->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    captureSession.setVideoOutput(preview);

    QPushButton* imageButton = new QPushButton("Image", this);
    connect(imageButton, SIGNAL(clicked( )), SLOT(captureImage( )));
    QPushButton* videoButton = new QPushButton("Video", this);
    connect(videoButton, SIGNAL(clicked( )), SLOT(recordVideo( )));

    QHBoxLayout* hboxLayout = new QHBoxLayout;
    hboxLayout->addWidget(imageButton);
    hboxLayout->addWidget(videoButton);

    QVBoxLayout* vboxLayout = new QVBoxLayout(this);
    vboxLayout->addWidget(preview);
    vboxLayout->addLayout(hboxLayout);

    imageCapture = new QImageCapture( );
    captureSession.setImageCapture(imageCapture);

    recorder = new QMediaRecorder(camera);
    recorder->setQuality(QMediaRecorder::HighQuality);
    recorder->setOutputLocation(QUrl(QString("test.mp4")));
    captureSession.setRecorder(recorder);

    camera->start( ); // 카메라의 프리뷰 시작
    preview->resize(preview->sizeHint( ));
}

void Widget::captureImage( ) {
    imageCapture->captureToFile("capture.jpg");
}

void Widget::recordVideo( ) {
    recorder->record( );
}


Widget::~Widget()
{
}

//#include "widget.h"
//#include <QCameraViewfinder>
//#include <QCamera>

//Widget::Widget(QWidget *parent)
//    : QWidget(parent)
//{

//    camera=new QCamera(this);
//    QCameraViewfinder *viewfinder = new QCameraViewfinder(this);
//    viewfinder->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
//    camera->setViewfinder(viewfinder);

//    imageCapture=new QCameraImageCapture(camera);
//    recorder=new QMediaRecorder(camera);
//    recorder->setOutputLocation(QUrl(QString("test.mp4")));
//    camera->start();//카메라의 프리뷰 시작
//    viewfinder->resize(viewfinder->sizeHint());

//}

//Widget::captureImage(){
//    camera->searchAndLock();//카메라 화면을 잠시 정리
//    camera->setCaptureModel(QCamera::CaptureStillImage);
//    imageCapture->capture("capture.jpg");
//    camera->unlock();
//}

//Widget::recordVideo(){
//    camera->setCaptureMode(QCamera::CaptureVideo);
//    recorder->record();
//}

//Widget::~Widget()
//{
//}
