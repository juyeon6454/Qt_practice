#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>

class Database : public QMainWindow
{
    Q_OBJECT

public:
    Database(QWidget *parent = nullptr);
    ~Database();
};
#endif // DATABASE_H
