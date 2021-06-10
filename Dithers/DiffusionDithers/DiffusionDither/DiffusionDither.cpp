#include "DiffusionDither.h"
#include <cmath>

DiffusionDither::DiffusionDither(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos) :
    dMatrixRows(dMatrixRows), dMatrixCols(dMatrixCols), pos(pos) {
    ;
}

void DiffusionDither::setDMatrix(unsigned int src[][MAX_DISTRIBUTION_MATRIX_COLS]) {
    for (std::size_t i = 0; i < this->dMatrixRows; ++i) {
        for (std::size_t j = 0; j < this->dMatrixCols; ++j) {
            this->dMatrix[i][j] = src[i][j];
        }
    }
}


void DiffusionDither::setUpDither(Image* image) {
    this->pixelsMaxValue = image->getPixels()[0][0].getMaxValue();
    this->threshold = (double) this->pixelsMaxValue / 2.0;
}

void DiffusionDither::distributeDifference(Image* image, double diff, std::size_t x, std::size_t y) {
    std::size_t endingRowIndex = std::min(x + this->dMatrixRows, image->getRows());
    std::size_t beginningColIndex = std::max(0, (int)y - (int)this->pos);
    std::size_t endingColIndex = std::min((int)y - (int)this->pos + this->dMatrixCols, image->getCols());
    unsigned int distributionCoefficient;
    for (std::size_t i = x; i < endingRowIndex; ++i) {
        for (std::size_t j = beginningColIndex; j < endingColIndex; ++j) {
            distributionCoefficient = this->dMatrix[i - x][j - ((int)y - (int)this->pos)];
            if (distributionCoefficient != 0) {
                image->getPixels()[i][j].incrementDitherValue(diff * (double)distributionCoefficient / this->distributionDivisor);
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
            difference = pixelValue + image->getPixels()[i][j].getDitherValue() - this->threshold;

            if (difference > EPS) {
                image->getPixels()[i][j].setValue(this->pixelsMaxValue);
                difference = -(this->pixelsMaxValue - this->threshold - difference);
            }
            else {
                image->getPixels()[i][j].setValue(this->pixelsMinValue);
                difference = this->threshold + difference - this->pixelsMinValue;
            }
            image->getPixels()[i][j].resetDitherValue();
            distributeDifference(image, difference, i, j);
        }
    }
}