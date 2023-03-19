#ifndef DIMENSION_H
#define DIMENSION_H

#include <cstddef>

class Dimension {
    private:
        std::size_t rows;
        std::size_t cols;
    public:
        Dimension(std::size_t rows, std::size_t cols);

        std::size_t getRows() const;
        std::size_t getCols() const;
};

#endif