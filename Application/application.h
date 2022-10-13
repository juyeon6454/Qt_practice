#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int&, char**);

public:
    bool notify(QObject*, QEvent*);

signals:

};

#endif // APPLICATION_H
