#include "object.h"
#include <QDebug>

Object::Object(QObject *parent)
    : QObject(parent){
    qInfo()<<"Constructor"<<this;
}
Object::~Object()
{

}
//void Object::useWidget(){
//    //포인터가 있는지 확인
//    if(widget.data()){
//        qInfo()<<"Widget ="<<widget.data();
//        //pointer에 접근
//        widget.data()->setObjectName("MyWidget");
//    }
//    else{
//    qInfo()<<"No Pointer!!!";


//    }

//}

