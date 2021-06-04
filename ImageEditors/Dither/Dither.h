#ifndef DITHER_H
#define DITHER_H
#include "../../Image/Image.h"
#include "../../Pixel/Pixel.h"

class Dither {
    private:
        static const std::size_t MAX_DISTRIBUTION_MATRIX_ROWS = 3;
        static const std::size_t MAX_DISTRIBUTION_MATRIX_COLS = 5;
        static const std::size_t MAX_ERROR_MATRIX_ROWS = 3;
        const double EPS = 1.0 / (1 << 30);

        std::string algorithmName;

        std::size_t dMatrixRows;
        std::size_t dMatrixCols;

        unsigned int pos;
        unsigned int dMatrix[MAX_DISTRIBUTION_MATRIX_ROWS][MAX_DISTRIBUTION_MATRIX_COLS] = { 0 };
        unsigned int distributionDivisor;

        double threshold;
        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

        void setUpDistributionMatrix(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos);
        void distributeDifference(Image* image, double diff, std::size_t x, std::size_t y);

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
};

#endif