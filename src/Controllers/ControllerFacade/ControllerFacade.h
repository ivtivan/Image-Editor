#ifndef CONTROLLER_FACADE_H
#define CONTROLLER_FACADE_H

#include "../FileController/FileController.h"
#include "../ImageControl/Editor/Editor.h"
#include <vector>

class ControllerFacade {
    private:
        Editor editor;
        FileController fileController;
    public:
        ControllerFacade();
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