#ifndef PGM_PIXEL_H
#define PGM_PIXEL_H

#include "../Pixel.h"

class PGMPixel : public Pixel {
    private:
        unsigned short value;

        const std::string toString() const override;
    public:
        PGMPixel(unsigned short value, unsigned short maxValue);

        double getValue() const override;

        void setToMaxValue() override;
        void setToMinValue() override;

        ~PGMPixel() = default;
};

#endif