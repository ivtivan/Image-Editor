#ifndef IMAGE_EDITOR_CALLER_H
#define IMAGE_EDITOR_CALLER_H

#include "../../Image/Image.h"

typedef void (*CropFunctionPointer)(Image*);
typedef void (*ScaleFunctionPointer)(Image*);
typedef void (*DitherFunctionPointer)(Image*);

// Calls the needed function
class ImageEditorCaller {
    private:
        static CropFunctionPointer cropFunctions[];
        static ScaleFunctionPointer scaleFunctions[];
        static DitherFunctionPointer ditherFunctions[];
    public:
        static void cropImage(Image* image);
        static void scaleImage(Image* image);
        static void ditherImage(Image* image);
};

#endif