#include "ImageHelperFactory.h"
#include "GraphicsMagickHelper.h"
#include "OpenCvHelper.h"

ImageHelperFactory::ImageHelperFactory()
{

}

ImageHelperFactory::~ImageHelperFactory()
{

}

ImageHelper * ImageHelperFactory::buildImageHelper(ImageHelperType type, ImageOperation &op)
{
    ImageHelper *helper = NULL;

    if (type == GM_HELPER)
    {
        helper = new GraphicsMagickHelper();
    }
    else if (type == CV_HELPER)
    {
        helper = new OpenCvHelper();
    }
    else
    {
        helper = new GraphicsMagickHelper();
    }

    helper->setImageOperation(op);

    return helper;
}