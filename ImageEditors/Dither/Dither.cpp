#include "Dither.h"
#include <cmath>

Dither::Dither(std::string algorithmName) : algorithmName(algorithmName) {

}

void Dither::setUpDistributionMatrix(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos) {
    this->dMatrixRows = dMatrixRows;
    this->dMatrixCols = dMatrixCols;
    this->pos = pos;
}

void Dither::setUpFS() {
    setUpDistributionMatrix(2, 3, 1);

    this->dMatrix[0][2] = 7;
    this->dMatrix[1][0] = 3;
    this->dMatrix[1][1] = 5;
    this->dMatrix[1][2] = 1;
    this->distributionDivisor = 16;
}

void Dither::setUpJJN() {
    setUpDistributionMatrix(3, 5, 2);

    this->dMatrix[0][3] = 7;
    this->dMatrix[0][4] = 5;
    this->dMatrix[1][0] = 3;
    this->dMatrix[1][1] = 5;
    this->dMatrix[1][2] = 7;
    this->dMatrix[1][3] = 5;
    this->dMatrix[1][4] = 3;
    this->dMatrix[2][0] = 1;
    this->dMatrix[2][1] = 3;
    this->dMatrix[2][2] = 5;
    this->dMatrix[2][3] = 3;
    this->dMatrix[2][4] = 1;
    this->distributionDivisor = 48;
}

void Dither::setUpStucki() {
    setUpDistributionMatrix(3, 5, 2);
    
    this->dMatrix[0][3] = 8;
    this->dMatrix[0][4] = 4;
    this->dMatrix[1][0] = 2;
    this->dMatrix[1][1] = 4;
    this->dMatrix[1][2] = 8;
    this->dMatrix[1][3] = 4;
    this->dMatrix[1][4] = 2;
    this->dMatrix[2][0] = 1;
    this->dMatrix[2][1] = 2;
    this->dMatrix[2][2] = 4;
    this->dMatrix[2][3] = 2;
    this->dMatrix[2][4] = 1;
    this->distributionDivisor = 42;
}

void Dither::setUpAtkinson() {
    setUpDistributionMatrix(3, 4, 1);

    this->dMatrix[0][2] = 1;
    this->dMatrix[0][3] = 1;
    this->dMatrix[1][0] = 1;
    this->dMatrix[1][1] = 1;
    this->dMatrix[1][2] = 1;
    this->dMatrix[2][1] = 1;
    this->distributionDivisor = 8;
}

void Dither::setUpBurkes() {
    setUpDistributionMatrix(2, 5, 2);

    this->dMatrix[0][3] = 8;
    this->dMatrix[0][4] = 4;
    this->dMatrix[1][0] = 2;
    this->dMatrix[1][1] = 4;
    this->dMatrix[1][2] = 8;
    this->dMatrix[1][3] = 4;
    this->dMatrix[1][4] = 2;
    this->distributionDivisor = 32;
}

void Dither::setUpSierra() {
    setUpDistributionMatrix(3, 5, 2);

    this->dMatrix[0][3] = 5;
    this->dMatrix[0][4] = 3;
    this->dMatrix[1][0] = 2;
    this->dMatrix[1][1] = 4;
    this->dMatrix[1][2] = 5;
    this->dMatrix[1][3] = 4;
    this->dMatrix[1][4] = 2;
    this->dMatrix[2][1] = 2;
    this->dMatrix[2][2] = 3;
    this->dMatrix[2][3] = 2;
    this->distributionDivisor = 32;
}

void Dither::setUpTRSierra() {
    setUpDistributionMatrix(2, 5, 2);
    this->dMatrix[0][3] = 4;
    this->dMatrix[0][4] = 3;
    this->dMatrix[1][0] = 1;
    this->dMatrix[1][1] = 2;
    this->dMatrix[1][2] = 3;
    this->dMatrix[1][3] = 2;
    this->dMatrix[1][4] = 1;
    this->distributionDivisor = 16;
}

void Dither::setUpSieraLite() {
    setUpDistributionMatrix(2, 3, 1);

    this->dMatrix[0][2] = 2;
    this->dMatrix[1][0] = 1;
    this->dMatrix[1][1] = 1;
    this->distributionDivisor = 4;
}

void Dither::setUp4Bayer() {
    // TODO
}

void Dither::setUp8Bayer() {
    // TODO
}

void Dither::setUpDither(Image* image) {
    this->threshold = (double)(image->getPixels()[0][0].getMaxValue()) / 2.0;
    this->pixelsMaxValue = image->getPixels()[0][0].getMaxValue();

    if (this->algorithmName == "FS") {
        setUpFS();
    }
    else if (this->algorithmName == "JJN") {
        setUpJJN();
    }
    else if (this->algorithmName == "Stucki") {
        setUpStucki();
    }
    else if (this->algorithmName == "Atkinson") {
        setUpAtkinson();
    }
    else if (this->algorithmName == "Burkes") {
        setUpBurkes();
    }
    else if (this->algorithmName == "Sierra") {
        setUpSierra();
    }
    else if (this->algorithmName == "TRSierra") {
        setUpTRSierra();
    }
    else if (this->algorithmName == "SieraLite") {
        setUpSieraLite();
    }
    else if (this->algorithmName == "4Bayer") {
        setUp4Bayer();
    }
    else if (this->algorithmName == "8Bayer") {
        setUp8Bayer();
    }
}

void Dither::distributeDifference(Image* image, double diff, std::size_t x, std::size_t y) {
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

void Dither::ditherImage(Image* image) {
    setUpDither(image);

    double pixelValue;
    double difference;
    for (std::size_t i = 0; i < image->getRows(); ++i) {
        for (std::size_t j = 0; j < image->getCols(); ++j) {
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