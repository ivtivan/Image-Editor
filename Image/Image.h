#ifndef IMAGE_H
#define IMAGE_H

#include "../Pixel/Pixel.h"
#include <string>

enum fileType {
    PBM,
    PGM,
    PPM
};

/**
 * @brief Supports working with images.
 * 
 * Creates an image form parameters or loads one from a PBM/PGM/PPM file.
 */
class Image {
    private:
        /**
         * @brief Pixel values in form of a string.
         * 
         * Comments begin with '#'.
         */
        std::string content;

        Pixel** pixels;
        fileType type;
        unsigned int pixelMaxValue;

        std::size_t cols;
        std::size_t rows;

        /**
         * @brief Removes comments from a line.
         * 
         * Comments begin with '#'.
         */
        void removeCommentsFrom(std::string& line);

        /**
         * @brief determines the file type.
         * 
         * Recognized identifiers are P1, P2, P3.
         * Throws ImageException if the identifier is not recognized.
         */
        const fileType determineFileType(std::string identifier);

        void allocatePixelArray();

        /**
         * @brief Filles allocated pixel matrix.
         * 
         * Values of the pixels in the attribute content are used.
         */
        void fillPBM();

        /**
         * @brief Filles allocated pixel matrix.
         * 
         * Values of the pixels in the attribute content are used.
         */
        void fillPGM();

        /**
         * @brief Filles allocated pixel matrix.
         * 
         * Values of the pixels in the attribute content are used.
         */
        void fillPPM();
        
        /**
         * @brief Determines type of an image, saved in a file.
         * 
         * Throws ImageException if fileType was not read.
         */
        const fileType readFileType(std::ifstream& file);

        /**
         * @brief Reads parameters of an image, saved in a file.
         * 
         * Used to read image size and max value of pixel.
         * 
         * Throws ImageException if a parameter was not read.
         */
        const std::size_t readParameter(std::ifstream& file);

        /**
         * @brief Reads pixels' values of an image, saved in a file.
         * 
         * @return const std::string containing the pixels. values.
         */
        const std::string readPixels(std::ifstream& file);

        /**
         * @brief Calls the needed fill function based on the file type.
         * Calls fillPBM(), fillPGM() or fillPPM90
         */
        void fillPixelArray();

        /**
         * @brief Sets value of all pixels.
         * 
         * @param color in hex form
         */
        void colorPixels(std::string color);
    public:
        Image();
        Image(const Image& image);

        Image& operator=(const Image& image);

        const fileType getFileType() const;
        const std::size_t getRows() const;
        const std::size_t getCols() const;
        Pixel** getPixels();

        /**
         * @brief Set the Pixels object.
         * 
         * Clears the memory of the currently hold pixel martix.
         * Points to the passed pixel matrix.
         * Changes the values of the rows and cols attributes.
         * 
         * @param pixels passed pixel matrix
         * @param rows number of rows in the passed pixel matrix
         * @param cols number of columns in the passed pixel matrix
         */
        void setPixels(Pixel** pixels, std::size_t rows, std::size_t cols);

        /**
         * @brief Set the Pixels object.
         * 
         * Allocates a pixel matrix with the desired size and colors
         * all pixels.
         * 
         * @param color in hex from
         * @param rows rows of image
         * @param cols columns of image
         */
        void setPixels(std::string color, std::size_t rows, std::size_t cols);

        /**
         * @brief Stores image from a file.
         * 
         * Saves image parameters and pixels.
         * Throws FileException if no such file exists.
         */
        void storeImageFrom(std::string filePath);

        Image* operator*();
        ~Image();

        friend std::ostream& operator<<(std::ostream& os, const Image& image);
};

#endif