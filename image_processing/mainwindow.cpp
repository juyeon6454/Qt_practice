#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsPixmapItem>

#define LIMIT_UBYTE(n) ((n)>UCHAR_MAX)?UCHAR_MAX:((n)<0)?0:(n)

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   int sizeX = 512;
   int sizeY = 512;

    QGraphicsScene *scene = new QGraphicsScene;
    QImage img = QImage("./lena_gray.bmp");

    for(int x=0; x < sizeY; x++){
        for (int y=0; y <sizeX; y++){
                  QRgb rgb = img.pixel(x,y);

//                  int r = LIMIT_UBYTE(qRed(rgb) +30);
//                  int g = LIMIT_UBYTE(qGreen(rgb) + 30);
//                  int b = LIMIT_UBYTE(qBlue(rgb)+30);
//                  img.setPixelColor(x, y, QColor(r, g, b));

                   int gray = LIMIT_UBYTE(qGray(rgb)+50);
                   img.setPixel(x,y,gray);

                  //img.invertPixels(QImage::InvertRgba);
        }
    }
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(img));

    scene->addItem(item);

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
   delete ui;
}
