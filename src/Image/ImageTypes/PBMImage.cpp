#include "PBMImage.h"

PBMImage::PBMImage() {
    ;
}

PBMImage::PBMImage(std::size_t rows, std::size_t cols, Pixel*** pixels) :
    Image(rows, cols, pixels) {
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