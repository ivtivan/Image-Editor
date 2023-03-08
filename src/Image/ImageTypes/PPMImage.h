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
        PPMImage(const std::ifstream& sourceFile);
        PPMImage(std::string hexColor, std::size_t rows, std::size_t cols);
        ~PPMImage();
};

#endif