#include "ControllerFrame.h"

const bool ControllerFrame::create(const std::vector<std::string> params) {
    // TODO: CREATE FILE
    return fileController.create();
}

const bool ControllerFrame::open(const std::vector<std::string> params) {
    // TODO
    return fileController.open(params.at(0));
}

const bool ControllerFrame::close() {
    // TODO
    return fileController.close();
}

const bool ControllerFrame::save() {
    //TODO
    return true && fileController.close();
}

const bool ControllerFrame::saveAs(const std::vector<std::string> params) {
    //TODO
    return true && fileController.close();
}

const bool ControllerFrame::crop(const std::vector<std::string> params) const {
    // TODO:
    // Image* image = FileController::instance().getImage();
    std::size_t x1 = std::stoi(params.at(0));
    std::size_t y1 = std::stoi(params.at(1));
    std::size_t x2 = std::stoi(params.at(2));
    std::size_t y2 = std::stoi(params.at(3));
    // Editor::instance().cropImage(image, x1, y1, x2, y2);
}

const bool CommandInterpreter::resize(const std::vector<std::string> params) const {
    // TODO:
    //Image* image = FileController::instance().getImage();
    std::size_t rows = std::stoi(params.at(0));
    std::size_t cols = std::stoi(params.at(1));
    //Editor::instance().resizeImage(image, rows, cols);
    return true;
}

const bool CommandInterpreter::dither(const std::vector<std::string> params) const {
    // TODO: access image
    // Editor::instance().ditherImage(/* TODO */, params.at(0));
    return true;
}

const bool CommandInterpreter::exit() const {
    // TODO
    throw ExitException("Exit command registered. Program will exit.");
}