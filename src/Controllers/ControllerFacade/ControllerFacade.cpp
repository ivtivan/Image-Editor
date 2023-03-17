#include "ControllerFacade.h"

ControllerFacade::ControllerFacade() : editor(),
    fileController() {
    ;
}

const bool ControllerFacade::create(const std::vector<std::string> params) {
    const ImageFactory factory;
    std::size_t rows = stoi(params.at(0));
    std::size_t cols = stoi(params.at(1));
    std::string hexColor = params.at(2);
    Image* targetImage = factory.getPPMFromSizeColor(rows, cols, hexColor);
    editor.setTargetImage(targetImage);
    fileController.setTargetImage(targetImage);
    return fileController.create("tempTODO.ppm");
}

const bool ControllerFacade::open(const std::vector<std::string> params) {
    return fileController.open(params.at(0));
}

const bool ControllerFacade::close() {
    return fileController.close();
}

const bool ControllerFacade::save() {
    return fileController.save();
}

const bool ControllerFacade::saveAs(const std::vector<std::string> params) {
    return fileController.saveAs(params.at(0));
}

const bool ControllerFacade::crop(const std::vector<std::string> params) const {
    std::size_t x1 = std::stoi(params.at(0));
    std::size_t y1 = std::stoi(params.at(1));
    std::size_t x2 = std::stoi(params.at(2));
    std::size_t y2 = std::stoi(params.at(3));
    return editor.cropImage(x1, y1, x2, y2);
}

const bool ControllerFacade::resize(const std::vector<std::string> params) const {
    std::size_t rows = std::stoi(params.at(0));
    std::size_t cols = std::stoi(params.at(1));
    return editor.resizeImage(rows, cols);;
}

const bool ControllerFacade::dither(const std::vector<std::string> params) const {
    return editor.ditherImage(params.at(0));
}

const bool ControllerFacade::exit() const {
    // TODO
    return false;
}