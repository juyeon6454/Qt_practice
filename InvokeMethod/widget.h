#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

class Widget : public QLabel
{
    Q_OBJECT
public:
    Widget(QWidget *parnet=nullptr);
    ~Widget();

//private:
//    virtual bool event(QEvent* e);
//    void customEvnet(QEvent* event);

//public slots:
//    double add(const int a, const float b);
//   // explicit Widget(QWidget *parent = nullptr);
protected:
    void moveEvent(QMoveEvent*);
    void closeEvent(QCloseEvent*);

signals:

};

#endif // WIDGET_H
