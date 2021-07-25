#include "OrderedDither.h"

OrderedDither::OrderedDither(std::size_t dimension) :
    dimension(dimension) {
    ;
}

void OrderedDither::setTMatrix(double src[][MAX_THRESHOLD_MATRIX_DIMENSION]) {
    for (std::size_t i = 0; i < this->dimension; ++i) {
        for (std::size_t j = 0; j < this->dimension; ++j) {
            this->tMatrix[i][j] = src[i][j];
        }
    }
}

void OrderedDither::calculateMatrixthresholds() {
    for (std::size_t i = 0; i < this->dimension; ++i) {
        for (std::size_t j = 0; j < this->dimension; ++j) {
            tMatrix[i][j] = (tMatrix[i][j] + 1.0) / (double)(dimension * dimension) - 0.5;
        }
    }
}

void OrderedDither::setUpDither(Image* image) {
    this->pixelsMaxValue = image->getPixels()[0][0].getMaxValue();
    this->threshold = (double) this->pixelsMaxValue / 2.0;
    this->precisionValue = (double) this->pixelsMaxValue / 2.0;
    calculateMatrixthresholds();
}

void OrderedDither::ditherImage(Image* image) {
    setUpDither(image);

    double pixelValue, alteredValue;
    double factor;

    std::size_t imageRows = image->getRows();
    std::size_t imageCols = image->getCols();

    for (std::size_t i = 0; i < imageRows; ++i) {
        for (std::size_t j = 0; j < imageCols; ++j) {
            pixelValue = image->getPixels()[i][j].getValue();
            factor = tMatrix[i % dimension][j % dimension];

            alteredValue = pixelValue + precisionValue * factor;

            if (alteredValue - threshold > EPS) {
                image->getPixels()[i][j].setValue(this->pixelsMaxValue);
            }
            else {
                image->getPixels()[i][j].setValue(this->pixelsMinValue);
            }
        }
    }
}