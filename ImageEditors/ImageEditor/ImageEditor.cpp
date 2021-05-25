#include "ImageEditor.h"
#include "../../CustomExceptions/FileException/FileException.cpp"
#include "../../ImageHolder/ImageHolder.h"

void ImageEditor::cropImage() {
    if (ImageHolder::getIsLoaded() == false) {
        throw FileException("Cannot edit image - no image was laoded.");
    }
}

void ImageEditor::scaleImage() {
    if (ImageHolder::getIsLoaded() == false) {
        throw FileException("Cannot edit image - no image was laoded.");
    }
}

void ImageEditor::ditherImage() {
    if (ImageHolder::getIsLoaded() == false) {
        throw FileException("Cannot edit image - no image was laoded.");
    }
}