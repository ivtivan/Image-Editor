#ifndef OREDERED_DITHER_H
#define OREDERED_DITHER_H

#include "../../../Image/Image.h"
#include "../../../Pixel/Pixel.h"

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
class OrderedDither {
    protected:
        static const std::size_t MAX_THRESHOLD_MATRIX_DIMENSION = 8;
        const double EPS = 1.0 / (1 << 30);

        /**
         * @brief Dimension of threshold matrix
         * 
         */
        std::size_t dimension;

        /**
         * @brief Threshold matrix
         * 
         */
        double tMatrix[MAX_THRESHOLD_MATRIX_DIMENSION][MAX_THRESHOLD_MATRIX_DIMENSION];

        /**
         * @brief Threshold used for setting pixels either black or white
         * 
         */
        double threshold;

        /**
         * @brief Mupltiplier of the value red from the threshold map
         * 
         */
        double precisionValue;

        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

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

         /**
         * @brief Sets parameters, which depend on the image, being dithered.
         * 
         * Changes value of the attributes pixelsMaxValue, precisonValue and threshold.
         * 
         * @param image image, being dithered
         */
        void setUpDither(Image* image);
    public:
        OrderedDither(std::size_t dimension);

        void ditherImage(Image* image);
};

#endif