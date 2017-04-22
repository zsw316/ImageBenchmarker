#ifndef IMAGE_HELPER_FACTORY_H
#define IMAGE_HELPER_FACTORY_H

#include "ImageHelper.h"

typedef enum
{
    GM_HELPER = 0,
    CV_HELPER = 1,
    INVALID_HELPER
} ImageHelperType;

class ImageHelperFactory
{
public:
    ImageHelperFactory();
    ~ImageHelperFactory();

    ImageHelper * buildImageHelper(ImageHelperType type, ImageOperation &op);    
};

#endif