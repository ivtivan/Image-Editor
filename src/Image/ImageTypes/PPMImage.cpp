#include "PPMImage.h"

PPMImage::PPMImage(std::size_t rows, std::size_t cols, Pixel*** pixels) :
    Image(rows, cols, pixels) {
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