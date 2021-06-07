#ifndef NONDIFFUSION_DITHER_H
#define NONDIFFUSION_DITHER_H

#include "../../../Image/Image.h"
#include "../../../Pixel/Pixel.h"

class NondiffusionDither {
    private:
        static const std::size_t MAX_THRESHOLD_MATRIX_ROWS = 8;
        static const std::size_t MAX_THRESHOLD_MATRIX_COLS = 8;
        const double EPS = 1.0 / (1 << 30);

        std::size_t tMatrixRows;
        std::size_t tMatrixCols;

        double tMatrix[MAX_THRESHOLD_MATRIX_COLS][MAX_THRESHOLD_MATRIX_COLS];

        double threshold;
        double precisionValue;
        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

        void setUpDither(Image* image);
    public:
        NondiffusionDither(std::size_t tMatrixRows, std::size_t tMatrixCols);

        void ditherImage(Image* image);
};

#endif