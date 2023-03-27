#include "PBMImage.h"
#include "../../Pixel/PixelTypes/PBMPixel.h"
#include <iostream>

PBMImage::PBMImage() {
    ;
}

PBMImage::PBMImage(Dimension dimension, pixel_ptr_vector&& pixels) :
    Image(dimension, std::move(pixels)) {
    ;
}

const std::string PBMImage::getTypeID() const {
    return "P1";
}


PBMImage::~PBMImage() {
    ;
}