#include "Point.h"

Point::Point(std::size_t x, std::size_t y) : x(x), y(y) {
    ;
}

std::size_t Point::getX() const {
    return x;
}

std::size_t Point::getY() const {
    return y;
}