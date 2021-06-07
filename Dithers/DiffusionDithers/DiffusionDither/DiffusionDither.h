#ifndef DIFFUSION_DITHER_H
#define DIFFUSION_DITHER_H
#include "../../../Image/Image.h"
#include "../../../Pixel/Pixel.h"

class DiffusionDither {
    protected:
        static const std::size_t MAX_DISTRIBUTION_MATRIX_ROWS = 3;
        static const std::size_t MAX_DISTRIBUTION_MATRIX_COLS = 5;
        const double EPS = 1.0 / (1 << 30);

        std::size_t dMatrixRows;
        std::size_t dMatrixCols;

        std::size_t pos;
        unsigned int dMatrix[MAX_DISTRIBUTION_MATRIX_ROWS][MAX_DISTRIBUTION_MATRIX_COLS];
        unsigned int distributionDivisor;

        double threshold;
        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

        void setDMatrix(unsigned int src[][MAX_DISTRIBUTION_MATRIX_COLS]);
        void setUpDither(Image* image);
        void distributeDifference(Image* image, double diff, std::size_t x, std::size_t y);
    public:
        DiffusionDither(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos);

        void ditherImage(Image* image);
};

#endif