#include "../Catch2/catch.hpp"
#include "../src/Controllers/FileController/FileController.h"
#include <iostream>

/*
//  Helpers decalration and default data
*/
void assertionsUnsuccessfulSave(FileController SUT);
void assertionsSuccessfulClose(FileController SUT);

/*
//  Tests
*/
SCENARIO("Closing", "[wrong_usage]") {
    GIVEN("A FileController without set path") {
        FileController SUT;
        THEN("saving returns false") {
            assertionsSuccessfulClose(SUT);
        }
    }
}

SCENARIO("Saving without setting filepath", "[wrong_usage]") {
    GIVEN("A FileController without set path") {
        FileController SUT;
        THEN("saving returns false") {
            assertionsUnsuccessfulSave(SUT);
        }
    }
}


SCENARIO("Saving by specigfying file path", "[right_usage]") {
    //  TODO with Image mock
}

void assertionsUnsuccessfulSave(FileController SUT) {
    REQUIRE_FALSE(SUT.save());
}

void assertionsSuccessfulClose(FileController SUT) {
    REQUIRE(SUT.close());
}
