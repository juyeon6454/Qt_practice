#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPrinter>
#include <QDialog>
#include <QPrintDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <QTextEdit>
void MainWindow::on_actionNew_triggered()
{
      QTextEdit* textedit = new QTextEdit(this);
      ui->mdiArea->addSubWindow(textedit);
      textedit->show();

}

void MainWindow::mousePressEvent(QMouseEvent*)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setFullPage(true);
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec() == QDialog::Accepted){
        QPixmap pixmap = grab();
        pixmap.save("window.png");
//        QPrinter printer(QPrinter::PrinterResolution);
//        printer.setFullPage(true);
        QPainter paint(&printer);
        paint.drawPixmap(0,0,pixmap.scaled(1280,720));

    }


}
