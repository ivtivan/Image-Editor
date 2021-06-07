#include "DiffusionDither.h"
#include <cmath>

DiffusionDither(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos) :
    dMatrixRows(dMatrixRows), dMatrixCols(dMatrixCols), pos(pos) {
    ;
}

void DiffusionDither::setUpDither(Image* image) {
    this->pixelsMaxValue = image->getPixels()[0][0].getMaxValue();
    this->threshold = (double) this->pixelsMaxValue / 2.0;
}

void DiffusionDither::distributeDifference(Image* image, double diff, std::size_t x, std::size_t y) {
    std::size_t endingRowIndex = std::min(x + dMatrixRows, image->getRows());
    std::size_t beginningColIndex = std::max(0, (int)y - (int)pos);
    std::size_t endingColIndex = std::min(beginningColIndex + dMatrixCols, image->getCols());
    unsigned int distributionCoeficient;
    for (std::size_t i = x; i < endingRowIndex; ++i) {
        for (std::size_t j = beginningColIndex; j < endingColIndex; ++j) {
            distributionCoeficient = dMatrix[i - x][j - beginningColIndex];
            if (distributionCoeficient != 0) {
                image->getPixels()[i][j].incrementDitherValue(diff * (double)distributionCoeficient / this->distributionDivisor);
            }
        }
    }
}

void DiffusionDither::ditherImage(Image* image) {
    setUpDither(image);

    double pixelValue;
    double difference;

    std::size_t imageRows = image->getRows();
    std::size_t imageCols = image->getRows();
    
    for (std::size_t i = 0; i < imageRows; ++i) {
        for (std::size_t j = 0; j < imageCols; ++j) {
            pixelValue = image->getPixels()[i][j].getValue();
            difference = this->threshold + image->getPixels()[i][j].getDitherValue() - pixelValue;
            if (difference > EPS) {
                image->getPixels()[i][j].setValue(this->pixelsMaxValue);
            }
            else {
                image->getPixels()[i][j].setValue(this->pixelsMinValue);
            }
            image->getPixels()[i][j].resetDitherValue();
            distributeDifference(image, difference, i, j);
        }
    }
}