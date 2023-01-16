#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>                     /* USHRT_MAX 상수를 위해서 사용한다. */
#define LIMIT_UBYTE(n) ((n)>UCHAR_MAX)?UCHAR_MAX:((n)<0)?0:(n)

#include "bmpHeader.h"
 typedef unsigned char ubyte;

inline unsigned char clip(int value, int min, int max);
unsigned char clip(int value, int min, int max)
{
    return(value > max ? max : value < min ? min : value);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //   QGraphicsScene *scene = new QGraphicsScene;
//QImage img = QImage("./lena_gray.bmp");

    FILE* fp;
    BITMAPFILEHEADER bmpHeader;             /* BMP FILE INFO */
    BITMAPINFOHEADER bmpInfoHeader;     /* BMP IMAGE INFO */
    RGBQUAD* palrgb;
    ubyte* inimg, * outimg;
    int x, y, z, imageSize;
    int arr[9] = { 0, };

    /* BITMAPFILEHEADER 구조체의 데이터 */
    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);

    /* BITMAPINFOHEADER 구조체의 데이터 */
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);


    int elemSize = bmpInfoHeader.biBitCount / 8;
    int height = bmpInfoHeader.biHeight;
    int width = bmpInfoHeader.biWidth;
    int size = width * elemSize;
    imageSize = size * bmpInfoHeader.biHeight;

    /* 이미지의 해상도(넓이 × 깊이) */
    printf("Resolution : %d x %d\n", bmpInfoHeader.biWidth, bmpInfoHeader.biHeight);
    printf("Bit Count : %d\n", bmpInfoHeader.biBitCount);     /* 픽셀당 비트 수(색상) */
    printf("Image Size : %d\n", imageSize);

    inimg = (ubyte*)malloc(sizeof(ubyte) * imageSize);
    outimg = (ubyte*)malloc(sizeof(ubyte) * imageSize);

    printf("inimg : %ld \n", sizeof(ubyte) * (imageSize));

    fread(inimg, sizeof(ubyte), imageSize, fp);
    fclose(fp);

    //	memset(padimg, 0, sizeof(ubyte) *
    //			(imageSize + ((bmpInfoHeader.biWidth + bmpInfoHeader.biHeight+2)*2)) );

    memset(outimg, 0, sizeof(ubyte) * imageSize);

    float kernel[3][3] = { {1 / 9.0, 1 / 9.0, 1 / 9.0},
                            { 1 / 9.0 , 1 / 9.0, 1 / 9.0},
                            { 1 / 9.0, 1 / 9.0, 1 / 9.0} };
    int cnt = 0;
    //padimg * kernel
    //for(y = 1; y < bmpInfoHeader.biHeight + 1; y++) {
    //	for(x = elemSize; x < (bmpInfoHeader.biWidth + 1) * elemSize; x+=elemSize) {
    for (y = 0; y < bmpInfoHeader.biHeight; y++) {
        for (x = 0; x < (bmpInfoHeader.biWidth) * elemSize; x += elemSize) {
            for (z = 0; z < elemSize; z++) {
                if (x == 0) {
                    //LeftUpVertex
                    if (y == 0) {
                        arr[0] = arr[1] = arr[3] = arr[4] = inimg[x + (y * size) + z];
                        arr[2] = arr[5] = inimg[x + elemSize + (y * size) + z];
                        arr[6] = arr[7] = inimg[x + ((y + 1) * size) + z];
                        arr[8] = inimg[x + elemSize + ((y + 1) * size) + z];
                    }
                    //LeftDownVertex
                    else if (y == height - 1) {
                        arr[0] = arr[1] = inimg[x + ((y - 1) * size) + z];
                        arr[2] = inimg[x + elemSize + ((y - 1) * size) + z];
                        arr[3] = arr[6] = arr[7] = arr[4] = inimg[x + (y * size) + z];
                        arr[8] = arr[5] = inimg[x + elemSize + (y * size) + z];
                    }
                    else {
                        arr[0] = arr[1] = inimg[x + ((y - 1) * size) + z];
                        arr[2] = inimg[x + elemSize + ((y - 1) * size) + z];
                        arr[3] = arr[4] = inimg[x + (y * size) + z];
                        arr[5] = inimg[x + elemSize + (y * size) + z];
                        arr[6] = arr[7] = inimg[x + ((y + 1) * size) + z];
                        arr[8] = inimg[x + elemSize + ((y + 1) * size) + z];
                    }

                    cnt = 0;
                    float sum = 0.0;
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            sum += kernel[i + 1][j + 1] * arr[cnt++];
                        }
                    }
                    outimg[(x + y * size) + z] = clip(sum, 0, 255);
                }

                else if (x == (width * elemSize - elemSize)) {
                    //RightUpVertex
                    if (y == 0) {
                        arr[0] = arr[3] = inimg[x - elemSize + (y * size) + z];
                        arr[1] = arr[2] = arr[5] = arr[4] = inimg[x + (y * size) + z];
                        arr[6] = inimg[x - elemSize + ((y - 1) * size) + z];
                        arr[7] = arr[8] = inimg[x + ((y + 1) * size) + z];
                    }
                    //RightDownVertex
                    else if (y == height - 1) {
                        arr[0] = inimg[x - elemSize + ((y - 1) * size) + z];
                        arr[1] = arr[2] = inimg[x - elemSize + ((y - 1) * size) + z];
                        arr[3] = arr[6] = inimg[x - elemSize + (y * size) + z];
                        arr[4] = arr[5] = arr[7] = arr[8] = inimg[x + (y * size) + z];
                    }
                    else {
                        arr[0] = inimg[x - elemSize + ((y - 1) * size) + z];
                        arr[2] = arr[1] = inimg[x + ((y - 1) * size) + z];
                        arr[3] = inimg[x - elemSize + (y * size) + z];
                        arr[5] = arr[4] = inimg[x + (y * size) + z];
                        arr[6] = inimg[x - elemSize + ((y + 1) * size) + z];
                        arr[8] = arr[7] = inimg[x + ((y + 1) * size) + z];
                    }
                    cnt = 0;
                    float sum = 0.0;
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            sum += kernel[i + 1][j + 1] * arr[cnt++];
                        }
                    }
                    outimg[(x + y * size) + z] = clip(sum, 0, 255);
                }
                else if (y == 0) {
                    if (x != 1 && x != size - elemSize) {
                        arr[0] = arr[3] = inimg[x - elemSize + (y * size) + z];
                        arr[1] = arr[4] = inimg[x + (y * size) + z];
                        arr[2] = arr[5] = inimg[x + elemSize + (y * size) + z];
                        arr[6] = inimg[x - elemSize + ((y + 1) * size) + z];
                        arr[7] = inimg[x + ((y + 1) * size) + z];
                        arr[8] = inimg[x + elemSize + ((y + 1) * size) + z];

                        cnt = 0;
                        float sum = 0.0;
                        for (int i = -1; i < 2; i++) {
                            for (int j = -1; j < 2; j++) {
                                sum += kernel[i + 1][j + 1] * arr[cnt++];
                            }
                        }
                        outimg[(x + y * size) + z] = clip(sum, 0, 255);
                    }
                }
                else if (y == (height - 1)) {
                    if (x != 1 && x != size - elemSize) {
                        arr[0] = inimg[x - elemSize + ((y - 1) * size) + z];
                        arr[1] = inimg[x + ((y - 1) * size) + z];
                        arr[2] = inimg[x + elemSize + ((y - 1) * size) + z];
                        arr[3] = arr[6] = inimg[x - elemSize + (y * size) + z];
                        arr[4] = arr[7] = inimg[x + (y * size) + z];
                        arr[5] = arr[8] = inimg[x + elemSize + (y * size) + z];
                        cnt = 0;
                        float sum = 0.0;
                        for (int i = -1; i < 2; i++) {
                            for (int j = -1; j < 2; j++) {
                                sum += kernel[i + 1][j + 1] * arr[cnt++];
                            }
                        }
                        outimg[(x + y * size) + z] = clip(sum, 0, 255);
                    }
                }

                else {
                    float sum = 0.0;
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            sum += kernel[i + 1][j + 1] * inimg[((x + i * elemSize) + (y + j) * size) + z];
                        }
                    }
                    outimg[(x + y * size) + z] = clip(sum, 0, 255);
                }

            }
        }
    }



    /* BITMAPFILEHEADER 구조체의 데이터 */
    fwrite(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);

    /* BITMAPINFOHEADER 구조체의 데이터 */
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    //fwrite(inimg, sizeof(ubyte), imageSize, fp);
    fwrite(outimg, sizeof(ubyte), imageSize, fp);

    fclose(fp);

    free(inimg);
    free(outimg);


//    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(img));

//scene->addItem(item);

//    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

