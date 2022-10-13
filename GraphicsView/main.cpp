#include "widget.h"

#include <QApplication>
#include <QtWidgets>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QGraphicsScene *scene = new QGraphicsScene;
//    scene->addRect(-10,-10,120,50);//아이템을 간단히 추가
//    QGraphicsItem *item = new QGraphicsTextItem("Hello World!");
//    scene->addItem(item);

//    QGraphicsView *view = new QGraphicsView;
//    view->setScene(scene);
//    view->show();


////    Widget w;
////    w.show();
//    return a.exec();
//}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsRectItem *rect = scene->addRect(-10,-10, 120, 50);
    rect->setPen(QPen(Qt::red));
    rect->setBrush(QBrush(Qt::yellow));
    QGraphicsItem *item = new QGraphicsTextItem("Hello World!");
    scene->addItem(item);
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    return a.exec();
}



