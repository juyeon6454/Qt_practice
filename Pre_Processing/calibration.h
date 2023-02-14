#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QWidget>

namespace Ui {
class Calibration;
}

class Calibration : public QWidget
{
    Q_OBJECT

public:
    explicit Calibration(QWidget *parent = nullptr);
    ~Calibration();

private slots:

    int on_Calibration_pushButton_clicked();

    void on_Clear_pushButton_clicked();

    void on_size_comboBox_activated(int index);

    void on_calibration_comboBox_activated(int index);

    void on_raw_Filepath_pushButton_clicked();

    void on_dark_Filepath_PushButton_clicked();

    void on_gain_Filepath_pushButton_clicked();

private:
    Ui::Calibration *ui;
    //QProcess *process;
};

#endif // CALIBRATION_H
