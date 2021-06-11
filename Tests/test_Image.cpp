// #define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../Image/Image.h"
#include "../CustomExceptions/ImageException/ImageException.h"
#include "../CustomExceptions/FileException/FileException.h"
#include <cmath>

SCENARIO("Testing setting pixels through pixel matrix", "[setter]") {
    GIVEN("An image and pixel matrix") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        Pixel** testPixels = new Pixel*[testRows];
        for (std::size_t i = 0; i < testRows; ++i) {
            testPixels[i] = new Pixel[testCols];
        }

        WHEN("The image's pixels are set") {
            testImage.setPixels(testPixels, testRows, testCols);

            THEN("The number of rows and columns changes and the pixels are set") {
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
            }
        }
    }
}

SCENARIO("Testing setting pixels through color", "[setter]") {
    GIVEN("An image and invalid colors") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        std::string wrongColor1 = "1212123";
        std::string wrongColor2 = "#12221";
        std::string wrongColor3 = "##231Fd";

        WHEN("Setters are called") {
            THEN("ImageException is thrown") {
                REQUIRE_THROWS_AS(testImage.setPixels(wrongColor1, testRows, testCols), ImageException);
                REQUIRE_THROWS_AS(testImage.setPixels(wrongColor2, testRows, testCols), ImageException);
                REQUIRE_THROWS_AS(testImage.setPixels(wrongColor3, testRows, testCols), ImageException);
            }
        }
    }

    GIVEN("An image and а valid color") {
        const double EPS = 1.0 / (1 << 30);
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        std::string color = "#212123";

        WHEN("Setter is called") {
            testImage.setPixels(color, testRows, testCols);
            THEN("Image is correct") {
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getMaxValue() - 255.0) < EPS);
                REQUIRE(testImage.getPixels()[0][0].getValue() != 0);
            }
        }
    }
}

SCENARIO("Testing resetting image", "[reset]") {
    GIVEN("An image with set pixels") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        Pixel** testPixels = new Pixel*[testRows];
        for (std::size_t i = 0; i < testRows; ++i) {
            testPixels[i] = new Pixel[testCols];
        }

        testImage.setPixels("#909090", testRows, testCols);

        WHEN("The image is reset") {
            testImage.reset();
            THEN("The number of rows and columns is 0 and the pixels are not set") {
                REQUIRE(testImage.getRows() == 0);
                REQUIRE(testImage.getCols() == 0);
                REQUIRE(testImage.getPixels() == nullptr);
            }
        }
    }
}


SCENARIO("Testing converting an image", "[convert]") {
    const double EPS = 1.0 / (1 << 30);

    GIVEN("A black PPM image") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        testImage.setPixels("#000000", testRows, testCols);

        WHEN("The image is converted to PBM") {
            testImage.convertTo(PBM);

            THEN("The image is successfully converted") {
                REQUIRE(testImage.getFileType() == PBM);
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getValue() - 1.0) < EPS);
            }
        }
    }

    GIVEN("A grey PPM image") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        testImage.setPixels("#090909", testRows, testCols);

        WHEN("The image is converted to PGM") {
            testImage.convertTo(PGM);
            THEN("The image is successfully converted") {
                REQUIRE(testImage.getFileType() == PGM);
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getValue() - 9.0) < EPS);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getMaxValue() - 255.0) < EPS);
            }
        }

        WHEN("The image is converted to PBM") {
            THEN("A FileException is thrown") {
                REQUIRE_THROWS_AS(testImage.convertTo(PBM), FileException);
            }
        }
    }

    GIVEN("A nongrey PPM image") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        testImage.setPixels("#127812", testRows, testCols);

        WHEN("The image is converted to PGM") {
            THEN("A FileException is thrown") {
                REQUIRE_THROWS_AS(testImage.convertTo(PGM), FileException);
            }
        }

        WHEN("The image is converted to PBM") {
            THEN("A FileException is thrown") {
                REQUIRE_THROWS_AS(testImage.convertTo(PBM), FileException);
            }
        }
    }

    GIVEN("A black PBM image") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        testImage.setPixels("#000000", testRows, testCols);
        testImage.convertTo(PBM);

        WHEN("The image is converted to PGM") {
            testImage.convertTo(PGM);

            THEN("The image is successfully converted") {
                REQUIRE(testImage.getFileType() == PGM);
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getValue() - 0.0) < EPS);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getMaxValue() - 1.0) < EPS);
            }
        }

        WHEN("The image is converted to PPM") {
            testImage.convertTo(PPM);

            THEN("The image is successfully converted") {
                REQUIRE(testImage.getFileType() == PPM);
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getValue() - 0.0) < EPS);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getMaxValue() - 255.0) < EPS);
            }
        }
    }

    GIVEN("A black PGM image") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        testImage.setPixels("#000000", testRows, testCols);
        testImage.convertTo(PGM);

        WHEN("The image is converted to PBM") {
            testImage.convertTo(PBM);

            THEN("The image is successfully converted") {
                REQUIRE(testImage.getFileType() == PBM);
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getValue() - 1.0) < EPS);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getMaxValue() - 1.0) < EPS);
            }
        }

        WHEN("The image is converted to PPM") {
            testImage.convertTo(PPM);

            THEN("The image is successfully converted") {
                REQUIRE(testImage.getFileType() == PPM);
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getValue() - 0.0) < EPS);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getMaxValue() - 255.0) < EPS);
            }
        }
    }

    GIVEN("A grey PGM image") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        testImage.setPixels("#090909", testRows, testCols);
        testImage.convertTo(PGM);

        WHEN("The image is converted to PBM") {
            THEN("A fileException is thrown") {
                REQUIRE_THROWS_AS(testImage.convertTo(PBM), FileException);
            }
        }

        WHEN("The image is converted to PPM") {
            testImage.convertTo(PPM);

            THEN("The image is successfully converted") {
                REQUIRE(testImage.getFileType() == PPM);
                REQUIRE(testImage.getRows() == testRows);
                REQUIRE(testImage.getCols() == testCols);
                REQUIRE(testImage.getPixels() != nullptr);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getValue() - 9.0) < EPS);
                REQUIRE(std::abs(testImage.getPixels()[0][0].getMaxValue() - 255.0) < EPS);
            }
        }
    }
}