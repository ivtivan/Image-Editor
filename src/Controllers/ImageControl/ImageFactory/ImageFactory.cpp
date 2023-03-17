#include "ImageFactory.h"

ImageFactory::ImageFactory() {
    ;
}

PPMImage* ImageFactory::getPPMFromSizeColor(std::size_t  rows, std::size_t  cols,
    std::string hexColor) const {
    //  TODO: handle bad_alloc
    Pixel*** pixels = new Pixel**[rows];
    for (std::size_t i = 0; i < rows; ++i) {
        pixels[i] = new Pixel*[cols];
        for (std::size_t j = 0; j < cols; ++j) {
            pixels[i][j] = new PPMPixel(hexColor);
        }
    }

    return new PPMImage(rows, cols, pixels);
}