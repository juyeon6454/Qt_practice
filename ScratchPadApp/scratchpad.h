#ifndef SCRATCHPAD_H
#define SCRATCHPAD_H

#include <QWidget>

class ScratchPad : public QWidget
{
    Q_OBJECT                                                    //slots을 사용
public:
    explicit ScratchPad(QWidget *parent = nullptr);             //explicit : 자유로운 형변환을 막기 위함


protected:                                                      //이벤트 핸들러 추가
    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;         //화면에 이미지를 드로잉
    void resizeEvent(QResizeEvent *event)Q_DECL_OVERRIDE;       //mainwindow창 크기 변화에 따른 image 크기 변화
                                                                //Q_DECL_OVERRIDE : 선언된 함수가 실제 오버라이딩 하고 있는지 검사
    void mousePressEvent(QMouseEvent* event)Q_DECL_OVERRIDE;    //마우스를 눌렀을 때 발생하는 event
    void mouseMoveEvent(QMouseEvent* event)Q_DECL_OVERRIDE;     //마우스를 움직일 때 발생하는 event
    void mouseReleaseEvent(QMouseEvent* event)Q_DECL_OVERRIDE;  //마우스를 뗐을 때 발생하는 event


private:
    void resizeImage(QImage *image, const QSize &newSize);      //이미지를 주면 새 이미지를 만들어줌

    bool modified;                                              /*버튼이 눌렸는지 확인하는 변수 : 드로잉시 사용
                                                                눌리지 않았을 때 false 눌렸을 때 true*/
    QImage image;                                               //그림을 그리는데 사용하는 버퍼 이미지
    QPointF prevPos;                                            //선을 그릴 때 이전 점의 위치를 기억하는 변수
    QColor paintColor;                                          //색상을 기억하는 변수
    qreal paintSize;                                            //선의 크기를 기억하는 변수


signals:

public slots:
    void setPaintColor();                                       //QColorDialog를 이용한 선 색상 변경
    void saveImage();                                           //image 저장 (현재 날짜/시간 정보로 파일명 설정)
    void setPaintSize(qreal size);                              //선의 굵기

};

#endif // SCRATCHPAD_H


//#ifndef SCRATCHPAD_H
//#define SCRATCHPAD_H

//#include <QWidget>

//class ScratchPad : public QWidget
//{
//    Q_OBJECT    //slots을 사용하기 위해 Q_OBJECT를 상속받음
//public:
//    explicit ScratchPad(QWidget *parent = nullptr); //explicit 자유로운 형변환을 막기 위해
//    qreal paintSize;//선의 크기를 기억하는 변수

//protected://이벤트 핸들러를 추가//scratchpa에 오버라이딩 된 함수들이니까 widget을 상속받음
//    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;// 선언된 함수가 실제 오버라이딩 하고 있는지 검사
//    void resizeEvent(QResizeEvent *event)Q_DECL_OVERRIDE;

//    void mousePressEvent(QMouseEvent* event)Q_DECL_OVERRIDE;//마우스를 눌렀을 때 (점 찍어준다?)
//    void mouseMoveEvent(QMouseEvent* event)Q_DECL_OVERRIDE;
//    void mouseReleaseEvent(QMouseEvent* event)Q_DECL_OVERRIDE;//마우스를 똈을때

//private:
//    void resizeImage(QImage *image, const QSize &newSize);//이미지를 주면 새 이미지를 만들어줌

//    bool modified;  //버튼이 눌렸는지 확인하는 변수 : 드로잉시 사용 -> 안 눌렸을 때 false 눌리면 true
//    QImage image;   //그림을 그리는데 사용하는 버퍼 이미지
//    QPointF prevPos;//선을 그릴 때 이전 점의 위치를 기억하는 변수
//    QColor paintColor;//선의 크기를 기억하는 변수


//signals:

//public slots:
//    void setPaintColor();   //글자 color 변경
//    void saveImage();       //image 저장
//    void setPaintSize(qreal size);//글자 size 변경

//};

//#endif // SCRATCHPAD_H


