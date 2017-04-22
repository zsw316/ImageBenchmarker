#include "OpenCvHelper.h"

OpenCvHelper::OpenCvHelper()
{

}

OpenCvHelper::~OpenCvHelper()
{

}

void OpenCvHelper::init()
{

}

void OpenCvHelper::loadImage()
{
    srcImage = imread(imageOperation.srcImagePath);
}

bool OpenCvHelper::cropImage(uint32_t targetWidth, uint32_t targetHeight)
{
    uint32_t srcWidth = srcImage.size().width;
	uint32_t srcHeight = srcImage.size().height;

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
        Rect region_of_interest(uX, uY, uWidth, uHeight);
        Mat image_roi = srcImage(region_of_interest);

        Size size(targetWidth,targetHeight);  
        Mat dstImage;          //dstimage
        resize(image_roi ,dstImage,size);  //resize image
	}catch(...)
	{
		error_log("crop failed, catch exception! src=%dx%d, dest=%dx%d\n",
			srcWidth, srcHeight, targetWidth, targetHeight);
		return false;
	}

    return true;
}

bool OpenCvHelper::processImage()
{
    if(imageOperation.opType == CROP_OP) {
        return cropImage(imageOperation.destImageWidth, imageOperation.destImageHeight);
    }

    return cropImage(imageOperation.destImageWidth, imageOperation.destImageHeight);
}