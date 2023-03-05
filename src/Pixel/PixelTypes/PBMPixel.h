#ifndef PBM_Pixel_H
#define PBM_Pixel_H

#include "../Pixel.h"

class PBMPixel : public Pixel {
    private:
        unsigned char value;

        const bool isBlack() const;
        const bool isWhite() const;

        const std::string toString() const;
    public:
        PBMPixel(unsigned char value);

        const double getValue() const;
        
};

#endif