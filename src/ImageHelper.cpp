#include "ImageHelper.h"

ImageHelper::ImageHelper()
{

}

ImageHelper::~ImageHelper()
{

}

void ImageHelper::setImageOperation(ImageOperation &op)
{
    imageOperation.opType = op.opType;
    imageOperation.srcImagePath = op.srcImagePath;
    imageOperation.srcImageSize = op.srcImageSize;
    imageOperation.destImageWidth = op.destImageWidth;
    imageOperation.destImageHeight = op.destImageHeight;    
}

uint32_t ImageHelper::getSrcImageSize()
{
    return imageOperation.srcImageSize;
}
