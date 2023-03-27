#ifndef DIFFUSION_DITHER_H
#define DIFFUSION_DITHER_H

#include "../../Dither/Dither.h"

/**
 * @brief Dither class that supports diffusion dithering.
 * 
 * Inherith from Dither parent class.
 * Parent class.
 * 
 * Converts all images in black and white images.
 * Keeps file format.
 */
class DiffusionDither : public Dither {
    protected:
        static const std::size_t MAX_DISTRIBUTION_MATRIX_ROWS = 3;
        static const std::size_t MAX_DISTRIBUTION_MATRIX_COLS = 5;
        const double EPS = 1.0 / (1 << 30);

        /**
         *  Index of the pixel, whose error (offset) is being calculated
         *  in the first row of the distribution matrix
         */
        std::size_t pos;

        /**
         * Number of parts in which the error is split.
         */
        unsigned int distributionDivisor;

        /**
         *  Holds how the error of a pixel is diffused by keeping
         *  the number of parts diffused to the other pixels.
         */
        unsigned int dMatrix[MAX_DISTRIBUTION_MATRIX_ROWS][MAX_DISTRIBUTION_MATRIX_COLS];

        void setDMatrix(unsigned int src[][MAX_DISTRIBUTION_MATRIX_COLS]);

        /**
         *  Distributes error to the other pixels.
         */
        void distributeError(std::shared_ptr<Image> image, double error, std::size_t x, std::size_t y);

        void setUpDither(std::shared_ptr<Image> image);
    public:
        DiffusionDither(const std::size_t& matrixRows, const std::size_t& matrixCols, const std::size_t& pos);
        
        void ditherImage(std::shared_ptr<Image> image);
};

#endif