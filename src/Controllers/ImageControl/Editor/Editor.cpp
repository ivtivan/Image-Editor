#include "Editor.h"
#include "../Dithers/DiffusionDithers/DiffusionDithersTypes/DiffusionDithersTypes.h"
#include "../Dithers/OrderedDithers/OrderedDithersTypes/OrderedDithersTypes.h"
#include <cmath>

Editor::Editor() {
    ;
}

void Editor::setTargetImage(std::shared_ptr<Image> targetImage) {
    this->targetImage = targetImage;
}

void Editor::closeTargetImage() {
    targetImage = nullptr;
}

bool Editor::cropImage(const Point& upLeft, const Point& downRight) const {
    if (upLeft.getX() > downRight.getX() ||
        upLeft.getY() > downRight.getY()) {
        return false;
    }

    std::size_t xUpLeft = upLeft.getX();
    std::size_t yUpLeft = upLeft.getY();
    std::size_t xDownRight = (std::size_t)
        (std::min((double)downRight.getX(), (double)targetImage->getRows()));
    std::size_t yDownRight = (std::size_t)
        (std::min((double)downRight.getY(), (double)targetImage->getCols()));
 
    pixel_ptr_vector pixelHolder;

    const Dimension targetDimension(xDownRight - xUpLeft, yDownRight - yUpLeft);

    for (std::size_t xOffset = 0; xOffset < targetDimension.getRows(); ++xOffset) {
        for (std::size_t yOffset = 0; yOffset < targetDimension.getCols(); ++yOffset) {
            pixelHolder.push_back(std::move
                (targetImage->getPixelAt(Point(xUpLeft + xOffset, yUpLeft + yOffset))));
        }
    }

    targetImage->movePixelsFromWith(std::move(pixelHolder), targetDimension);
    return true;
}

// Algorithm from https://courses.cs.vt.edu/~masc1044/L17-Rotation/ScalingNN.html
bool Editor::resizeImage(const Dimension& dst) const {
    std::size_t srcRows = targetImage->getRows();
    std::size_t srcCols = targetImage->getCols();
    std::size_t srcX, srcY; // coordinates of the source pixel
    std::size_t destRows = dst.getRows();
    std::size_t destCols = dst.getCols();

    pixel_ptr_vector destPixels;

    for (std::size_t destX = 0; destX < destRows; ++destX) {
        srcX = (std::size_t)((double) srcRows * (double) destX / (double)destRows); 
        srcX = (std::size_t)(std::min((double)srcX, (double)(srcRows - 1)));
        for (std::size_t destY = 0; destY < destCols; ++destY) {
            srcY = (std::size_t)((double) srcCols * (double) destY / (double)destCols);
            srcY = (std::size_t)(std::min((double)srcY, (double)(srcCols - 1)));

            destPixels.push_back(
                targetImage->getPixelAt(Point(srcX, srcY)));
        }
    }

    targetImage->movePixelsFromWith(std::move(destPixels), dst);
    return true;
}

bool Editor::ditherImage(std::string algorithmName) const {
    if (algorithmName == "Linear") {
        DitherLinear dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "Atkinson") {
        DitherAtkinson dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "Burkes") {
        DitherBurkes dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "FS") {
        DitherFS dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "JJN") {
        DitherJJN dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "Sierra") {
        DitherSierra dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "SierraLite") {
        DitherSierraLite dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "TRSierra") {
        DitherTRSierra dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "Stucki") {
        DitherStucki dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "4Bayer") {
        Dither4Bayer dither;
        dither.ditherImage(targetImage);
    }
    else if (algorithmName == "8Bayer") {
        Dither8Bayer dither;
        dither.ditherImage(targetImage);
    }
    else {
        return false;
    }

    return true;
}