// #define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../Editor/Editor.h"
#include "../CustomExceptions/EditException/EditException.h"

SCENARIO("Testing cropping image", "[cropping]") {
    GIVEN("An image") {
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        Pixel** testPixels = new Pixel*[testRows];
        for (std::size_t i = 0; i < testRows; ++i) {
            testPixels[i] = new Pixel[testCols];
        }

        testImage.setPixels(testPixels, testRows, testCols);

        WHEN("A valid image is cropped") {
            Editor::instance().cropImage(*testImage, 1, 1, 10, 10);
            
            THEN("The number of rows and columns changes") {
                REQUIRE(testImage.getRows() == 9);
                REQUIRE(testImage.getCols() == 9);
            }
        }
        
        WHEN("A valid image is cropped with one of the points having large coordinates") {
            Editor::instance().cropImage(*testImage, 1, 1, 100, 100);
            
            THEN("The number of rows and columns changes") {
                REQUIRE(testImage.getRows() == 9);
                REQUIRE(testImage.getCols() == 9);
            }
        }

        WHEN("The passed coordinates are not valid") { 
            THEN("The number of rows and columns does not change a nd an exception is thrown") {
                REQUIRE_THROWS_AS(Editor::instance().cropImage(*testImage, 1, 1, 100, 0), EditException);
                REQUIRE(testImage.getCols() == 10);
            }
        }
    }
}


SCENARIO("Testing resizing image", "[resizing]") {
    GIVEN("An image") {
        const double EPS = 1.0 / (1 << 30);
        Image testImage;

        std::size_t testRows = 10;
        std::size_t testCols = 10;

        Pixel** testPixels = new Pixel*[testRows];
        for (std::size_t i = 0; i < testRows; ++i) {
            testPixels[i] = new Pixel[testCols];
        }

        testImage.setPixels(testPixels, testRows, testCols);

        std::size_t testColoredRow1 = 2;
        std::size_t testColoredRow2 = testColoredRow1 + 1;
        std::size_t testColoredCol1 = 2;
        std::size_t testColoredCol2 = testColoredCol1 + 1;
        unsigned int color = 1;
        for (std::size_t i = testColoredRow1; i <= testColoredRow2; ++i) {
            for (std::size_t j = testColoredCol1; j <= testColoredCol2; ++j) {
                testPixels[i][j].setValue(color);
            }
        }

        WHEN("The image is made bigger") {
            std::size_t resizeFactor = 2;
            Editor::instance().resizeImage(*testImage, testRows * resizeFactor, testCols * resizeFactor);
            
            THEN("The number of rows and columns changes and the pixelss,values are set right") {
                REQUIRE(testImage.getRows() == testRows * resizeFactor);
                REQUIRE(testImage.getCols() == testCols * resizeFactor);
                
                for (std::size_t i = testColoredRow1 * resizeFactor; i < (testColoredRow2 + 1) * resizeFactor; ++i) {
                    for (std::size_t j = testColoredCol1 * resizeFactor; j < (testColoredCol2 + 1) * resizeFactor; ++j) {
                        REQUIRE(std::abs(testImage.getPixels()[i][j].getValue() - (double)color) < EPS);
                    }
                }
            }
        }

        WHEN("The image is made smaller") {
            std::size_t resizeFactorDivisor = 2;
            Editor::instance().resizeImage(*testImage, testRows / resizeFactorDivisor, testCols / resizeFactorDivisor);
            
            THEN("The number of rows and columns changes and the pixelss,values are set right") {
                REQUIRE(testImage.getRows() == testRows / resizeFactorDivisor);
                REQUIRE(testImage.getCols() == testCols / resizeFactorDivisor);
                for (std::size_t i = testColoredRow1 / resizeFactorDivisor; i < (testColoredRow2 + 1) / resizeFactorDivisor; ++i) {
                    for (std::size_t j = testColoredCol1 / resizeFactorDivisor; j < (testColoredCol2 + 1) / resizeFactorDivisor; ++j) {
                        REQUIRE(std::abs((double)testImage.getPixels()[i][j].getValue() - (double)color) < EPS);
                    }
                }
            }
        }
    }
}