#ifndef IMAGE_HELPEPR
#define IMAGE_HELPER

#include <string>

enum fileType {
    PBM,
    PGM,
    PPM,
    COUNT,  // number of possible types
    ERROR   // to be used to indicatet an error
};

struct ImageParameters{
    fileType type;
    short unsigned rows;
    short unsigned cols;
    short unsigned pixelMaxValue;
};

fileType getTypeFrom(std::string type) {
    std::string types[COUNT] = {"P1", "P2", "P3"};
    for (int i = 0; i < COUNT; ++i) {
        if (type.compare(types[i]) == 0) {
            return (fileType)i;
        }
    }

    return ERROR;
}

std::string getStringFrom(fileType type) {
    std::string types[COUNT] = {"P1", "P2", "P3"};
    return types[type];
}

#endif