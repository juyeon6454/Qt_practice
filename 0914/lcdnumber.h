#ifndef LCDNUMBER_H
#define LCDNUMBER_H

#include <QMainWindow>

class LCDNumber : public QMainWindow
{
    Q_OBJECT

public:
    LCDNumber(QWidget *parent = nullptr);
    ~LCDNumber();
};
#endif // LCDNUMBER_H
