#ifndef NONDIFFUSION_DITHER_H
#define NONDIFFUSION_DITHER_H

#include "../../../Image/Image.h"
#include "../../../Pixel/Pixel.h"

class NondiffusionDither {
    private:
        static const std::size_t MAX_THRESHOLD_MATRIX_DIMENSION = 8;
        const double EPS = 1.0 / (1 << 30);

        std::size_t dimension;

        double tMatrix[MAX_THRESHOLD_MATRIX_DIMENSION][MAX_THRESHOLD_MATRIX_DIMENSION];

        double threshold;
        double precisionValue;
        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

        void calculateMatrixthresholds();
        void setUpDither(Image* image);
    public:
        NondiffusionDither(std::size_t dimension);

        void ditherImage(Image* image);
};

#endif