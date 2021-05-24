#ifndef IMAGE_HOLDER_H
#define IMAGE_HODLER_H

// Holds value of image as text
class ImageHolder {
    private:
        static std::string imagePixels;
    public:
        copyImagePixelsFrom(std::string file);

}

#endif