#ifndef STITCHING_H
#define STITCHING_H

#include <QWidget>

namespace Ui {
class Stitching;
}

class Stitching : public QWidget
{
    Q_OBJECT

public:
    explicit Stitching(QWidget *parent = nullptr);
    ~Stitching();


    //QProcess *process;

private slots:
    int on_Stitching_pushButton_clicked();

    void on_path_pushButton_2_clicked();

    void on_Clear_pushButton_2_clicked();


private:
    Ui::Stitching *ui;
};

#endif // STITCHING_H
