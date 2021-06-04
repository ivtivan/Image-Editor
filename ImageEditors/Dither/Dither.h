#ifndef DITHER_H
#define DITHER_H
#include "../../Image/Image.h"
#include "../../Pixel/Pixel.h"

class Dither {
    private:
        const std::size_t MAX_DISTRIBUTION_MATRIX_ROWS = 3;
        const std::size_t MAX_DISTRIBUTION_MATRIX_COLS = 5;
        const std::size_t MAX_ERROR_MATRIX_ROWS = 3;
        const double EPS = 1.0 / (1 << 30);

        std::string algorithmName;

        std::size_t dMatrixRows;
        std::size_t dMatrixCols;

        unsigned int pos;
        unsigned int dMatrix[MAX_DISTRIBUTION_MATRIX_ROWS][MAX_DISTRIBUTION_MATRIX_COLS] = { 0 };
        unsigned int distributionDivisor;

        int* errorMatrix[MAX_ERROR_MATRIX_ROWS];
        std::size_t eMatrixRows;
        std::size_t eMatrixesCols;

        double threshold;
        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

        void setUpDistributionMatrix(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos);
        void setUpErrorMatrix(std::size_t eMatrixRows);

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

        void ditherImage(Image* image);

        ~Dither();
};

#endif