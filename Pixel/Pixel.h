#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

const std::size_t MAX_VALUES_COUNT = 3;

class Pixel {
    private:
        bool isRGB;
        unsigned int maxValue;
        const unsigned int minValue = 0;
        unsigned int value[MAX_VALUES_COUNT];

        double ditherValue = 0;
    public:
        Pixel();

        Pixel(const Pixel& pixel);
        Pixel& operator=(const Pixel& pixel);

        void setValue(const unsigned int value);
        void setMaxValue(const unsigned int maxValue);
        void setRGBValue(unsigned int value[MAX_VALUES_COUNT]);

        void incrementDitherValue(const double incr);
        void resetDitherValue();

        const unsigned int getMaxValue() const;
        const double getValue() const;
        const double getDitherValue() const;

        friend std::ostream& operator<<(std::ostream& os, Pixel pixel);
};

#endif