#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <string>
#include <sstream>

class PBMPixel;
class PGMPixel;
class PPMPixel;

/**
 * @brief pixel parrent class.
 */
class Pixel {
    protected:
        const unsigned short maxValue;
        const unsigned short minValue;
        unsigned short* value;

        /** 
         * @brief Value obtained from diffusing errors when using diffusuion ditters.
         * 
         */
        double ditherValue;

        const bool isBlack() const;
        const bool isWhite() const;

    public:
        Pixel();
        Pixel(unsigned short maxValue, std::size_t length);
        Pixel(unsigned short value, unsigned short maxValue, std::size_t length);

        virtual const double getValue() const;
        const unsigned short* getValueArray() const;
        virtual const std::string getValueString() const;

        const unsigned int getMaxValue() const;
        const double getDitherValue() const;
        
        virtual void setValue(const unsigned short value);
        void setValue(const unsigned short* value);

        /**
         * @brief Sets value of pixel through string.
         * 
         * @param value color in hex form
         */
        void setValue(std::string value);

        void incrementDitherValue(const double incr);

        /**
         * @brief Sets diffused error from dithering to 0.
         */
        void resetDitherValue();
        
        virtual const bool isGrey() const;
        const bool isBlackOrWhite() const;
        
        /**
         * @brief Converts a pixel in PBM format.
         * 
         * Throws an exception if the pixel is neither black nor white.
         * Throws an exception if the pixel is already in PBM.
         */
        virtual PBMPixel toPBMPixel();

        /**
         * @brief Converts a pixel in PGM format while keeping the opriginal maxValue.
         * 
         * Throws an exception if the pixel is already in PGM.
         */
        virtual PGMPixel toPGMPixel();

        /**
         * @brief Converts a pixel in PPM format while keeping the opriginal value and maxValue.
         * 
         * Throws an exception if the pixel is already in PPM.
         */
        virtual PPMPixel toPPMPixel();

        ~Pixel();

        friend std::ostream& operator<<(std::ostream& os, Pixel pixel);
};

#endif