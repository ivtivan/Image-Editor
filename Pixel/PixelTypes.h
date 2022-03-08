#ifndef PIXEL_TYPES
#define PIXEL_TYPES

#include "Pixel.h"

class PBMPixel : public Pixel {
    public:
        PBMPixel();
        PBMPixel(unsigned short value);

        const double getValue() const;
        const std::string getValueString() const;

        void setValue(const unsigned short value);

        const bool isGrey() const;
        
        PBMPixel* toPBMPixel();
        PGMPixel* toPGMPixel();
        PPMPixel* toPPMPixel();
};

class PGMPixel : public Pixel {
    public:
        PGMPixel(unsigned short maxValue);
        PGMPixel(unsigned short value, unsigned short maxValue);

        const double getValue() const;
        const std::string getValueString() const;

        void setValue(const unsigned short value);

        const bool isGrey() const;

        PBMPixel* toPBMPixel();
        PGMPixel* toPGMPixel();
        PPMPixel* toPPMPixel();
};

class PPMPixel : public Pixel {
    public:
        PPMPixel(unsigned short maxValue);
        PPMPixel(unsigned short value, unsigned short maxValue);

        const double getValue() const;
        const std::string getValueString() const;

        void setValue(const unsigned short value);

        const bool isGrey() const;

        PBMPixel* toPBMPixel();
        PGMPixel* toPGMPixel();
        PPMPixel* toPPMPixel();
};

#endif