#include "Editor.h"
#include "../CustomExceptions/CustomExceptions.h"
#include "../Dithers/DiffusionDithers/DitherAtkinson/DitherAtkinson.h"
#include "../Dithers/DiffusionDithers/DitherBurkes/DitherBurkes.h"
#include "../Dithers/DiffusionDithers/DitherFS/DitherFS.h"
#include "../Dithers/DiffusionDithers/DitherJJN/DitherJJN.h"
#include "../Dithers/DiffusionDithers/DitherLinear/DitherLinear.h"
#include "../Dithers/DiffusionDithers/DitherSierra/DitherSierra.h"
#include "../Dithers/DiffusionDithers/DitherSierraLite/DitherSierraLite.h"
#include "../Dithers/DiffusionDithers/DitherTRSierra/DitherTRSierra.h"
#include "../Dithers/DiffusionDithers/DitherStucki/DitherStucki.h"
#include "../Dithers/OrderedDithers/Dither4Bayer/Dither4Bayer.h"
#include "../Dithers/OrderedDithers/Dither8Bayer/Dither8Bayer.h"
#include <cmath>

Editor::Editor() {
    ;
}

Editor& Editor::instance() {
    static Editor editor;
    return editor;
}

void Editor::cropImage(Image* image, std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2) {
    if (x1 > x2 || y1 > y2) {
        throw EditException("Points passed not valid.");
    }

    x2 = std::round(std::min((double)x2, (double)image->getRows()));
    y2 = std::round(std::min((double)y2, (double)image->getCols()));
 
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
            pixelHolder[i][j] = image->getPixels()[x1 + i][y1 + j];
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
        srcX = (int)((double) srcRows * (double) i / (double)destRows); 
        srcX = (int)(std::min((double)srcX, (double)(srcRows - 1)));
        for (std::size_t j = 0; j < destCols; ++j) {
            srcY = (int)((double) srcCols * (double) j / (double)destCols);
            srcY = (int)(std::min((double)srcY, (double)(srcCols - 1)));

            destPixels[i][j] = image->getPixels()[srcX][srcY];
        }
    }

    image->setPixels(destPixels, destRows, destCols);
}

void Editor::ditherImage(Image* image, std::string algorithmName) {
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
        throw EditException("Dithering algorithm not found.");
    }
}