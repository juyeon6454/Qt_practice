#include "scratchpad.h"

#include <QtWidgets>

ScratchPad::ScratchPad(QWidget *parent):                //ScratchPad가 QWidget을 상속
    QWidget(parent), modified(false), paintSize(10)     //image에 처음 표현되는 선굵기 초기값(10), 마우스를 누르지 않은 상태 초기값 (false)
{
    setAttribute(Qt::WA_AcceptTouchEvents);             //Widget에서 TouchEvent가 활성화 될 수 있게 해줌
    setAttribute(Qt::WA_StaticContents);                //변하는 내용이 없다? 안 써줘도 됨 그리는 event 말고 변하는게 없으니까 써줌(속성)
    paintColor=Qt::black;                               //선 색을 검정으로 설정

}

void ScratchPad::paintEvent(QPaintEvent *event){
    QPainter painter(this);                             //QPainter 객체 생성
    const QRect rect = event->rect();                   //사각형을 반환(사각형이 그려지는 이벤트)
    painter.drawImage(rect.topLeft(), image, rect);     //왼쪽 위를 기준으로 rect 영역 안에서 image를 보여줌
}

void ScratchPad::resizeEvent(QResizeEvent *event)               //창 크기가 변할때마다 event 불림
{

    if(width()>image.width()||height()>image.height()){         /*이미지의 넓이나 높이가 하나라도 widget보다 작을때
                                                                이전의 영역보다 현재 영역이 커질 때만 조정해줌*/
        int newWidth = qMax(width()+128, image.width());        //창의 크기가 변하는 기준으로 image의 여유값을 128로 지정해줌
        int newHeight= qMax(height()+128, image.height());      //창의 크기가 변하는 기준으로 image의 여유값을 128로 지정해줌
        resizeImage(&image, QSize(newWidth, newHeight));        /*resizeEvent가 생기면 새로운 너비와 높이로 크기를 조정해줌
                                                                QSize(int width, int height)*/
        update();                                               //update의 인자가 없을 때는 rect(전체 영역)

    }
    QWidget::resizeEvent(event);                                //처리하지 못하는 일을 부모로 넘겨줌(자식이 먼저 처리하고)
                                                                //부모 생성자를 불러주는거랑 똑같음
}

void ScratchPad::resizeImage(QImage *image, const QSize &newSize)
{
    if(image->size() == newSize) return;                         //새로운 크기로 버퍼를 새롭게 생성
    QImage newImage(newSize, QImage::Format_RGB32);              //QImage(const QSize &size, QImage::Format format)
                                                                 //Format_RGB32: The image is stored using a 32-bit RGB format (0xffRRGGBB).
    newImage.fill(qRgb(255,255,255));                            //흰색으로 만든다 (int r, int g, int b) 흰색 색상코드 255,255,255
    QPainter painter(&newImage);                                 //QPainter(QPaintDevice *device) 들어가는 QPointDevice는

    painter.drawImage(QPoint(0,0), *image);
    *image = newImage;                                          //멤버변수에 있는 이미지가 새로운걸로 바뀜
}

void ScratchPad::mousePressEvent(QMouseEvent* event)            //마우스를 눌렀을 때
{
    prevPos = event->pos();                                     //이전 점의 위치를 기억
    QPen pen(paintColor, paintSize);
    pen.setCapStyle(Qt::RoundCap);                              //선의 외각선을 부드럽게 하기 위해 모서리가 둥근 형태로 바꿔줌
    QPainter painter(&image);                                   //QPainter(QPaintDevice *device) 들어가는 QPaintDevice는 QImage image

    painter.setPen(pen);                                        //펜 사용
    painter.drawPoint(prevPos);                                 //현재 펜의 색상을 사용하여 지정된 위치에 단일 점을 그림
    painter.end();                                              /* QPainter에 device를 지정해주면 begin()을 자동으로 호출해주기
                                                                   때문에 end()로 끝내줘야함*/

    modified = true;                                            //마우스를 눌렀으니까 modified를 true로 바꿔줌
}

