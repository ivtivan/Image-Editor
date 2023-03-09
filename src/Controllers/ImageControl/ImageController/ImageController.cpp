#include "ImageController.h"

ImageController::ImageController() : editor(),
    imageFactory(), image(nullptr) {

}

const Image* ImageController::getImage() {
    return image;
}

const bool ImageController::cropImage(std::size_t xUpLeft, std::size_t yUpLeft,
    std::size_t xDownRight, std::size_t yDownRight) const {
    return editor.cropImage(image, xUpLeft, yUpLeft, xDownRight, yDownRight);
}

const bool ImageController::resizeImage(std::size_t destRows, std::size_t destCols) const {
    return editor.resizeImage(image, destRows, destCols);

}

const bool ImageController::ditherImage(std::string algorithmName) const {
    return editor.ditherImage(image, algorithmName);
}