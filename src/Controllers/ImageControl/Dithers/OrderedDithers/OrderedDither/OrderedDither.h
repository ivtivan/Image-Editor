#ifndef OREDERED_DITHER_H
#define OREDERED_DITHER_H

#include "../../Dither/Dither.h"

/**
 * @brief Dither class that supports ordered dithering.
 */
class OrderedDither : public Dither {
    protected:
        static const std::size_t MAX_THRESHOLD_MATRIX_DIMENSION = 8;
        const double EPS = 1.0 / (1 << 30);

        /**
         * Threshold matrix
         */
        double tMatrix[MAX_THRESHOLD_MATRIX_DIMENSION][MAX_THRESHOLD_MATRIX_DIMENSION];

        /**
         * Mupltiplier of the value red from the threshold map
         */
        double precisionValue;

        void setTMatrix(double src[][MAX_THRESHOLD_MATRIX_DIMENSION]);
        
        void calculateMatrixthresholds();

        void setUpDither(Image* image);
    public:
        OrderedDither(const std::size_t& dimension);

        void ditherImage(Image* image);
};

#endif