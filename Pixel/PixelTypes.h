#ifndef PIXEL_TYPES
#define PIXEL_TYPES

#include "Pixel.h"

class PBMPixel : public Pixel {
    public:
        PBMPixel();

        const double getValue() const;
        const std::string getValueString() const;

        void setValue(const unsigned short value);

        const bool isGrey() const;
};

class PGMPixel : public Pixel {
    public:
        PGMPixel(unsigned short maxValue);

        const double getValue() const;
        const std::string getValueString() const;

        void setValue(const unsigned short value);

        const bool isGrey() const;
};

class PPMPixel : public Pixel {
    public:
        PPMPixel(unsigned short maxValue);

        const double getValue() const;
        const std::string getValueString() const;

        void setValue(const unsigned short value);

        const bool isGrey() const;
};

#endif