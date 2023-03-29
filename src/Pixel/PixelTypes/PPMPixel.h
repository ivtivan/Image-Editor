#ifndef PPM_PIXEL_H
#define PPM_PIXEL_H

#include "../Pixel.h"

class PPMPixel : public Pixel {
    private:
        unsigned short value[3];

        const std::string toString() const override;
    public:
        PPMPixel(unsigned short value[3], unsigned short maxValue);
        PPMPixel(std::string hex);

        double getValue() const override;

        void setToMaxValue() override;
        void setToMinValue() override;

        ~PPMPixel() = default;
};

#endif