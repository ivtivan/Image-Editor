#ifndef PBM_Pixel_H
#define PBM_Pixel_H

#include "../Pixel.h"

class PBMPixel : public Pixel {
    private:
        unsigned char value;

        const std::string toString() const override;
    public:
        PBMPixel(unsigned char value);

        double getValue() const override;

        void setToMaxValue() override;
        void setToMinValue() override;

        ~PBMPixel() = default;
};

#endif