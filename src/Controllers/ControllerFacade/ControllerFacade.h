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
        bool create(const std::vector<std::string> param);
        bool open(const std::vector<std::string> param);
        bool close();
        bool save();
        bool saveAs(const std::vector<std::string> param);
        bool crop(const std::vector<std::string> param) const;
        bool resize(const std::vector<std::string> param) const;
        bool dither(const std::vector<std::string> param) const;
        bool exit();
};

#endif