#include "Editor.h"
#include "../Dither/Dither.h"
#include <cmath>

void Editor::cropImage(Image* image, std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2) {
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

    image->setPixels(pixelHolder, x2 - x1, y2 - y1);
}

// Algorithm from https://courses.cs.vt.edu/~masc1044/L17-Rotation/ScalingNN.html
void Editor::resizeImage(Image* image, std::size_t destRows, std::size_t destCols) {
    std::size_t srcRows = image->getRows();
    std::size_t srcCols = image->getCols();
    std::size_t srcX, srcY; // coordinates of the source pixel

    Pixel** destPixels = new Pixel*[destRows];
    for (std::size_t i = 0; i < destRows; ++i) {
        try {
            destPixels[i] = new Pixel[destCols];
        }
        catch (const std::bad_alloc&) {
            for (std::size_t j = 0; j < i; ++j) {
                delete[] destPixels[j];
            }
            delete[] destPixels;
        }
    }

    for (std::size_t i = 0; i < destRows; ++i) {
        srcX =(int) std::round((double) srcRows * (double) i / (double)destRows); 
        srcX = std::min(srcX, srcRows - 1);
        for (std::size_t j = 0; j < destCols; ++j) {
            srcY =(int) std::round((double) srcCols * (double) j / (double)destCols);
            srcY = std::min(srcY, srcCols - 1);
            
            destPixels[i][j] = image->getPixels()[srcX][srcY];
        }
    }

    image->setPixels(destPixels, destRows, destCols);
}

void Editor::ditherImage(Image* image, std::string algorithmName) {
    Dither dither(algorithmName);
    dither.ditherImage(image);
}