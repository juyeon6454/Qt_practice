#include <QCoreApplication>
#include <QDebug>
#include <QVariant>

#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Counter a,b;
    QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));
    a.setValue(30);
    b.setObjectName("bar");
    qDebug() << b.property("objectName");
    qDebug("%d", b.value());

    return app.exec();
}
