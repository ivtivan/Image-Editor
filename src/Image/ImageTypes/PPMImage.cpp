#include "PPMImage.h"

PPMImage::PPMImage(Dimension dimension, Pixel*** pixels) :
    Image(dimension, pixels) {
    ;
}

void PPMImage::updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols) {
    //  TODO
} 

const std::string PPMImage::getTypeID() const {
    return "P3";
}

PPMImage::~PPMImage() {
    ;
}