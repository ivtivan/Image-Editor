#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <string>
#include <sstream>

const std::size_t MAX_VALUES_COUNT = 3;


/**
 * @brief Supports working with pixels.
 * 
 * The value is either a number or in RGB format.
 */
class Pixel {
    private:
        bool isRGB;
        unsigned int maxValue;
        const unsigned int minValue = 0;

        unsigned int value[MAX_VALUES_COUNT];

        /** 
         * @brief Value obtained from diffusing errors when using diffusuion ditters.
         * 
         */
        double ditherValue = 0;

        /**
         * @brief Checks if a pixel is black.
         * 
         * A pixel is black if its value is equal to the max possible value.
         */
        const bool isBlack() const;

        /**
         * @brief Checks if a pixel is white.
         * 
         * A pixel is black if its value is equal to the min possible value.
         */
        const bool isWhite() const;
    public:
        Pixel();

        Pixel(const Pixel& pixel);
        Pixel& operator=(const Pixel& pixel);

        const unsigned int getMaxValue() const;

        /**
         * @brief Returns a representation of the pixel as a double.
         * 
         * If the image is in RGB format returns a greyscale color.
         * Otherwise, the exact value is returned.
         */
        const double getValue() const;

        /**
         * @brief Returns diffused error.
         * 
         */
        const double getDitherValue() const;

        /**
         * @brief Sets value of pixel.
         * 
         * If it is in RGB, the value is set to each color.
         */
        void setValue(const unsigned int value);

        /**
         * @brief Sets value of pixel through an array.
         * 
         * Marks the pixel as RGB.
         */
        void setValue(unsigned int value[MAX_VALUES_COUNT]);

        /**
         * @brief Sets value of pixel through string.
         * 
         * If it is in RGB, the value is set to each color.
         * 
         * @param value color in hex form
         */
        void setValue(std::string value);

        /**
         * @brief Sets max possible value of pixel.
         * 
         */
        void setMaxValue(const unsigned int maxValue);

        /**
         * @brief Sets RGB status.
         * 
         * Throws PixelException when setted to false if this might result in loss of data.
         * Sets max value to 255 and adjusts pixel value if RGB status was previously false 
         * and is set to true.
         */
        void setRGB(bool value);

        /**
         * @brief Sets RGB status of black or white pixel to false and changes max value to 1.
         * 
         * Throws PixelException when the pixel is neither black nor white.
         */
        void setBlackOrWhite();

        /**
         * @brief Swaps the two colors.
         * 
         * Throws PixelException when the pixel is neither black nor white.
         */
        void swapBlackAndWhite();

        void incrementDitherValue(const double incr);

        /**
         * @brief Sets diffused error from dithering to 0.
         * 
         */
        void resetDitherValue();

        /**
         * @brief Checks if a pixel is a shade of grey.
         * 
         * Black and white are counted as shades of grey.
         * A pixel which is not RGB is always grey.
         */
        const bool isGrey() const;

        const bool isBlackOrWhite() const;

        friend std::ostream& operator<<(std::ostream& os, Pixel pixel);
};

#endif