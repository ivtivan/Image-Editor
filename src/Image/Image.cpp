#include "Image.h"
#include <fstream>
#include <iostream>
Image::Image() : dimension(0, 0), pixels(nullptr) {
    ;
}

Image::Image(Dimension dimension, Pixel*** pixels) :
    dimension(dimension), pixels(pixels) {
    ;
}

Pixel* Image::getPixelAt(const Point& point) const {
    if (pixels) {
        std::cout << "ALERT\n";
    }
    return pixels[point.getX()][point.getY()];
}

std::size_t Image::getRows() const {
    return dimension.getRows();
}

std::size_t Image::getCols() const {
    return dimension.getCols();
}

void Image::setPixels(Pixel*** pixels) {
    this->pixels = pixels;
}


std::ostream& operator<<(std::ostream& os, const Image* image) {
    os << image->getTypeID() << std::endl;
    os << image->getRows() << " " << image->getCols() << std::endl;
    os << image->getPixelAt(Point(0, 0))->toString();
    for (std::size_t i = 0; i < image->getRows(); ++i) {
        for (std::size_t j = 0; j < image->getCols(); ++j) {
            os << image->getPixelAt(Point(i, j))->toString();

            if (j != image->getCols()- 1) {
                os << " ";
            }
        }
        os << '\n';
    }
    return os;
}

void Image::updatePixels(Pixel*** srcPixels, const Dimension srcDimension) {
    freePixels();
    
    pixels = srcPixels;
    dimension = srcDimension;
}

void Image::freePixels() {
    for (std::size_t i = 0; i < dimension.getRows(); ++i) {
        for (std::size_t j = 0; j < dimension.getCols(); ++j) {
            delete pixels[i][j];
        }
        delete pixels[i];
    }
    delete pixels;
}

const std::string Image::getTypeID() const {
    return "";
}

Image::~Image() {
    freePixels();
}