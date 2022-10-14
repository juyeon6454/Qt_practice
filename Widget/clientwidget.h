#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QTcpSocket>


class ClientWidget : public QWidget
{
    Q_OBJECT
public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void echoData();
    void sendData();

private:
    QTextEdit *message;
    QLineEdit *inputLine;
    QTcpSocket *clientSocket;
signals:


};

#endif // CLIENTWIDGET_H
