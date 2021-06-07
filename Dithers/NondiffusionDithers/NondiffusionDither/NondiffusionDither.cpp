#include "NondiffusionDither.h"
#include <cmath>

NondiffusionDither(std::size_t dMatrixRows, std::size_t tMatrixCols) :
    dMatrixRows(tMatrixRows), tMatrixCols(tMatrixCols) {
    ;
}

void DiffusionDither::setUpDither(Image* image) {
    this->pixelsMaxValue = image->getPixels()[0][0].getMaxValue();
    this->threshold = (double) this->pixelsMaxValue / 2.0;
    this->precisionValue = (double) this->pixelsMaxValue / 2.0;
}

void DiffusionDither::ditherImage(Image* image) {
    setUpDither(image);

    double pixelValue, alteredValue;
    double factor;
    for (std::size_t i = 0; i < image->getRows(); ++i) {
        for (std::size_t j = 0; j < image->getCols(); ++j) {
            pixelValue = image->getPixels()[i][j].getValue();
            factor = tMatrix[i % tMatrixRows][j % tMatrixCols];

            if (alteredValue - pixelValue > EPS) {
                image->getPixels()[i][j].setValue(this->pixelsMaxValue);
            }
            else {
                image->getPixels()[i][j].setValue(this->pixelsMinValue);
            }
        }
    }
}