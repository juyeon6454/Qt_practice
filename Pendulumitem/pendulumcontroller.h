#ifndef PENDULUMCONTROLLER_H
#define PENDULUMCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QTimeLine>
#include <QGraphicsItem>

class Pendulumcontroller : public QObject
{
    Q_OBJECT
public:
    explicit Pendulumcontroller(QGraphicsItem* pendulum, QObject* parent = nullptr);


signals:

private slots:
    void slotRotateItem(int r);
    void slotRestartTimeLine();

private:
    QTimeLine m_timeline;
    QGraphicsItem* m_pendulum;

};

#endif // PENDULUMCONTROLLER_H
