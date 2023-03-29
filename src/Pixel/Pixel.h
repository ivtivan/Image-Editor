#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Supports working with pixels.
 * 
 * The value is either a number or in RGB format.
 */
class Pixel {
    private:
        unsigned short minValue;
        unsigned short maxValue;
        double ditherValue;
    public:
        Pixel();
        Pixel(unsigned short maxValue);

        unsigned short getMinValue() const;
        unsigned short getMaxValue() const;
        double getDitherValue() const;
        virtual double getValue() const;
        virtual void setToMaxValue();
        virtual void setToMinValue();

        void incrementDitherValue(const double incr);
        void resetDitherValue();

        virtual const std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Pixel* pixel);
        
        virtual ~Pixel();
};

#endif