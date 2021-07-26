#include "DiffusionDither.h"
#include <cmath>

DiffusionDither::DiffusionDither(const std::size_t& matrixRows, const std::size_t& matrixCols, const std::size_t& pos) :
    Dither(matrixRows, matrixCols), pos(pos) {
    ;
}

void DiffusionDither::setDMatrix(unsigned int src[][MAX_DISTRIBUTION_MATRIX_COLS]) {
    for (std::size_t i = 0; i < this->matrixRows; ++i) {
        for (std::size_t j = 0; j < this->matrixCols; ++j) {
            this->dMatrix[i][j] = src[i][j];
        }
    }
}


void DiffusionDither::setUpDither(Image* image) {
    this->pixelsMaxValue = image->getPixels()[0][0].getMaxValue();
    this->threshold = (double) this->pixelsMaxValue / 2.0;
}

void DiffusionDither::distributeError(Image* image, double error, std::size_t x, std::size_t y) {
    std::size_t endingRowIndex = std::min(x + this->matrixRows, image->getRows());
    std::size_t beginningColIndex = std::max(0, (int)y - (int)this->pos);
    std::size_t endingColIndex = std::min((int)y - (int)this->pos + this->matrixCols, image->getCols());
    unsigned int distributionCoefficient;
    for (std::size_t i = x; i < endingRowIndex; ++i) {
        for (std::size_t j = beginningColIndex; j < endingColIndex; ++j) {
            distributionCoefficient = this->dMatrix[i - x][j - ((int)y - (int)this->pos)];
            if (distributionCoefficient != 0) {
                image->getPixels()[i][j].incrementDitherValue(error * (double)distributionCoefficient / this->distributionDivisor);
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
            distributeError(image, difference, i, j);
        }
    }
}