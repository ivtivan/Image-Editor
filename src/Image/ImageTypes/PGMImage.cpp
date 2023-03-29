#include "PGMImage.h"
#include "../../Pixel/PixelTypes/PGMPixel.h"

PGMImage::PGMImage() {
    ;
}

PGMImage::PGMImage(Dimension dimension, pixel_ptr_vector&& pixels) :
    Image(dimension, std::move(pixels)) {
    ;
}

void PGMImage::outputImage(std::ostream& os) const {
    outputType(os);
    outputDimension(os);
    outputMaxValue(os);
    outputPixels(os);
}

const std::string PGMImage::getTypeID() const {
    return "P2";
}

PGMImage::~PGMImage() {
    ;
}