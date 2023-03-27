#include "PPMImage.h"
#include "../../Pixel/PixelTypes/PPMPixel.h"

PPMImage::PPMImage(Dimension dimension, pixel_ptr_vector&& pixels) :
    Image(dimension, std::move(pixels)) {
    ;
}

const std::string PPMImage::getTypeID() const {
    return "P3";
}

PPMImage::~PPMImage() {
    ;
}