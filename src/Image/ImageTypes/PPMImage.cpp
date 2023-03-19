#include "PPMImage.h"

PPMImage::PPMImage(Dimension dimension, Pixel*** pixels) :
    Image(dimension, pixels) {
    ;
}

const std::string PPMImage::getTypeID() const {
    return "P3";
}

PPMImage::~PPMImage() {
    ;
}