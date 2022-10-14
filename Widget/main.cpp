#include "widget.h"
#include "clientwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    ClientWidget c;

    w.show();
    c.show();
    return a.exec();
}
