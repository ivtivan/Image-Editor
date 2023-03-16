#include "PBMImage.h"

PBMImage::PBMImage() {
    ;
}

const std::string PBMImage::getTypeID() const {
    return "P1";
}

void PBMImage::allocatePixels() {
    //  TODO
}

void PBMImage::updatePixels(Pixel** srcPixels, std::size_t srcRows, std::size_t srcCols) {
    //  TODO
} 

PBMImage::~PBMImage() {
    ;
}