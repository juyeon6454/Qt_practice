#include "widget.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <QImage>
//#include <opencv2/core.hpp>
//#include <vector>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    // Load the BMP image
    QImage image("./lena_gray.bmp");

    // Convert the QImage to cv::Mat
    cv::Mat mat(image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine());
    cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);

    // Apply CLAHE to the image
    cv::Mat equalized;
    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    clahe->apply(mat, equalized);

    // Convert the equalized cv::Mat back to QImage
    QImage equalizedImage(equalized.data, equalized.cols, equalized.rows, equalized.step, QImage::Format_Grayscale8);

    // Save the equalized image

    equalizedImage.save("./lena_result.bmp");


}


Widget::~Widget()
{
}
