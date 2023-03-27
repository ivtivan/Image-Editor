#ifndef IMAGE_FACTORY_H
#define IMAGE_FACTORY_H

#include "../../../Image/Image.h"
#include "../../../Image/ImageTypes/PBMImage.h"
#include "../../../Image/ImageTypes/PGMImage.h"
#include "../../../Image/ImageTypes/PPMImage.h"
#include "../../../Pixel/PixelTypes/PBMPixel.h"
#include "../../../Pixel/PixelTypes/PGMPixel.h"
#include "../../../Pixel/PixelTypes/PPMPixel.h"

class ImageFactory {
    private:
        std::ifstream* src;
        Dimension dimension;
        unsigned short maxValue;
        pixel_ptr_vector pixels;

        std::string readImageTypeIdentificator();
        Dimension readDimension();
        void saveMaxValue();

        void readIntoPBMPixelMatrix();
        void readIntoPGMPixelMatrix();

        void readIntoPPMPixelMatrix();
        void fillPPMPixelMatrixColor(const std::string& hexColor);
    public:
        ImageFactory();


        std::shared_ptr<Image> loadImageFrom(std::ifstream& src);
        std::shared_ptr<PBMImage> loadPBMImageFrom();
        std::shared_ptr<PGMImage> loadPGMImageFrom();
        std::shared_ptr<PPMImage> loadPPMImageFrom();
        std::shared_ptr<PPMImage> getPPMFromSizeColor(const Dimension& dimension, const std::string& hexColor);
};

#endif