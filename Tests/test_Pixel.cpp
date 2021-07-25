#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../Pixel/Pixel.h"
#include "../CustomExceptions/CustomExceptions.h"

SCENARIO("Testing setting value through string", "[setter]") {
    GIVEN("A pixel and a color in two formats") {
        const double EPS = 1.0 / (1 << 30); 
        Pixel testPixel;
        std::string color = "#909090"; // rgb = (144, 144, 144)
        int expectedValues[3] = {144 , 144, 144};

        // Formula from Pixel::getValue()
        double expectedGetValue = (double)expectedValues[0] * 0.3 + 
            (double)expectedValues[1] * 0.59 + (double)expectedValues[2] * 0.11;
        
        WHEN("The pixel's value is set through the string") {
            testPixel.setValue(color);
            
            THEN("The right value is set") {
                REQUIRE(testPixel.getValue() - expectedGetValue < EPS);
            }
        }
    }
}

SCENARIO("Testing setting RGB", "[setter]") {
    GIVEN("A pixel which is not RGB with max value the half of the max RGB value") {
        const double EPS = 1.0 / (1 << 30);
        unsigned int maxValueRGB = 255;
        unsigned int testPixelValue = 45;

        Pixel testPixel;
        testPixel.setMaxValue(maxValueRGB / 2);
        testPixel.setValue(testPixelValue);
        
        WHEN("The pixel's is set to RGB") {
            testPixel.setRGB(true);
            
            THEN("The value changes accordingly") {
                REQUIRE(testPixel.getValue() - 
                    (double)maxValueRGB / (double)testPixelValue * (double)testPixelValue < EPS);
            }
        }
    }

    GIVEN("A nongrey RGB pixel") {
        const double EPS = 1.0 / (1 << 30);
        unsigned int maxValueRGB = 255;
        unsigned int testPixelValue[3] = {45, 23, 144};

        Pixel testPixel;
        testPixel.setValue(testPixelValue);
        
        WHEN("The pixel's is set to nonRGB") {
            THEN("A PixelException is thrown") {
                REQUIRE_THROWS_AS(testPixel.setRGB(false), PixelException);
            }
        }
    }
}

SCENARIO("Testing setting black or white", "[black_white]") {
    GIVEN("A white pixel") {
        const double EPS = 1.0 / (1 << 30);
        unsigned int maxValueRGB = 255;
        unsigned int testPixelValue[3] = {maxValueRGB, maxValueRGB, maxValueRGB};

        Pixel testPixel;
        testPixel.setValue(testPixelValue);
        
        WHEN("The function to set pixel black or white is called") {
            testPixel.setBlackOrWhite();
            
            THEN("The values change accordingly") {
                REQUIRE(testPixel.getMaxValue() == 1);
                REQUIRE(testPixel.getValue() - 1.0 < EPS);
            }
        }
    }

    GIVEN("A nonwhite and nonblack RGB pixel") {
        const double EPS = 1.0 / (1 << 30);
        unsigned int testPixelValue[3] = {45, 23, 144};

        Pixel testPixel;
        testPixel.setValue(testPixelValue);
        
        WHEN("The function to set pixel black or white is called") {
            THEN("A PixelException is thrown") {
                REQUIRE_THROWS_AS(testPixel.setBlackOrWhite(), PixelException);
            }
        }
    }
}

SCENARIO("Testing swapping black or white", "[black_white]") {
    GIVEN("A white pixel") {
        const double EPS = 1.0 / (1 << 30);
        unsigned int maxValueRGB = 255;
        unsigned int testPixelValue[3] = {maxValueRGB, maxValueRGB, maxValueRGB};

        Pixel testPixel;
        testPixel.setValue(testPixelValue);
        
        WHEN("The function to swap black and white is called") {
            testPixel.swapBlackAndWhite();
            
            THEN("The pixel is black") {
                REQUIRE(testPixel.getValue() - 0.0 < EPS);
            }
        }
    }

    GIVEN("A nonwhite and nonblack RGB pixel") {
        const double EPS = 1.0 / (1 << 30);
        unsigned int testPixelValue[3] = {45, 23, 144};

        Pixel testPixel;
        testPixel.setValue(testPixelValue);
        
        WHEN("The function to swap black and white is called") {
            THEN("A PixelException is thrown") {
                REQUIRE_THROWS_AS(testPixel.swapBlackAndWhite(), PixelException);
            }
        }
    }
}

SCENARIO("Testing checking if a pixel is black or white", "[black_white]") {
    GIVEN("A pixel") {
        Pixel testPixel;
        
        WHEN("The pixel value is set to 0") {
            unsigned int minValue = 0;
            testPixel.setValue(minValue);
            
            THEN("The pixel is black or white") {
                REQUIRE(testPixel.isBlackOrWhite() == true);
            }
        }

        WHEN("The pixel value is set to the pixels maxValue") {
            testPixel.setValue(testPixel.getMaxValue());
            
            THEN("The pixel is black or white") {
                REQUIRE(testPixel.isBlackOrWhite() == true);
            }
        }

        WHEN("The pixel value is set to a nonblack or notwhite color") {
            unsigned int testPixelValue[3] = {45, 23, 144};
            testPixel.setValue(testPixelValue);
            
            THEN("The pixel is neither black nor white") {
                REQUIRE(testPixel.isBlackOrWhite() == false);
            }
        }
    }
}

SCENARIO("Testing checking if a pixel is grey", "[grey]") {
    GIVEN("A pixel") {
        Pixel testPixel;
        
        WHEN("The pixel value is set to 0") {
            unsigned int minValue = 0;
            testPixel.setValue(minValue);
            
            THEN("The pixel is grey") {
                REQUIRE(testPixel.isGrey() == true);
            }
        }

        WHEN("The pixel value is set to the pixels maxValue") {
            testPixel.setValue(testPixel.getMaxValue());
            
            THEN("The pixel is grey") {
                REQUIRE(testPixel.isGrey() == true);
            }
        }

        WHEN("The pixel value is set to a shade of grey") {
            unsigned int testPixelValue[3] = {45, 45, 45};
            testPixel.setValue(testPixelValue);
            
            THEN("The pixel is grey") {
                REQUIRE(testPixel.isGrey() == true);
            }
        }

        WHEN("The pixel value is set to a nongrey color") {
            unsigned int testPixelValue[3] = {45, 23, 144};
            testPixel.setValue(testPixelValue);
            
            THEN("The pixel is not grey") {
                REQUIRE(testPixel.isGrey() == false);
            }
        }
    }
}

SCENARIO("Changing dither value", "[dither]") {
    GIVEN("A pixel and a dither value") {
        const double EPS = 1.0 / (1 << 30); 
        Pixel testPixel;
        double ditherIncrement = 5.0;

        WHEN("The pixel's dither value is incremented twice") {
            testPixel.incrementDitherValue(ditherIncrement);
            testPixel.incrementDitherValue(ditherIncrement);
            
            THEN("The right dither value is stored") {
                REQUIRE(testPixel.getDitherValue() - 2.0 * ditherIncrement < EPS);
            }

            AND_WHEN("The dither value is reset") {
                testPixel.resetDitherValue();

                THEN("The dither value is 0") {
                    REQUIRE(testPixel.getDitherValue() - 0.0 < EPS);
                }
            }
        }
    }
}