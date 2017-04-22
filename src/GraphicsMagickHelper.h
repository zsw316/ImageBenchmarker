#ifndef GRAPHICS_MAGICK_HELPER_H
#define GRAPHICS_MAGICK_HELPER_H

#include <stdint.h>
#include "def.h"
#include "ImageHelper.h"
#include "Magick++.h"

using namespace std;
using namespace Magick;

class GraphicsMagickHelper : public ImageHelper
{
public:
    GraphicsMagickHelper();

    ~GraphicsMagickHelper();

    void init();

    void loadImage();

    bool cropImage(uint32_t targetWidth, uint32_t targetHeight);

    bool processImage();

private:
    Image srcImage;

};

#endif