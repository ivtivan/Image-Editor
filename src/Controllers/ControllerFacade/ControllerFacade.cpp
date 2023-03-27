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
    std::shared_ptr<Image> generatedImage = factory.getPPMFromSizeColor(dimension, hexColor);
    editor.setTargetImage(generatedImage);
    fileController.setSrcImage(generatedImage);
    return true;
}

bool ControllerFacade::open(const std::vector<std::string> params) {
    ImageFactory factory;
    std::string imageFile = params.at(0);
    std::ifstream readFrom = fileController.open(imageFile);
    std::shared_ptr<Image> openedImage = factory.loadImageFrom(readFrom);
    readFrom.close();
    editor.setTargetImage(openedImage);
    fileController.setSrcImage(openedImage);
    return true;
}

bool ControllerFacade::close() {
    editor.closeTargetImage();
    return fileController.close();
}

bool ControllerFacade::save() {
    return fileController.save();
}

bool ControllerFacade::saveAs(const std::vector<std::string> params) {
    return fileController.saveAs(params.at(0));
}

bool ControllerFacade::crop(const std::vector<std::string> params) const {
    Point upLeft(std::stoi(params.at(0)), std::stoi(params.at(1)));
    Point downRight(std::stoi(params.at(2)), std::stoi(params.at(3)));
    return editor.cropImage(upLeft, downRight);
}

bool ControllerFacade::resize(const std::vector<std::string> params) const {
    Dimension dst(std::stoi(params.at(0)), std::stoi(params.at(1)));
    return editor.resizeImage(dst);
}

bool ControllerFacade::dither(const std::vector<std::string> params) const {
    return editor.ditherImage(params.at(0));
}

bool ControllerFacade::exit() {
    return close();
}