#include "ImageFactory.h"

ImageFactory::ImageFactory() {
    ;
}

Image* ImageFactory::getPPMFromSizeColor(std::size_t  rows, std::size_t  cols,
    std::string hexColor) const {
    return new PPMImage(rows, cols, hexColor);
}