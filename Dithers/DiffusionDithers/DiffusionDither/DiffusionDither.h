#ifndef DIFFUSION_DITHER_H
#define DIFFUSION_DITHER_H
#include "../../../Image/Image.h"
#include "../../../Pixel/Pixel.h"

/**
 * @brief Dither class that supports diffusion dithering.
 * 
 * Parent class.
 * 
 * Converts all images in black and white images.
 * Keeps file format.
 */
class DiffusionDither {
    protected:
        static const std::size_t MAX_DISTRIBUTION_MATRIX_ROWS = 3;
        static const std::size_t MAX_DISTRIBUTION_MATRIX_COLS = 5;
        const double EPS = 1.0 / (1 << 30);

        /**
         * @brief Rows in the specific distribution matrix
         * 
         */
        std::size_t dMatrixRows;

        /**
         * @brief Columns in the specific distribution matrix
         * 
         */
        std::size_t dMatrixCols;

        /**
         * @brief Position of current pixel.
         * 
         * Index of the pixel, whose error(offset) is being calcuated
         * in the first row of the distribution matrix
         */
        std::size_t pos;

        /**
         * @brief Number of parts in which the error is spit.
         * 
         */
        unsigned int distributionDivisor;

        /**
         * @brief Distribution matrix.
         * Holds how the error of a pixel is diffused by keeping
         * the number of parts diffused to the other pixels.
         */
        unsigned int dMatrix[MAX_DISTRIBUTION_MATRIX_ROWS][MAX_DISTRIBUTION_MATRIX_COLS];

        /**
         * @brief Threshold used for setting pixels either black or white
         * 
         */
        double threshold;

        unsigned int pixelsMaxValue;
        const unsigned int pixelsMinValue = 0;

        /**
         * @brief Sets distribution matrix.
         * 
         * Copies the values from the source matrix.
         * 
         * @param src source matrix
         */
        void setDMatrix(unsigned int src[][MAX_DISTRIBUTION_MATRIX_COLS]);

        /**
         * @brief Sets parameters, which depent on the image, being dithered.
         * 
         * Changes value of the attributes pixelsMaxValue and threshold.
         * 
         * @param image image, being dithered
         */
        void setUpDither(Image* image);

        /**
         * @brief Distributes error to the other pixels.
         * 
         * @param image image, being dithered
         * @param error error of the current pixel
         * @param x row coordinate of the current pixel
         * @param y column coordinate of the current pixel
         */
        void distributeError(Image* image, double error, std::size_t x, std::size_t y);
    public:
        DiffusionDither(std::size_t dMatrixRows, std::size_t dMatrixCols, std::size_t pos);

        void ditherImage(Image* image);
};

#endif