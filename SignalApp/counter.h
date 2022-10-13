#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit Counter(QObject *parent = nullptr);
    int value() const {return m_value; }

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(int newValue);

private:
    int m_value;

signals:

};

#endif // COUNTER_H
