#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../Pixel/Pixel.h"

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