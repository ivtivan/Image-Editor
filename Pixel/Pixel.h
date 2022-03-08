#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief pixel parrent class.
 */
class Pixel {
    protected:
        unsigned short maxValue;
        unsigned short minValue = 0;
        unsigned short* value;

        /** 
         * @brief Value obtained from diffusing errors when using diffusuion ditters.
         * 
         */
        double ditherValue;

        /**
         * @brief Checks if a pixel is black.
         * 
         * A pixel is black if its value is equal to the min possible value.
         * Since for some file types this is not the case, the function should not be called
         * outside of the member function isBlackOrWhite().
         */
        const bool isBlack() const;

        /**
         * @brief Checks if a pixel is white.
         * 
         * A pixel is black if its value is equal to the max possible value.
         * Since for some file types this is not the case, the function should not be called
         * outside of the member function isBlackOrWhite(). 
         */
        const bool isWhite() const;
    public:
        Pixel(unsigned short maxValue, std::size_t length);
        Pixel(const Pixel& pixel);
        Pixel& operator=(const Pixel& pixel);

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

        /**
         * @brief Sets RGB status of black or white pixel to false and changes max value to 1.
         * 
         * Value of pixel is changed if needed.
         * 
         * Throws PixelException when the pixel is neither black nor white.
         */
        void setBlackOrWhite();

        /**
         * @brief Swaps the two colors.
         * 
         * Throws PixelException when the pixel is neither black nor white.
         */
        void swapBlackAndWhite();

        void incrementDitherValue(const double incr);

        /**
         * @brief Sets diffused error from dithering to 0.
         * 
         */
        void resetDitherValue();
        
        virtual const bool isGrey() const;

        const bool isBlackOrWhite() const;
        
        ~Pixel();

        friend std::ostream& operator<<(std::ostream& os, Pixel pixel);
};

#endif