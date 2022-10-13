#ifndef CONCURRENT_H
#define CONCURRENT_H

#include <QWidget>

class Concurrent : public QWidget
{
    Q_OBJECT

public:
    Concurrent(QWidget *parent = nullptr);
    ~Concurrent();
};
#endif // CONCURRENT_H
