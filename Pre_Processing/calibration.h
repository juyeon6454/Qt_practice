#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QWidget>

namespace Ui {
class Calibration;
}

class Calibration : public QWidget
{
    Q_OBJECT    // signal_slot을 위한 Q_OBJECT 상속

public:
    explicit Calibration(QWidget *parent = nullptr);    // 생성자
    ~Calibration();                                     // 소멸자

private:
    Ui::Calibration *ui;

private slots:        
    int on_calibrationPushButton_clicked();             // LOAD 버튼 누를 때 실행
    void on_clearPushButton_clicked();                  // CLEAR 버튼을 눌러 LineEdit 비움
    void on_sizeComboBox_activated(int index);          // calibration 할 Panorama, Cephalo 옵션 선택
    void on_calibrationComboBox_activated(int index);   // dark calibration, gain calibration 옵션 선택
    void on_rawFilePathPushButton_clicked();            // 원본 파일의 경로 설정
    void on_darkFilePathPushButton_clicked();           // dark frame 경로 설정
    void on_gainFilePathPushButton_clicked();           // gain frame 경로 설정
};

#endif // CALIBRATION_H
