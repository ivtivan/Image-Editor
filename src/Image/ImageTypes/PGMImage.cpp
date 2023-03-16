#include "PGMImage.h"

PGMImage::PGMImage() {
    ;
}

const std::string PGMImage::getTypeID() const {
    return "P2";
}

void PGMImage::allocatePixels() {
    //  TODO
}

void PGMImage::updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols) {
    //  TODO
} 

PGMImage::~PGMImage() {
    ;
}