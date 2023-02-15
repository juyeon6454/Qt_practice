#ifndef STITCHING_H
#define STITCHING_H

#include <QWidget>
#include <QProcess>
#include <QProgressDialog>

namespace Ui {
class Stitching;
}

class Stitching : public QWidget
{
    Q_OBJECT        // signal_slot을 위한 Q_OBJECT 상속

public:
    explicit Stitching(QWidget *parent = nullptr);  // 생성자
    ~Stitching();                                   // 소멸자

private:
    Ui::Stitching *ui;
    QProcess* process;  // process 생성
    QProgressDialog* dialog;    //progressdialog 생성

private slots:
    int on_stitchingPushButton_clicked();   // 정합 시작
    void on_clearPushButton_clicked();      // LineEdit에 있는 내용 지움
    void on_filePathPushButton_clicked();   // 파일 탐색기로 경로 찾음
};


#endif // STITCHING_H
