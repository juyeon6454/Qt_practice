#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

class Widget : public QLabel
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
//    void timerEvent(QTimerEvent *event);

public slots:
    void displayClock();

};
#endif // WIDGET_H
