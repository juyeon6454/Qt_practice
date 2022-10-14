#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTcpServer>
#include <QPushButton>
#include <QTcpSocket>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void clientConnect();
    void echoData();
    void removeItem();

private:
    QLabel *infoLabel;
    QTcpServer *tcpServer;

    QList<QTcpSocket*> clientList;

};
#endif // WIDGET_H
