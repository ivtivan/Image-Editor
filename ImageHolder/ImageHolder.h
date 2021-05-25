#ifndef IMAGE_HOLDER_H
#define IMAGE_HODLER_H

enum fileType {
    PBM,
    PGM,
    PPM
}

// Holds value of image as text
class ImageHolder {
    private:
        static bool isLoaded; // assures that a new file is not passed while another one is loaded
        static std::string imageContent;
        static fileType type;

        static void determineFileType(std::string fileExtension);
        static void saveFileType(std::string filePath);
        static void storeContent(std::string filePath);
    public:
        static const bool getIsLoaded();
        static const fileType getFileType();
        static std::string getImageContent();

        static void storeImage(std::string filePath);
        static void saveChangesTo(std::string filePath);
        static void clear();
}

#endif