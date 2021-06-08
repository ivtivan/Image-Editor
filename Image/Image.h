#ifndef IMAGE_H
#define IMAGE_H

#include "../Pixel/Pixel.h"
#include <string>

enum fileType {
    PBM,
    PGM,
    PPM
};

// Holds value of image as text
class Image {
    private:
        std::string content;
        Pixel** pixels;
        fileType type;
        unsigned int pixelMaxValue;

        std::size_t cols;
        std::size_t rows;

        void removeCommentsFrom(std::string& line);
        const fileType determineFileType(std::string fileExtension);
        void storeFileType(std::string filePath);
        void storeContent(std::string filePath);

        void allocatePixelArray();

        void fillPBM();
        void fillPGM();
        void fillPPM();

        void fillPixelArray();
        void colorPixels(std::string color);
    public:
        Image();
        Image(const Image& image);

        Image& operator=(const Image& image);

        const fileType getFileType() const;
        const std::string getContent() const;

        void storeImageFrom(std::string filePath);
        void saveImageTo(std::string filePath) const;

        const std::size_t getRows() const;
        const std::size_t getCols() const;

        Pixel** getPixels();
        // does not change the values of row and cols
        void setPixels(Pixel** pixels, std::size_t rows, std::size_t cols);
        void setPixels(std::string color, std::size_t rows, std::size_t cols);

        Image* operator*();
        ~Image();

        friend std::ostream& operator<<(std::ostream& os, const Image& image);
};

#endif