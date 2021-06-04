#include "Dither.h"

Dither::Dither(std::string algorithmName) : algorithmName(algorithmName) {

}

void Dither::setUpDistributionMatrix(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos) {
    this->dMatrixRows = dMatrixRows;
    this->dMatrixCols = dMatrixCols;
    this->pos = pos;
}

void Dither::setUpErrorMatrix(std::size_t eMatrixRows) {
    this->eMatrixRows = eMatrixRows;
    this->errorMatrix[0] = new int[this->eMatrixCols];

    if (this->eMatrixRows == 2) {
        try {
            this->errorMatrix[1] = new int[this->eMatrixCols];
        }
        catch(const bad_alloc&) {
            delete[] errorMatrix[0];
        }
    }
}

void Dither::setUpFS() {
    setUpErrorMatrix(2);
    setUpDistributionMatrix(2, 3, 1);

    this->dMatrix[0][2] = 7;
    this->dMatrix[1][0] = 3;
    this->dMatrix[1][1] = 5;
    this->dMatrix[1][2] = 1;
    this->errorDivisor = 16;
}

void Dither::setUpJJN() {
    setUpErrorMatrix(2);
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
    this->errorDivisor = 48;
}

void Dither::setUpStucki() {
    setUpErrorMatrix(2);
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
    this->errorDivisor = 42;
}

void Dither::setUpAtkinson() {
    setUpErrorMatrix(2);
    setUpDistributionMatrix(3, 4, 1);

    this->dMatrix[0][2] = 1;
    this->dMatrix[0][3] = 1;
    this->dMatrix[1][0] = 1;
    this->dMatrix[1][1] = 1;
    this->dMatrix[1][2] = 1;
    this->dMatrix[2][1] = 1;
    this->errorDivisor = 8;
}

void Dither::setUpBurkes() {
    setUpErrorMatrix(1);
    setUpDistributionMatrix(2, 5, 2);

    this->dMatrix[0][3] = 8;
    this->dMatrix[0][4] = 4;
    this->dMatrix[1][0] = 2;
    this->dMatrix[1][1] = 4;
    this->dMatrix[1][2] = 8;
    this->dMatrix[1][3] = 4;
    this->dMatrix[1][4] = 2;
    this->errorDivisor = 32;
}

void Dither::setUpSierra() {
    setUpErrorMatrix(2);
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
    this->errorDivisor = 32;
}

void Dither::setUpTRSierra() {
    setUpErrorMatrix(1);
    setUpDistributionMatrix(2, 5, 2);
    this->dMatrix[0][3] = 4;
    this->dMatrix[0][4] = 3;
    this->dMatrix[1][0] = 1;
    this->dMatrix[1][1] = 2;
    this->dMatrix[1][2] = 3;
    this->dMatrix[1][3] = 2;
    this->dMatrix[1][4] = 1;
    this->errorDivisor = 16;
}

void Dither::setUpSieraLite() {
    setUpErrorMatrix(1);
    setUpDistributionMatrix(2, 3, 1);

    this->dMatrix[0][2] = 2;
    this->dMatrix[1][0] = 1;
    this->dMatrix[1][1] = 1;
    this->errorDivisor = 4;
}

void Dither::setUp4Bayer() {
    // TODO
}

void Dither::setUp8Bayer() {
    // TODO
}

void Dither::setUpDither(Image* image) {
    eMatrixesCols = image->getCols();

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

void Dither::ditherImage(Image* image) {
    setUpDither();

    for (std::size_t i = 0; i < image->getRows(); ++i) {
        for (std::size_t j = 0; j < image->getCols(); ++j) {

        }
    }
}

Dither::~Dither() {
    for (std::size_t i = 0; i < MAX_ERROR_MATRIX_ROWS; ++i) {
        delete[] this->errorMatrix[i];
    }
}