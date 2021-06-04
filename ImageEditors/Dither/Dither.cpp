#include "Dither.h"

Dither::Dither(std::string algorithmName) : algorithmName(algorithmName) {

}

void Dither::setUpFS() {
    this->rows = 2;
    this->cols = 3;
    this->pos = 1;
    this->dMatrix[0][2] = 7;
    this->dMatrix[1][0] = 3;
    this->dMatrix[1][1] = 5;
    this->dMatrix[1][2] = 1;
    this->errorDivisor = 16;
}

void Dither::setUpJJN() {
    this->rows = 3;
    this->cols = 5;
    this->pos = 2;
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
    this->errorDivisor = 48;
}

void Dither::setUpDither(Image* image) {
    errorDivisor = new int[image->getcols()];

    if (this->algorithmName == "FS") {

    }
    else if (this->algorithmName == "JJN") {

    }
    else if (this->algorithmName == "Stucki") {

    }
    else if (this->algorithmName == "Atkinson") {

    }
    else if (this->algorithmName == "Burkes") {

    }
    else if (this->algorithmName == "Sierra") {

    }
    else if (this->algorithmName == "TRSierra") {

    }
    else if (this->algorithmName == "SieraLite") {

    }
    else if (this->algorithmName == "4Bayer") {

    }
    else if (this->algorithmName == "8Bayer") {

    }
}

void Dither::DitherImage(Image* image) {
    setUpDither();

    for (std::size_t i = 0; i < image->getRows(); ++i) {
        for (std::size_t j = 0; j < image->getCols(); ++j) {

        }
    }
}

Dither::~Dither() {
    delete this->nextRowErrors;
}