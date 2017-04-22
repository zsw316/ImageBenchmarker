#include <opencv2/opencv.hpp>   
#include <iostream>   

using namespace cv;  
using namespace std;  

int main(int argc,char **argv)  
{  
    Mat srcImage;  
    srcImage = imread(argv[1],1);  
  
    if(argc != 2 || !srcImage.data)  
    {  
        cout << "No image data\n";  
        exit(1);  
    }  
  
    uint32_t targetWidth = 960;
    uint32_t targetHeight = 640;

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
        imwrite("opencv_crop.jpg", dstImage);
	}catch(...)
	{
		printf("crop failed, catch exception! src=%dx%d, dest=%dx%d\n",
			srcWidth, srcHeight, targetWidth, targetHeight);
		exit(1);  
	}

    return 0; 
}
