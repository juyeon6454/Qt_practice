#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsPixmapItem>

#define LIMIT_UBYTE(n) ((n)>UCHAR_MAX)?UCHAR_MAX:((n)<0)?0:(n)

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   int width = 512;
   int height = 512;
   int elemSize = 1;
   int arr[9] = { 0, };

    QGraphicsScene *scene = new QGraphicsScene;

    QImage inimg = QImage("./lena_gray.bmp");

    QImage outimg = QImage(width, height, QImage::Format_Indexed8);

    float kernel[3][3] = { {1 / 9.0, 1 / 9.0, 1 / 9.0},
                              {1 / 9.0, 1 / 9.0, 1 / 9.0},
                              {1 / 9.0, 1 / 9.0, 1 / 9.0} };


/////////////////////////////////
//    QImage image("whatever.png");
//    for(int x(0); x < image.width(); x++)
//        for(int y (0); y < image.height(); y++)
//            image[x][y] *= convKernel[x-1][y] + convKernel[x+1][y+1] ... etc

//    image.save();
/////////////////////////////////////



    for(int y=0; y < height; y++){
        for (int x=0; x <width; x++){
                    float sum = 0.0;
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            QRgb pixel = inimg.pixel(x,y);
                            sum += kernel[i + 1][j + 1] * (LIMIT_UBYTE(qGray(pixel)));
                            //qDebug() << sum;
                        }
                    }

                   outimg.setPixel(x,y,sum);
                  //img.invertPixels(QImage::InvertRgba);
        }
    }
n
//////////////////////////////////////////////////////////////////////////////
    int cnt = 0;

    for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                    if (x == 0) {
                        //LeftUpVertex
                        if (y == 0) {
                            arr[0] = arr[1] = arr[3] = arr[4] = qGray(x + (y * width));
                            arr[2] = arr[5] = qGray(x + elemSize + (y * width));
                            arr[6] = arr[7] = qGray(x + ((y + 1) * width));
                            arr[8] = qGray(x + elemSize + ((y + 1) * width));
                        }
                        //LeftDownVertex
                        else if (y == height - 1) {
                            arr[0] = arr[1] = qGray(x + ((y - 1) * width));
                            arr[2] = qGray(x + elemSize + ((y - 1) * width));
                            arr[3] = arr[6] = arr[7] = arr[4] = qGray(x + (y * width));
                            arr[8] = arr[5] = qGray(x + elemSize + (y * width));
                        }
                        else {
                            arr[0] = arr[1] = qGray(x + ((y - 1) * width));
                            arr[2] = qGray(x + elemSize + ((y - 1) * width));
                            arr[3] = arr[4] = qGray(x + (y * width));
                            arr[5] = qGray(x + elemSize + (y * width));
                            arr[6] = arr[7] = qGray(x + ((y + 1) * width));
                            arr[8] = qGray(x + elemSize + ((y + 1) * width));
                        }

                        cnt = 0;
                        float sum = 0.0;
                        for (int i = -1; i < 2; i++) {
                            for (int j = -1; j < 2; j++) {
                                sum += kernel[i + 1][j + 1] * arr[cnt++];
                            }
                        }
                       //outimg[(x + y * size) + z] = clip(sum, 0, 255);
                       outimg.setPixel(x,y*width ,sum);

                    }

                    else if (x == (width - 1)) {
                        //RightUpVertex
                        if (y == 0) {
                            arr[0] = arr[3] = qGray(x - elemSize + (y * width)) ;
                            arr[1] = arr[2] = arr[5] = arr[4] = qGray(x + (y * width));
                            arr[6] = qGray(x - elemSize + ((y - 1) * width));
                            arr[7] = arr[8] = qGray(x + ((y + 1) * width));
                        }
                        //RightDownVertex
                        else if (y == height - 1) {
                            arr[0] = qGray(x - elemSize + ((y - 1) * width));
                            arr[1] = arr[2] = qGray(x - elemSize + ((y - 1) * width));
                            arr[3] = arr[6] = qGray(x - elemSize + (y * width));
                            arr[4] = arr[5] = arr[7] = arr[8] = qGray(x + (y * width));
                        }
                        else {
                            arr[0] = qGray(x - elemSize + ((y - 1) * width));
                            arr[2] = arr[1] = qGray(x + ((y - 1) * width));
                            arr[3] = qGray(x - elemSize + (y * width));
                            arr[5] = arr[4] = qGray(x + (y * width));
                            arr[6] = qGray(x - elemSize + ((y + 1) * width));
                            arr[8] = arr[7] = qGray(x + ((y + 1) * width));
                        }
                        cnt = 0;
                        float sum = 0.0;
                        for (int i = -1; i < 2; i++) {
                            for (int j = -1; j < 2; j++) {
                                sum += kernel[i + 1][j + 1] * arr[cnt++];
                            }
                        }
                        //outimg[(x + y * size) + z] = clip(sum, 0, 255);
                        outimg.setPixel(x, y * width,sum);
                    }
                    else if (y == 0) {
                        if (x != 1 && x != width - elemSize) {
                            arr[0] = arr[3] = qGray(x - elemSize + (y * width));
                            arr[1] = arr[4] = qGray(x + (y * width));
                            arr[2] = arr[5] = qGray(x + elemSize + (y * width));
                            arr[6] = qGray(x - elemSize + ((y + 1) * width));
                            arr[7] = qGray(x + ((y + 1) * width));
                            arr[8] = qGray(x + elemSize + ((y + 1) * width));

                            cnt = 0;
                            float sum = 0.0;
                            for (int i = -1; i < 2; i++) {
                                for (int j = -1; j < 2; j++) {
                                    sum += kernel[i + 1][j + 1] * arr[cnt++];
                                }
                            }
                            //outimg[(x + y * size) + z] = clip(sum, 0, 255);
                            outimg.setPixel(x, y * width,sum);
                        }
                    }
                    else if (y == (height - 1)) {
                        if (x != 1 && x != width - elemSize) {
                            arr[0] = qGray(x - elemSize + ((y - 1) * width));
                            arr[1] = qGray(x + ((y - 1) * width));
                            arr[2] = qGray(x + elemSize + ((y - 1) * width));
                            arr[3] = arr[6] = qGray(x - elemSize + (y * width));
                            arr[4] = arr[7] = qGray(x + (y * width));
                            arr[5] = arr[8] = qGray(x + elemSize + (y * width));
                            cnt = 0;
                            float sum = 0.0;
                            for (int i = -1; i < 2; i++) {
                                for (int j = -1; j < 2; j++) {
                                    sum += kernel[i + 1][j + 1] * arr[cnt++];
                                }
                            }
                           // outimg[(x + y * size) + z] = clip(sum, 0, 255);
                          outimg.setPixel(x, y * width, sum);
                        }
                    }

                    else {
                        float sum = 0.0;
                        for (int i = -1; i < 2; i++) {
                            for (int j = -1; j < 2; j++) {
                                sum += kernel[i + 1][j + 1] * qGray(((x + i * elemSize) + (y + j) * width));
                            }
                        }
                       // outimg[(x + y * size) + z] = clip(sum, 0, 255);
                        outimg.setPixel(x, y * width,sum);
                    }

                }
            }

        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(outimg));

        scene->addItem(item);

        ui->graphicsView->setScene(scene);
        }

///////////////////////////////////////////////////////////////////////////////

MainWindow::~MainWindow()
{
   delete ui;
}

