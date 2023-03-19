#ifndef PBM_Pixel_H
#define PBM_Pixel_H

#include "../Pixel.h"

class PBMPixel : public Pixel {
    private:
        unsigned char value;

        bool isBlack() const;
        bool isWhite() const;

        const std::string toString() const;
    public:
        PBMPixel(unsigned char value);

        double getValue() const;

        void setToMaxValue();
        void setToMinValue();      
};

#endif