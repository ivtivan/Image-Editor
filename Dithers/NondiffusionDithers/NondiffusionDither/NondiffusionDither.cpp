#include "NondiffusionDither.h"

NondiffusionDither(std::size_t dimension) :
    dimension(dimension) {
    ;
}

void DiffusionDither::calculateMatrixthresholds() {
    std::size_t imageRows = image->getRows();
    std::size_t imageCols = image->getRows();

    for (std::size_t i = 0; i < imageRows; ++i) {
        for (std::size_t j = 0; j < imageCols; ++j) {
            tMatrix[i][j] = (tMatrix[i][j] + 1.0) / (dimension * dimension) - 0.5;
        }
    }
}

void DiffusionDither::setUpDither(Image* image) {
    this->pixelsMaxValue = image->getPixels()[0][0].getMaxValue();
    this->threshold = (double) this->pixelsMaxValue / 2.0;
    this->precisionValue = (double) this->pixelsMaxValue / 2.0;
    calculateMatrixthresholds();
}

void DiffusionDither::ditherImage(Image* image) {
    setUpDither(image);

    double pixelValue, alteredValue;
    double factor;

    std::size_t imageRows = image->getRows();
    std::size_t imageCols = image->getRows();

    for (std::size_t i = 0; i < imageRows; ++i) {
        for (std::size_t j = 0; j < imageCols; ++j) {
            pixelValue = image->getPixels()[i][j].getValue();
            factor = tMatrix[i % dimension][j % dimension];

            if (alteredValue - pixelValue > EPS) {
                image->getPixels()[i][j].setValue(this->pixelsMaxValue);
            }
            else {
                image->getPixels()[i][j].setValue(this->pixelsMinValue);
            }
        }
    }
}