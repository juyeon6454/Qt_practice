#ifndef HTTPDOWNLOAD_H
#define HTTPDOWNLOAD_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = 0);

signals:

public slots:
    void replyFinished(QNetworkReply *reply);

private:
        QNetworkAccessManager *manager;
};

#endif // HTTPDOWNLOAD_H
