#ifndef PGM_PIXEL_H
#define PGM_PIXEL_H

#include "../Pixel.h"

class PGMPixel : public Pixel {
    private:
        unsigned short value;

        const bool isBlack() const;
        const bool isWhite() const;

        const std::string toString() const;
    public:
        PGMPixel(unsigned short value, unsigned short maxValue);

        const double getValue() const;

        void setToMaxValue();
        void setToMinValue();      
};

#endif