#ifndef PPM_IMAGE_H
#define PPM_IMAGE_H

#include "../Image.h"
#include "../../Pixel/PixelTypes/PPMPixel.h"

class PPMImage : public Image {
    private:
        PPMPixel** pixels;

        void allocatePixels();
        void createPixels(const std::string& hexColor);
    public:
        PPMImage(std::size_t rows, std::size_t cols, std::string hexColor);

        const std::string getTypeID() const;

        void updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols);

        ~PPMImage();
};

#endif