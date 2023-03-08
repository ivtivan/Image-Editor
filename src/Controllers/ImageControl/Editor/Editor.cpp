#include "Editor.h"
#include "../Dithers/DiffusionDithers/DiffusionDithersTypes/DiffusionDithersTypes.h"
#include "../Dithers/OrderedDithers/OrderedDithersTypes/OrderedDithersTypes.h"
#include <cmath>

Editor::Editor() {
    ;
}

// TODO: move to a helepr file if beneficial
Pixel** Editor::allocatePixelMatrix(std::size_t rows, std::size_t cols) const {
    Pixel** pixels;
    try {
        pixels = new Pixel*[rows];
    }
    catch (const std::bad_alloc&) {
        return nullptr;
    }
    for (std::size_t i = 0; i < rows; ++i) {
        try {
            pixels[i] = new Pixel[cols];
        }
        catch (const std::bad_alloc&) {
            for (std::size_t j = 0; j < i; ++j) {
                delete[] pixels[j];
            }
            delete[] pixels;

            return nullptr;
        }
    }
    return pixels;
}

const bool Editor::cropImage(Image* image, std::size_t xUpLeft, std::size_t yUpLeft,
            std::size_t xDownRight, std::size_t yDownRight) const {
    if (xUpLeft > xDownRight || yUpLeft > yDownRight) {
        return false;
    }

    xDownRight = (std::size_t)(std::min((double)xDownRight, (double)image->getRows()));
    yDownRight = (std::size_t)(std::min((double)yDownRight, (double)image->getCols()));
 
    Pixel** pixelHolder = allocatePixelMatrix(xDownRight - xUpLeft, yDownRight - yUpLeft);
    if (!pixelHolder) {
        return false;
    }

    // TODO: function
    for (std::size_t xOffset = 0; xOffset < xDownRight - xUpLeft; ++xOffset) {
        for (std::size_t yOffset = 0; yOffset < yDownRight - yUpLeft; ++yOffset) {
            pixelHolder[xOffset][yOffset] = 
                image->getPixels()[xUpLeft + xOffset][yUpLeft + yOffset];
        }
    }

    image->setPixels(pixelHolder, xDownRight - xUpLeft, yDownRight - yUpLeft);
    return true;
}

// Algorithm from https://courses.cs.vt.edu/~masc1044/L17-Rotation/ScalingNN.html
const bool Editor::resizeImage(Image* image, std::size_t destRows, std::size_t destCols) const {
    std::size_t srcRows = image->getRows();
    std::size_t srcCols = image->getCols();
    std::size_t srcX, srcY; // coordinates of the source pixel

    Pixel** destPixels = allocatePixelMatrix(destRows, destCols);
    if (!destPixels) {
        return false;
    }

    // TODO: function
    for (std::size_t destX = 0; destX < destRows; ++destX) {
        srcX = (std::size_t)((double) srcRows * (double) destX / (double)destRows); 
        srcX = (std::size_t)(std::min((double)srcX, (double)(srcRows - 1)));
        for (std::size_t destY = 0; destY < destCols; ++destY) {
            srcY = (std::size_t)((double) srcCols * (double) destY / (double)destCols);
            srcY = (std::size_t)(std::min((double)srcY, (double)(srcCols - 1)));

            destPixels[destX][destY] = image->getPixels()[srcX][srcY];
        }
    }

    image->setPixels(destPixels, destRows, destCols);
    return true;
}

// TODO: move to DitherController
const bool Editor::ditherImage(Image* image, std::string algorithmName) const {
    if (algorithmName == "Linear") {
        DitherLinear dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "Atkinson") {
        DitherAtkinson dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "Burkes") {
        DitherBurkes dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "FS") {
        DitherFS dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "JJN") {
        DitherJJN dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "Sierra") {
        DitherSierra dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "SierraLite") {
        DitherSierraLite dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "TRSierra") {
        DitherTRSierra dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "Stucki") {
        DitherStucki dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "4Bayer") {
        Dither4Bayer dither;
        dither.ditherImage(image);
    }
    else if (algorithmName == "8Bayer") {
        Dither8Bayer dither;
        dither.ditherImage(image);
    }
    else {
        return false;
    }

    return true;
}