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
    protected:
        unsigned short maxValue;
        const unsigned short minValue;
        double ditherValue;

        virtual const bool isBlack() const;
        virtual const bool isWhite() const;
    public:
        Pixel();
        Pixel(unsigned short maxValue);

        const unsigned short getMaxValue() const;
        const double getDitherValue() const;

        virtual const double getValue() const;

        void incrementDitherValue(const double incr);
        void resetDitherValue();

        virtual const std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
        
        // TODO: virtual destructor?
};

#endif