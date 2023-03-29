#include "PPMImage.h"
#include "../../Pixel/PixelTypes/PPMPixel.h"

PPMImage::PPMImage(Dimension dimension, pixel_ptr_vector&& pixels) :
    Image(dimension, std::move(pixels)) {
    ;
}

const std::string PPMImage::getTypeID() const {
    return "P3";
}

void PPMImage::outputImage(std::ostream& os) const {
    outputType(os);
    outputDimension(os);
    outputMaxValue(os);
    outputPixels(os);
}

PPMImage::~PPMImage() {
    ;
}