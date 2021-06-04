#ifndef DITHER_H
#define DITHER_H
#include "../../Image/Image.h"

class Dither {
    private:
        std::string algorithmName;

        const std::size_t MAX_DISTRIBUTION_MATRIX_ROWS = 3;
        const std::size_t MAX_DISTRIBUTION_MATRIX_COLS = 5;

        std::size_t dMatrixRows;
        std::size_t dMatrixCols;

        unsigned int pos;
        unsigned int dMatrix[MAX_DISTRIBUTION_MATRIX_ROWS][MAX_DISTRIBUTION_MATRIX_COLS] = { 0 };
        unsigned int errorDivisor;

        int nextRowErrors*;

        void setUpFS();
        void setUpJJN();
        void setUpStucki();
        void setUpAtkinson();
        void setUpBurkes();
        void setUpSierra();
        void setUpTRSierra();
        void setUpSieraLite();
        void setUp4Bayer();
        void setUp8Bayer();

        void setUpDither(Image* image);
    public:
        Dither(std::string algorithmName);

        void DitherImage(Image* image);

        ~Dither();
};

#endif