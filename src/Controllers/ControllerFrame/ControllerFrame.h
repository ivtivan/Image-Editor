#ifndef CONTROLLER_FRAME_H
#define CONTROLLER_FRAME_H

#include "../FileController/FileController.h"
#include "../ImageControl/ImageController/ImageController.h"
#include <vector>

class ControllerFrame {
    private:
        ImageController imageController;
        FileController fileController;
    public:
        ControllerFrame();
        const bool create(const std::vector<std::string> param);
        const bool open(const std::vector<std::string> param);
        const bool close();
        const bool save();
        const bool saveAs(const std::vector<std::string> param);
        const bool crop(const std::vector<std::string> param) const;
        const bool resize(const std::vector<std::string> param) const;
        const bool dither(const std::vector<std::string> param) const;
        const bool exit() const;
};

#endif