#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTest>

class Widget : public QObject
{
    Q_OBJECT

public:
    //Widget(QWidget *parent = nullptr);
    //~Widget();
    explicit Widget(QObject *parent = nullptr);
    void setAge(int value);

private slots:
    void testFail();
    void testAge();
    void testWidget();

private:
    int age;
};
#endif // WIDGET_H
