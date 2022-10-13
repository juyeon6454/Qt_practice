#ifndef LINGUISTAPP_H
#define LINGUISTAPP_H

#include <QWidget>

class LinguistApp : public QWidget
{
    Q_OBJECT

public:
    LinguistApp(QWidget *parent = nullptr);
    ~LinguistApp();
};
#endif // LINGUISTAPP_H
