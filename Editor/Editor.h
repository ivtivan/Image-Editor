#ifndef EDITOR_H
#define EDITOR_H

#include "../Image/Image.h"

class Editor {
    private:
        Editor();
    public:
        Editor(const Editor&) = delete;
        Editor& operator=(const Editor&) = delete;

        static Editor& instance();

        // x1 <= x2, y1 <= y2
        void cropImage(Image* image, std::size_t x1 = 0, std::size_t y1 = 0, std::size_t x2 = 0, std::size_t y2 = 0);
        void resizeImage(Image* image, std::size_t destRows = 0, std::size_t destCols = 0);
        void ditherImage(Image* image, std::string algorithmName);
};

#endif