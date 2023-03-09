#include "ControllerFrame.h"

ControllerFrame::ControllerFrame() : imageController(),
    fileController() {
    ;
}

const bool ControllerFrame::create(const std::vector<std::string> params) {
    return fileController.create();
}

const bool ControllerFrame::open(const std::vector<std::string> params) {
    return fileController.open(params.at(0));
}

const bool ControllerFrame::close() {
    return fileController.close();
}

const bool ControllerFrame::save() {
    return fileController.save(imageController.getImage());
}

const bool ControllerFrame::saveAs(const std::vector<std::string> params) {
    return fileController.saveAs(imageController.getImage(), params.at(0));
}

const bool ControllerFrame::crop(const std::vector<std::string> params) const {
    std::size_t x1 = std::stoi(params.at(0));
    std::size_t y1 = std::stoi(params.at(1));
    std::size_t x2 = std::stoi(params.at(2));
    std::size_t y2 = std::stoi(params.at(3));
    return imageController.cropImage(x1, y1, x2, y2);
}

const bool ControllerFrame::resize(const std::vector<std::string> params) const {
    std::size_t rows = std::stoi(params.at(0));
    std::size_t cols = std::stoi(params.at(1));
    return imageController.resizeImage(rows, cols);;
}

const bool ControllerFrame::dither(const std::vector<std::string> params) const {
    return imageController.ditherImage(params.at(0));
}

const bool ControllerFrame::exit() const {
    // TODO
    return false;
}