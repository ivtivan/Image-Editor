#ifndef PPM_IMAGE_H
#define PPM_IMAGE_H

#include "../Image.h"
#include "../../Pixel/PixelTypes/PPMPixel.h"

class PPMImage : public Image {
    public:
        PPMImage(Dimension dimension, Pixel*** pixels);

        const std::string getTypeID() const;

        void updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols);

        ~PPMImage();
};

#endif