#include "ImageEditorCaller.h"
#include "../CustomExceptions/FileException/FileException.cpp"
#include "../ImageEditors/PBMEditor/PBMEditor.h"
#include "../ImageEditors/PGMEditor/PGMEditor.h"
#include "../ImageEditors/PPMEditor/PPMEditor.h"

CropFunctionPointer ImageEditor::cropFunctions[] = {
    &PBMEditor::cropImage, &PGMEditor::cropImage, &PPMEditor::cropImage};

ScaleFunctionPointer ImageEditor::scaleFunctions[] = {
    &PBMEditor::scaleImage, &PGMEditor::scaleImage, &PPMEditor::scaleImage};

DitherFunctionPointer ImageEditor::ditherFunctions[] = {
    &PBMEditor::ditherImage, &PGMEditor::ditherImage, &PPMEditor::ditherImage};

void ImageEditor::cropImage(Image* image) {
    if (Image::getIsLoaded() == false) {
        throw FileException("Cannot edit image - no image was laoded.");
    }

    cropFunctions[image->getFileType()]();

}

void ImageEditor::scaleImage(Image* image) {
    if (Image::getIsLoaded() == false) {
        throw FileException("Cannot edit image - no image was laoded.");
    }

    scaleFunctions[image->getFileType()]();
}

void ImageEditor::ditherImage(Image* image) {
    if (Image::getIsLoaded() == false) {
        throw FileException("Cannot edit image - no image was laoded.");
    }

    ditherFunctions[image->getFileType()]();
}