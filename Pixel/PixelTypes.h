#ifndef PIXEL_TYPES_H
#define PIXEL_TYPES_H

#include "Pixel.h"

class PBMPixel : public Pixel {
    private:
        unsigned char value;

        const bool isBlack() const;
        const bool isWhite() const;

        const std::string toString() const;
    public:
        PBMPixel(unsigned char value);
        
};

class PGMPixel : public Pixel{
    private:
        unsigned char value;

        const bool isBlack() const;
        const bool isWhite() const;

        const std::string toString() const;
    public:
        PGMPixel(unsigned short value, unsigned short maxValue);
};

class PPMPixel : public Pixel {
    private:
        unsigned char value[3];

        const bool isBlack() const;
        const bool isWhite() const;

        const std::string toString() const;
    public:
        PPMPixel(unsigned char value[3], unsigned short maxValue);
};

#endif