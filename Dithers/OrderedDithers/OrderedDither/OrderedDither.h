#ifndef OREDERED_DITHER_H
#define OREDERED_DITHER_H

#include "../../Dither/Dither.h"

/**
 * @brief Dither class that supports ordered dithering.
 * 
 * Parent class.
 * 
 * Converts all images in black and white images.
 * Keeps file format.
 * 
 * Described in https://en.wikipedia.org/wiki/Ordered_dithering.
 */
class OrderedDither : public Dither {
    protected:
        static const std::size_t MAX_THRESHOLD_MATRIX_DIMENSION = 8;
        const double EPS = 1.0 / (1 << 30);

        /**
         * @brief Threshold matrix
         * 
         */
        double tMatrix[MAX_THRESHOLD_MATRIX_DIMENSION][MAX_THRESHOLD_MATRIX_DIMENSION];

        /**
         * @brief Mupltiplier of the value red from the threshold map
         * 
         */
        double precisionValue;

        /**
         * @brief Sets threshold matrix.
         * 
         * Copies the values from the source matrix.
         * 
         * @param src source matrix
         */
        void setTMatrix(double src[][MAX_THRESHOLD_MATRIX_DIMENSION]);

        /**
         * @brief Precalculates the threshold matrix.
         * 
         */
        void calculateMatrixthresholds();

        void setUpDither(Image* image);
    public:
        OrderedDither(const std::size_t& dimension);

        void ditherImage(Image* image);
};

#endif