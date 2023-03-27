#include "Image.h"
#include <fstream>

Image::Image() : dimension(0, 0) {
    ;
}

Image::Image(Dimension dimension, pixel_ptr_vector&& pixels) :
    dimension(dimension), pixels(std::move(pixels)) {
    ;
}

std::shared_ptr<Pixel>& Image::getPixelAt(const Point& point) {
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

std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Image> image) {
    os << image->getTypeID() << std::endl;
    os << image->getCols() << " " << image->getRows() << std::endl;
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

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Image> image) {
    // TODO: return image.toString and add max value
    os << image->getTypeID() << std::endl;
    os << image->getCols() << " " << image->getRows() << std::endl;
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