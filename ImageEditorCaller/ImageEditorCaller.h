#ifndef IMAGE_EDITOR_CALLER_H
#define IMAGE_EDITOR_CALLER_H

#include "../Image/Image.h"
#include "../ImageEditors/PBMEditor/PBMEditor.h"
#include "../ImageEditors/PGMEditor/PGMEditor.h"
#include "../ImageEditors/PPMEditor/PPMEditor.h"

// Calls the needed function
class ImageEditorCaller {
    private:
        PBMEditor pbmEditor;
        PGMEditor pgmEditor;
        PPMEditor ppmEditor;
    public:
        ImageEditorCaller();

        void cropImage(Image* image);
        void resizeImage(Image* image);
        void ditherImage(Image* image);
};

#endif