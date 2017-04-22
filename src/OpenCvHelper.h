#ifndef OPENCV_HELPER_H
#define OPENCV_HELPER_H

#include "opencv.hpp"  
#include "ImageHelper.h"

using namespace cv;

class OpenCvHelper : public ImageHelper
{
public:
    OpenCvHelper();
    ~OpenCvHelper();

    void init();

    void loadImage();

    bool cropImage(uint32_t targetWidth, uint32_t targetHeight);

    bool processImage(); 

private:
    Mat srcImage;
};

#endif