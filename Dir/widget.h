#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QDir;
class QListWidget;
class QListWidgetItem;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT
private:
    void refreshDir();
    QDir *directory;
    QListWidget *dirListWidget;
    QLineEdit *filenameLineEdit;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void selectItem(QListWidgetItem* item);
    void changeDir();
    void makeDir();
    void removeDir();
    void renameDir();
};
#endif // WIDGET_H
