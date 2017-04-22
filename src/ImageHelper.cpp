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
    imageOperation.destImageWidth = op.destImageWidth;
    imageOperation.destImageHeight = op.destImageHeight;    
}