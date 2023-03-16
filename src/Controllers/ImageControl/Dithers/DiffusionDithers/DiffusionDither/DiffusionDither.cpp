#include "DiffusionDither.h"
#include <cmath>

DiffusionDither::DiffusionDither(const std::size_t& matrixRows, const std::size_t& matrixCols, const std::size_t& pos) :
    Dither(matrixRows, matrixCols), pos(pos) {
    ;
}

void DiffusionDither::setDMatrix(unsigned int src[][MAX_DISTRIBUTION_MATRIX_COLS]) {
    for (std::size_t i = 0; i < matrixRows; ++i) {
        for (std::size_t j = 0; j < matrixCols; ++j) {
            dMatrix[i][j] = src[i][j];
        }
    }
}


void DiffusionDither::setUpDither(Image* image) {
    pixelsMaxValue = image->getPixels()[0][0].getMaxValue();
    threshold = (double) pixelsMaxValue / 2.0;
}

void DiffusionDither::distributeError(Image* image, double error, std::size_t x, std::size_t y) {
    std::size_t endingRowIndex = std::min(x + matrixRows, image->getRows());
    std::size_t beginningColIndex = std::max((std::size_t)0, (std::size_t)y - (std::size_t)pos);
    std::size_t endingColIndex = std::min((std::size_t)y - (std::size_t)pos + matrixCols, image->getCols());
    unsigned int distributionCoefficient;
    for (std::size_t i = x; i < endingRowIndex; ++i) {
        for (std::size_t j = beginningColIndex; j < endingColIndex; ++j) {
            distributionCoefficient = dMatrix[i - x][j - ((std::size_t)y - (std::size_t)pos)];
            if (distributionCoefficient != 0) {
                image->getPixels()[i][j].incrementDitherValue(error * (double)distributionCoefficient / distributionDivisor);
            }
        }
    }
}

void DiffusionDither::ditherImage(Image* image) {
    setUpDither(image);

    double pixelValue;
    double difference;

    std::size_t imageRows = image->getRows();
    std::size_t imageCols = image->getCols();

    for (std::size_t i = 0; i < imageRows; ++i) {
        for (std::size_t j = 0; j < imageCols; ++j) {
            pixelValue = image->getPixels()[i][j].getValue();
            difference = pixelValue + image->getPixels()[i][j].getDitherValue() - threshold;

            if (difference > EPS) {
                image->getPixels()[i][j].setToMaxValue();
                difference = -(pixelsMaxValue - threshold - difference);
            }
            else {
                image->getPixels()[i][j].setToMinValue();
                difference = threshold + difference - pixelsMinValue;
            }
            image->getPixels()[i][j].resetDitherValue();
            distributeError(image, difference, i, j);
        }
    }
}