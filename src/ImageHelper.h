#ifndef IMAGE_HELPER_H
#define IMAGE_HELPER_H

#include <cstring>
#include <stdint.h>
#include <iostream>
#include "def.h"

using namespace std;

class ImageHelper 
{
public:
    ImageHelper();
    virtual ~ImageHelper() = 0;

    /*
     * Initialize the Helper
     */    
    virtual void init() = 0;

    /*
     * Load a Image from path
     */
    virtual void loadImage() = 0;

    /*
     * Crop the image to targetWidth x targetHeight
     */
    virtual bool cropImage(uint32_t targetWidth, uint32_t targetHeight) = 0;

    /*
     * Process the image according to ImageOperation
     */
    virtual bool processImage() = 0;

    void setImageOperation(ImageOperation &op);

public:
    ImageOperation imageOperation;
};

#endif