#ifndef PPM_PIXEL_H
#define PPM_PIXEL_H

#include "../Pixel.h"

class PPMPixel : public Pixel {
    private:
        unsigned short value[3];

        bool isBlack() const;
        bool isWhite() const;

        const std::string toString() const;
    public:
        PPMPixel(unsigned short value[3], unsigned short maxValue);
        PPMPixel(std::string hex);

        double getValue() const;

        void setToMaxValue();
        void setToMinValue();
};

#endif