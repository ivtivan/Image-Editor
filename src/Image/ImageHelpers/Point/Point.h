#ifndef POINT_H
#define POINT_H

#include <cstddef>

class Point {
    private:
        std::size_t x;
        std::size_t y;
    public:
        Point(std::size_t x, std::size_t y);

        std::size_t getX() const;
        std::size_t getY() const;
};

#endif