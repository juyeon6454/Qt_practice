#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QToolBar* toolbar = addToolBar(tr("Open"));

    /*RSS 피드를 열기 위한 콤보박스*/
    combo = new QComboBox;
    combo -> setEditable(true);
    combo -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(combo, SIGNAL(activated(int)),SLOT(openRssFeed()));
    toolbar->addWidget(combo);

    /*RSS 피드 버튼을 위한 액션*/
    QAction* act = new QAction(tr("Open RSS Feed"), this);


    act->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    connect(act, SIGNAL(triggered()), SLOT(openRssFeed()));
    toolbar->addAction(act);

    /*기본 RSS 피드 사이트 등록*/
    combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss");

    /*네트워트 매니저를 위한 설정*/
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::openRssFeed()
{
    /*RSS 사이트 접속*/
    manager->get(QNetworkRequest(QUrl(combo->currentText())));
}

void MainWindow::replyFinished(QNetworkReply* netReply)
{
    QString str(netReply->readAll());
    qDebug("%s",qPrintable(str));
}
