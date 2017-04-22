#include "GraphicsMagickHelper.h"

GraphicsMagickHelper::GraphicsMagickHelper()
{

}

GraphicsMagickHelper::~GraphicsMagickHelper()
{

}

void GraphicsMagickHelper::init()
{
    InitializeMagick(NULL);
}

void GraphicsMagickHelper::loadImage()
{    
	srcImage.read(imageOperation.srcImagePath);
}

bool GraphicsMagickHelper::cropImage(uint32_t targetWidth, uint32_t targetHeight)
{
	uint32_t srcWidth = srcImage.baseColumns();
	uint32_t srcHeight = srcImage.baseRows();

	//locale the start point(x,y)
	double scaleCrop = (double)targetWidth / (double)targetHeight;
	double scaleSrc = (double)srcWidth / (double)srcHeight;
	
	uint32_t uX = 0, uY = 0;
	uint32_t uWidth = srcWidth, uHeight = srcHeight;

	if (scaleCrop >= scaleSrc)	//width based
	{
		uHeight = (double)srcWidth / scaleCrop;
		uY = (srcHeight - uHeight) / 2;
	}
	else	//height based
	{
		uWidth = (double)srcHeight * scaleCrop;
		uX = (srcWidth - uWidth) / 2;
	}

	// Crop the image to specified size (width, height, xOffset, yOffset)
	try{	

		srcImage.crop(Geometry(uWidth, uHeight, uX, uY));
		srcImage.sample(Geometry(targetWidth, targetHeight));
	}catch(...)
	{
		error_log("crop failed, catch exception! src=%dx%d, dest=%dx%d\n",
			srcWidth, srcHeight, targetWidth, targetHeight);
		return false;
	}

	return true;
}

bool GraphicsMagickHelper::processImage()
{
    if(imageOperation.opType == CROP_OP) {
        return cropImage(imageOperation.destImageWidth, imageOperation.destImageHeight);
    }

    return cropImage(imageOperation.destImageWidth, imageOperation.destImageHeight);
} 