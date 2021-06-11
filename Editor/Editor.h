#ifndef EDITOR_H
#define EDITOR_H

#include "../Image/Image.h"
/**
 * Singleton class.
 * Allows cropping, resizing and dithering an image.
 */
class Editor {
    private:
        Editor();
    public:
        Editor(const Editor&) = delete;
        Editor& operator=(const Editor&) = delete;

        static Editor& instance();

        /**
         * @brief Crops image.
         * @param image pointer to the image being editted
         * @param x1 x-coordinate of upper left point
         * @param y1 y-coordinate of upper left point
         * @param x2 x-coordinate of lower right point
         * @param y2 y-coordinate of lower right point
         */
        void cropImage(Image* image, std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2);

        /**
         * @brief Resizes an image.
         * 
         * @param image pointer to the image being editted
         * @param destRows number of rows in the resized image
         * @param destCols number of columns in the resized image
         */
        void resizeImage(Image* image, std::size_t destRows, std::size_t destCols);
        void ditherImage(Image* image, std::string algorithmName);
};

#endif