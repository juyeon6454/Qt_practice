#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Thread;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    Thread* thread;
private slots:
   // QThread* thread;
    void threadControl(bool flag);


signals:

};

#endif // WIDGET_H