void ScratchPad::mouseMoveEvent(QMouseEvent* event)             //마우스 이동시
{
    QPointF newPos = event->pos();
    if(modified){
        QPen pen(paintColor, paintSize);
        pen.setCapStyle(Qt::RoundCap);                          //선의 외각선을 부드럽게 하기 위해 모서리가 둥근 형태로 바꿔줌
        pen.setJoinStyle(Qt::RoundJoin);
        QPainter painter(&image);
        painter.setPen(pen);
        painter.drawLine(prevPos, newPos);                      //이전 점에서 현재 점까지 선 그리기
        painter.end();                                          /*begin() 함수에서 가상의 메모리 영역에 드로잉한 결과를
                                                                  end()함수가 호출되면서 실제 드로잉 영역에 적용*/
    }
    int x1,x2,y1,y2;
    if(prevPos.x()<newPos.x()){                                 //속도를 위해 현재 변화된 부분을 계산해서 화면 업데이트
        x1=prevPos.x(); x2 = newPos.x();
    }else{
        x1=newPos.x(); x2 = prevPos.x();
    }                                                           /*(0,0)->TopLeft을 기준으로 처음 지점과
                                                                새로운 지점의 값 중 더 큰 값을 x2, y2*/

    if(prevPos.y()<newPos.y()){
        y1=prevPos.x(); y2 = newPos.x();
    }else{
        y1=newPos.x(); y2 = prevPos.y();
    }

    QRectF rect(x1, y1, x2, y2);                                //해당 좌표의 사각형 부분을 업데이트
    update();
    prevPos = newPos;
}

void ScratchPad::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    QPen pen(paintColor, paintSize);
    pen.setCapStyle(Qt::RoundCap);
    QPainter painter(&image);
    painter.setPen(pen);
    painter.drawPoint(prevPos);
    painter.end();
    modified = false;                                   //마우스를 떼면서 true에서 false로 바꿔줌

    update();
}

void ScratchPad::setPaintColor(){
    paintColor = QColorDialog::getColor(paintColor, this);                              //QColorDialog를 이용한 색상 변경
}

void ScratchPad::saveImage(){
    QString filename = QDateTime::currentDateTime().toString("yyyyMMddHHmmss")+".png";  //현재 날짜/시간 정보로 파일명 설정
    image.save(filename);
}

void ScratchPad::setPaintSize(qreal size){                                              //선의 굵기 선택
    paintSize = size;
}


//#include "scratchpad.h"

//#include <QtWidgets>

//#define RADIUS 5

//ScratchPad::ScratchPad(QWidget *parent):
//    QWidget(parent), paintSize(10), modified(false)//pad에 표현되는 선굵기의 초기값 설정, 마우스를 누르지 않은 상태니까 초기값 false
//{
//    setAttribute(Qt::WA_AcceptTouchEvents);
//    setAttribute(Qt::WA_StaticContents);
//    paintColor=Qt::black; //글자색 검정

//}

//void ScratchPad::paintEvent(QPaintEvent *event){
//    QPainter painter(this);
//    const QRect rect = event->rect();
//    painter.drawImage(rect.topLeft(), image, rect);//rect 영역 안에서만 그림을 보여줌
//}

//void ScratchPad::resizeEvent(QResizeEvent *event)//레이아웃이 변할떄마다 event 불림
//{
//    if(width()>image.width()||height()>image.height()){//이미지의 넓이나 높이가 하나라도 widget보다 작을때 이전의 영역보다 현재 영역이 커질 때만 조정해줌
//        int newWidth = qMax(width()+128, image.width()); //위젯을 새롭게 128 늘려줌
//        int newHeight=qMax(height() + 128, image.height());//높이를 새롭게 128 조정해줌
//        resizeImage(&image, QSize(newWidth, newHeight));//QSize(int width, int height)
//        //새로운 너비와 높이로 크기를 조정해줌
//        update();
//        //update의 인자가 없을 떄는 rect가 들어간다 (전체)
//    }
//    QWidget::resizeEvent(event);
//}

