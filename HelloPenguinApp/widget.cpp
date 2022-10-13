#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    ui->spinBox->blockSignals(true); //시그널을 잠시 멈춰줌
   // ui->spinBox->disconnect(ui->lineEdit);
    ui->dial->setValue(arg1.toInt());
    ui->spinBox->blockSignals(false);//다시 false로 하는 이유 입력이 끝나면 원래대로 돌아가야되니까
    //입력되는 순간에는 signal이 발생하면 안되지만 다시 돌아가야함 spinbox가 lineeditor에게 시그널이 가지 않도록
    //숫자 하나 쓸 때마다 공백이 채워짐을 방지
//    connect(ui->spinBox, SIGNAL(textChanged(QString)),
//            ui->lineEdit, SLOT(setText(QString)));

}

