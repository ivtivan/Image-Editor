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

void PBMImage::outputImage(std::ostream& os) const {
    outputType(os);
    outputDimension(os);
    outputPixels(os);
}


PBMImage::~PBMImage() {
    ;
}