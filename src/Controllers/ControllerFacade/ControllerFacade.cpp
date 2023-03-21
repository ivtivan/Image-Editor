#include "ControllerFacade.h"
#include <fstream>

ControllerFacade::ControllerFacade() : editor(),
    fileController() {
    ;
}

bool ControllerFacade::create(const std::vector<std::string> params) {
    ImageFactory factory;
    std::size_t rows = stoi(params.at(0));
    std::size_t cols = stoi(params.at(1));
    const Dimension dimension(rows, cols);
    std::string hexColor = params.at(2);
    Image* generatedImage = factory.getPPMFromSizeColor(dimension, hexColor);
    editor.setTargetImage(generatedImage);
    fileController.setSrcImage(generatedImage);
    return true;
}

bool ControllerFacade::open(const std::vector<std::string> params) {
    ImageFactory factory;
    std::string imageFile = params.at(0);
    std::ifstream readFrom = fileController.open(imageFile);
    Image* openedImage = factory.loadImageFrom(readFrom);
    readFrom.close();
    editor.setTargetImage(openedImage);
    fileController.setSrcImage(openedImage);
    return true;
}

bool ControllerFacade::close() {
    return fileController.close();
}

bool ControllerFacade::save() {
    return fileController.save();
}

bool ControllerFacade::saveAs(const std::vector<std::string> params) {
    return fileController.saveAs(params.at(0));
}

bool ControllerFacade::crop(const std::vector<std::string> params) const {
    std::size_t x1 = std::stoi(params.at(0));
    std::size_t y1 = std::stoi(params.at(1));
    std::size_t x2 = std::stoi(params.at(2));
    std::size_t y2 = std::stoi(params.at(3));
    return editor.cropImage(x1, y1, x2, y2);
}

bool ControllerFacade::resize(const std::vector<std::string> params) const {
    std::size_t rows = std::stoi(params.at(0));
    std::size_t cols = std::stoi(params.at(1));
    return editor.resizeImage(rows, cols);;
}

bool ControllerFacade::dither(const std::vector<std::string> params) const {
    return editor.ditherImage(params.at(0));
}

bool ControllerFacade::exit() const {
    // TODO
    return false;
}