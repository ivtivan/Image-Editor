#include "PBMImage.h"

PBMImage::PBMImage() {
    ;
}

PBMImage::PBMImage(Dimension dimension, Pixel*** pixels) :
    Image(dimension, pixels) {
    ;
}

const std::string PBMImage::getTypeID() const {
    return "P1";
}

PBMImage::~PBMImage() {
    ;
}