//void ScratchPad::resizeImage(QImage *image, const QSize &newSize)
//{
//    if(image->size() == newSize) return;    //새로운 크기로 버퍼를 새롭게 생성
//    QImage newImage(newSize, QImage::Format_RGB32); //QImage(const QSize &size, QImage::Format format)
//    //Format_RGB32: The image is stored using a 32-bit RGB format (0xffRRGGBB).
//    newImage.fill(qRgb(255,255,255));   //흰색으로 만든다 (int r, int g, int b) 흰색 색상코드 255,255,255
//    QPainter painter(&newImage);    //QPainter(QPaintDevice *device) 들어가는 QPointDevice는
//    //QPainter를 사용하여 그릴 수있는 이차원 공간의 추상화이다. 초기값?(0,0)이 왼쪽 위 QImage image에 그림을 그려야하니까
//    painter.drawImage(QPoint(0,0), *image);
//    *image = newImage;  //멤버변수에 있는 이미지가 새로운걸로 바뀜
//}

//void ScratchPad::mousePressEvent(QMouseEvent* event)    //마우스를 눌렀을 때
//{
//    prevPos = event->pos();         //이전 점의 위치를 기억
//    QPen pen(paintColor, paintSize);
//    pen.setCapStyle(Qt::RoundCap);  //선의 외각선을 부드럽게 하기 위해 모서리가 둥근 형태로 바꿔줌
//    QPainter painter(&image); //QPainter(QPaintDevice *device) 들어가는 QPointDevice는
//    //QPainter를 사용하여 그릴 수있는 이차원 공간의 추상화이다.  QImage image에 그림을 그려야하니까
//    painter.setPen(pen); //void setPen(const QPen &pen)
//    //begin을 호출
//    painter.drawPoint(prevPos);
//    painter.end(); // bool end()
//    //QPainter 이 생성자는 수명이 짧은 painter에게 편리합니다. QWidget::paintEvent()에서 한 번만 사용해야 합니다.
//    //생성자는 사용자를 위해 begin()을 호출하고 QPainter 소멸자는 자동으로 end()를 호출합니다.
//    modified = true; //마우스를 눌렀으니까 modified를 true로 바꿔줌
//}

//void ScratchPad::mouseMoveEvent(QMouseEvent* event) //마우스 이동시
//{
//    QPointF newPos = event->pos();
//    if(modified){
//        QPen pen(paintColor, paintSize);
//        pen.setCapStyle(Qt::RoundCap);
//        pen.setJoinStyle(Qt::RoundJoin);
//        QPainter painter(&image);
//        painter.setPen(pen);
//        painter.drawLine(prevPos, newPos);  //이전 점에서 현재 점까지 선 그리기
//        painter.end();

//    }
//    int x1,x2,y1,y2;
//    if(prevPos.x()<newPos.x()){ //속도를 위해 현재 변화된 부분을 계산해서 화면 업데이트
//        x1=prevPos.x(); x2 = newPos.x();
//    }else{
//        x1=newPos.x(); x2 = prevPos.x();
//    }

//    if(prevPos.y()<newPos.y()){
//        y1=prevPos.x(); y2 = newPos.x();
//    }else{
//        y1=newPos.x(); y2 = prevPos.y();
//    }

//    QRectF rect(x1, y1, x2, y2);
//    //update(rect.toRect().adjusted(-RADIUS, -RADIUS, +RADIUS, +RADIUS));
//    update();
//    prevPos = newPos;
//}

//void ScratchPad::mouseReleaseEvent(QMouseEvent* event)
//{
//    QPen pen(paintColor, paintSize);
//    pen.setCapStyle(Qt::RoundCap);
//    QPainter painter(&image);
//    painter.setPen(pen);
//    painter.drawPoint(prevPos);
//    painter.end();
//    modified = false;

//    update();
//}

//void ScratchPad::setPaintColor(){
//    paintColor = QColorDialog::getColor(paintColor, this);
//}

//void ScratchPad::saveImage(){
//    QString filename = QDateTime::currentDateTime().toString("yyyyMMddHHmmss")+".png";
//    image.save(filename);
//}

//void ScratchPad::setPaintSize(qreal size){
//    paintSize = size;
//}
