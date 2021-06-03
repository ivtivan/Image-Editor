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
    public:
        Pixel();

        Pixel(const Pixel& pixel);
        Pixel& operator=(const Pixel& pixel);

        void setValue(const unsigned int value);
        void setMaxValue(const unsigned int maxValue);
        void setRGBValue(unsigned int value[MAX_VALUES_COUNT]);

        friend std::ostream& operator<<(std::ostream& os, Pixel pixel);
};

#endif