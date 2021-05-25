#ifndef IMAGE_HOLDER_H
#define IMAGE_HODLER_H

// Holds value of image as text
class ImageHolder {
    private:
        static bool isLoaded; // assures that a new file is not passed while another one is loaded
        static std::string imagePixels;
    public:
        static void copyImagePixelsFrom(std::string filePath);

        static void saveChangesTo(std::string filePath);
        static void clear();
}

#endif