#include "widget.h"
#include "qcoreevent.h"
#include <QPushButton>
#include <QSignalMapper>
#include <QKeyEvent>
#include <QApplication>
#include <QCloseEvent>

//Widget::Widget(QWidget *parent)
//    : QWidget{parent}
//{
////    QSignalMapper* mapper = new QSignalMapper(this);
////    QPushButton* button[8];
////    for(int i=0; i<8; i++) {
////        button[i]=new QPushButton(QString("Button%1").arg(i+1),this);
////        button[i]->setGeometry(30,40*i,120,35);
////        connect(button[i],SIGNAL(clicked()),mapper,SLOT(map()));
////        mapper->setMapping(button[i],i);
////    }
////    connect(mapper, &QSignalMapper::mappedInt,[](int i){qDebug("%d",i);});

//}

////bool Widget::event(QEvent* e) {
////    if (e->type( ) == QEvent::KeyPress) {
////        QKeyEvent * ke = (QKeyEvent*)e;
////        qDebug( ) << ke->text( );
////        if (ke->key( ) == Qt::Key_Tab) {   // 독자적인 Tab 키 처리
////            ke->accept( );
////            return true;
////        }
////    } else if (e->type( ) >= QEvent::User) {

////        /* 커스텀(Custom) 이벤트 처리 */
////        return true;
////    }
////    return false;
////}

//bool Widget::event(QEvent* e) {

//    if (e->type( ) == QEvent::KeyPress) {
//        QKeyEvent * ke = (QKeyEvent*)e;
//        qDebug( ) << ke->text( );
//        if (ke->key( ) == Qt::Key_Tab) {   // 독자적인 Tab 키 처리
//            ke->accept( );
//            return true;
//        } else if (ke->key( ) == Qt::Key_S) {

//            const QEvent::Type CUSTOM_EVENT = static_cast<QEvent::Type>(QEvent::User + 1);
//            QApplication::postEvent(this, new QEvent(CUSTOM_EVENT));
//        }
//    } else if (e->type( ) >= QEvent::User)
//    {
//        /* 커스텀(Custom) 이벤트 처리 */
//        qDebug() << "User Event : " << e->type( );
//        return true;
//    }
//    return false;
//}



////void Widget::customEvent(QEvent* event){
////    if(event->type()==CUSTOM_EVENT){
////    }
////}


////bool Widget::event(QEvent* e){
////    if(e->type() == QEvent::KeyPress){
////        QKeyEvent * ke = (QKeyEvent*)e;
////        qDebug()<<ke->text();
////        if(ke->key() == Qt::Key_Tab){
////            ke->accept();
////            return true;
////        }

////    }
////      return false;
////}



//double Widget::add(const int a, const float b)
//{
//    return a+b;
//}

//Widget::~Widget()
//{
//}
//=================================================================

Widget::Widget(QWidget* parent): QLabel(parent){
    setText(tr("Hello World"));
    resize(100,30);
}

void Widget::moveEvent(QMoveEvent*){
    setText(QString("X: %1, Y: %2").arg(x()).arg(y()));
}

void Widget::closeEvent(QCloseEvent* event) {
    event->ignore();
}

Widget::~Widget()
{

}















