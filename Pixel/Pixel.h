#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <string>
#include <sstream>

const std::size_t MAX_VALUES_COUNT = 3;


/**
 * Pixel class
 * The value is either a number or in RGB format.
 */
class Pixel {
    private:
        bool isRGB;
        unsigned int maxValue;
        const unsigned int minValue = 0;
        unsigned int value[MAX_VALUES_COUNT];

        /**
         * Value obtained from diffusing errors
         * when using diffusuion ditters.
         */
        double ditherValue = 0;
    public:
        Pixel();

        Pixel(const Pixel& pixel);
        Pixel& operator=(const Pixel& pixel);

        /**
         * Sets value of pixel.
         * If it is in RGB, the value is set to each color.
         */
        void setValue(const unsigned int value);

        /**
         * Sets value of pixel through an array.
         * Makes the pixel in RGB.
         */
        void setValue(unsigned int value[MAX_VALUES_COUNT]);

        /**
         * Sets value of pixel.
         * The parameter is in hex format.
         * If it is in RGB, the value is set to each color.
         */
        void setValue(std::string value);

        /**
         * Sets max possible value of pixel.
         */
        void setMaxValue(const unsigned int maxValue);

        void incrementDitherValue(const double incr);

        /**
         * Sets diffused error from dithering to 0.
         */
        void resetDitherValue();

        const unsigned int getMaxValue() const;

        /**
         * If the image is in RGB format returns a greyscale color.
         * Otherwise, the exact value is returned.
         */
        const double getValue() const;

        /**
         * Returns diffused error.
         */
        const double getDitherValue() const;

        friend std::ostream& operator<<(std::ostream& os, Pixel pixel);
};

#endif