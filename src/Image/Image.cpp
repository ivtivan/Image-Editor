#include "Image.h"
#include <fstream>

Image::Image() : dimension(0, 0) {
    ;
}

Image::Image(Dimension dimension, pixel_ptr_vector&& pixels) :
    dimension(dimension), pixels(std::move(pixels)) {
    ;
}

const std::shared_ptr<Pixel>& Image::getPixelAt(const Point& point) const{
    std::size_t index = dimension.getCols() * point.getX() + point.getY();
    return pixels.at(index);
}

std::size_t Image::getRows() const {
    return dimension.getRows();
}

std::size_t Image::getCols() const {
    return dimension.getCols();
}

void Image::setPixels(pixel_ptr_vector&& pixels) {
    this->pixels = std::move(pixels);
}

void Image::outputImage(std::ostream&) const {
    ;
}

void Image::outputType(std::ostream& os) const {
    os << getTypeID() << std::endl;
}

void Image::outputDimension(std::ostream& os) const {
    os << getCols() << " " << getRows() << std::endl;
}

void Image::outputMaxValue(std::ostream& os) const {
    os << getPixelAt(Point(0, 0))->getMaxValue() << std::endl;
}

void Image::outputPixels(std::ostream& os) const {
    for (std::size_t i = 0; i < getRows(); ++i) {
        for (std::size_t j = 0; j < getCols(); ++j) {
            os << getPixelAt(Point(i, j))->toString();

            if (j != getCols()- 1) {
                os << " ";
            }
        }
        os << '\n';
    }
}

std::ostream& operator<<(std::ostream& os, const Image* image) {
    image->outputImage(os);
    return os;
}

void Image::movePixelsFromWith(pixel_ptr_vector&& srcPixels, const Dimension& srcDimension) {
    freePixels();
    pixels = std::move(srcPixels);
    dimension = srcDimension;
}

void Image::freePixels() {
    pixels.clear();
}

const std::string Image::getTypeID() const {
    return "";
}

Image::~Image() {
    freePixels();
}