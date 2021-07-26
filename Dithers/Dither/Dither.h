#ifndef DITHER_H
#define DITHER_H

#include "../../Image/Image.h"
#include "../../Pixel/Pixel.h"

/**
 * @brief Dither class that supports dithering.
 * 
 * Parent class.
 */
class Dither {
    protected:
        /**
         * @brief Rows in the specific distribution/threshold matrix
         * 
         */
        std::size_t matrixRows;

        /**
         * @brief Columns in the specific distribution/threshold matrix
         * 
         */
        std::size_t matrixCols;

        /**
         * @brief Threshold used for setting pixels either black or white
         * 
         */
        double threshold;

        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

        /**
         * @brief Sets parameters, which depend on the image, being dithered.
         * 
         * @param image image, being dithered
         */
        virtual void setUpDither(Image* image);
    public:
        Dither(const std::size_t& matrixRows, const std::size_t& matrixCols);

        virtual void ditherImage(Image* image);
};

#endif