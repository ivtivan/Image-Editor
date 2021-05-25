#ifndef IMAGE_H
#define IMAGE_H
enum fileType {
    PBM,
    PGM,
    PPM
}

// Holds value of image as text
class Image {
    private:
        std::string imageContent;
        fileType type;

        void determineFileType(std::string fileExtension);
        void saveFileType(std::string filePath);
        void storeContent(std::string filePath);
    public:
        Image();
        Image(const Image& image);

        Image& operator=(const Image& image);

        const fileType getFileType() const;
        const std::string getImageContent() const;

        void storeImageFrom(std::string filePath);
        void saveImageTo(std::string filePath) const;

        Image* operator*();
}

#endif