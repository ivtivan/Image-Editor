#include "PBMEditor.h"
#include <cmath>

void PBMEditor::cropImage(Image* image, std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2) {
    x2 = std::min(x2, image->getCols());
    y2 = std::min(y2, image->getCols());

    Pixel** pixelHolder = new Pixel*[x2 - x1];
    for (std::size_t i = 0; i < x2 - x1; ++i) {
        try {
            pixelHolder[i] = new Pixel[y2 - y1];
        }
        catch (const std::bad_alloc&) {
            for (std::size_t j = 0; j < i; ++j) {
                delete[] pixelHolder[j];
            }
            delete[] pixelHolder;
        }
    }

    for (std::size_t i = 0; i < x2 - x1; ++i) {
        for (std::size_t j = 0; j < y2 - y1; ++j) {
            pixelHolder[i][j] = image->getPixels()[x1 + i][y1 + i];
        }
    }

    image->setPixels(pixelHolder);
    image->setRows(x2 - x1);
    image->setCols(y2 - y1);
}
