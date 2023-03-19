#include "Dimension.h"

Dimension::Dimension(std::size_t rows, std::size_t cols) : 
    rows(rows), cols(cols) {
    ;
}

std::size_t Dimension::getRows() {
    return rows;
}

std::size_t Dimension::getCols() {
    return cols;
}