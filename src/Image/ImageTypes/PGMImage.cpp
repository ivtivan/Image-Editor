#include "PGMImage.h"

PGMImage::PGMImage() {
    ;
}

PGMImage::PGMImage(Dimension dimension, Pixel*** pixels) :
    Image(dimension, pixels) {
    ;
}


const std::string PGMImage::getTypeID() const {
    return "P2";
}

PGMImage::~PGMImage() {
    ;
}