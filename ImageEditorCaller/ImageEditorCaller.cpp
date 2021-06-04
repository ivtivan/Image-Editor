#include "ImageEditorCaller.h"
#include "../ImageEditors/PBMEditor/PBMEditor.h"
#include "../ImageEditors/PGMEditor/PGMEditor.h"
#include "../ImageEditors/PPMEditor/PPMEditor.h"

void ImageEditorCaller::cropImage(Image* image) {
    switch(image->getFileType()) {
        case PBM: this->pbmEditor.cropImage(image); break;
        case PGM: this->pbmEditor.cropImage(image); break;
        case PPM: this->pbmEditor.cropImage(image); break;
    }
}

void ImageEditorCaller::resizeImage(Image* image) {
    switch(image->getFileType()) {
        case PBM: this->pbmEditor.resizeImage(image); break;
        case PGM: this->pbmEditor.resizeImage(image); break;
        case PPM: this->pbmEditor.resizeImage(image); break;
    }
}

void ImageEditorCaller::ditherImage(Image* image) {
    switch(image->getFileType()) {
        case PBM: this->pbmEditor.ditherImage(image); break;
        case PGM: this->pbmEditor.ditherImage(image); break;
        case PPM: this->pbmEditor.ditherImage(image); break;
    }
}