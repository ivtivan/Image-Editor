#ifndef IMAGE_H
#define IMAGE_H

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
        fileType type;

        std::size_t cols;
        std::size_t rows;

        void removeCommentsFrom(std::string& line);
        const fileType determineFileType(std::string fileExtension);
        void storeFileType(std::string filePath);
        void storeContent(std::string filePath);
    public:
        Image();
        Image(const Image& image);

        Image& operator=(const Image& image);

        const fileType getFileType() const;
        const std::string getContent() const;

        void storeImageFrom(std::string filePath);
        void saveImageTo(std::string filePath) const;

        Image* operator*();
};

#endif