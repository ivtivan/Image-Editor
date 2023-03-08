#ifndef CONTROLLER_FRAME_H
#define CONTROLLER_FRAME_H

#include "../FileController/FileController.h"
#include "../ImageControl/ImageController/ImageController.h"

class ControllerFrame {
    private:
        ImageController image_controller;
        FileController file_controller;
    public:
        const bool create(/* TODO add parameters*/);
        const bool open(/* TODO add parameters*/);
        const bool close();
        const bool save();
        const bool saveAs(/* TODO add parameters*/);
        const bool crop(/* TODO add parameters*/) const;
        const bool resize(/* TODO add parameters*/) const;
        const bool dither(/* TODO add parameters*/) const;
        const bool exit() const;

};

#endif