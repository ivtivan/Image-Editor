#include "OrderedDither.h"

OrderedDither::OrderedDither(const std::size_t& dimension) :
    Dither(dimension, dimension) {
    ;
}

void OrderedDither::setTMatrix(double src[][MAX_THRESHOLD_MATRIX_DIMENSION]) {
    for (std::size_t i = 0; i < matrixRows; ++i) {
        for (std::size_t j = 0; j < matrixCols; ++j) {
            tMatrix[i][j] = src[i][j];
        }
    }
}

void OrderedDither::calculateMatrixthresholds() {
    for (std::size_t i = 0; i < matrixRows; ++i) {
        for (std::size_t j = 0; j < matrixCols; ++j) {
            tMatrix[i][j] = (tMatrix[i][j] + 1.0) / (double)(matrixRows * matrixCols) - 0.5;
        }
    }
}

void OrderedDither::setUpDither(Image* image) {
    pixelsMaxValue = image->getPixelAt(Point(0, 0))->getMaxValue();
    threshold = (double) pixelsMaxValue / 2.0;
    precisionValue = (double) pixelsMaxValue / 2.0;
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
            pixelValue = image->getPixelAt(Point(i, j))->getValue();
            factor = tMatrix[i % matrixRows][j % matrixCols];

            alteredValue = pixelValue + precisionValue * factor;

            if (alteredValue - threshold > EPS) {
                image->getPixelAt(Point(i, j))->setToMaxValue();
            }
            else {
                image->getPixelAt(Point(i, j))->setToMinValue();
            }
        }
    }
}