#ifndef FILTER_H
#define FILTER_H

#include <QObject>

class Filter : public QObject
{
    Q_OBJECT
public:
    explicit Filter(QObject *parent = nullptr);

public:
    bool eventFilter(QObject*,QEvent*);

signals:

};

#endif // FILTER_H
