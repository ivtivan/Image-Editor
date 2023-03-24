#include "../Catch2/catch.hpp"
#include "../src/Controllers/ControllerFacade/ControllerFacade.h"
#include <iostream>

/*
//  Helpers decalration and default data
*/
void assertionsUnsuccessfulSave(ControllerFacade SUT);
void assertionsSuccessfulClose(ControllerFacade SUT);

/*
//  Tests
*/
SCENARIO("Closing ControllerFacade", "[right_usage]") {
    GIVEN("") {
        ControllerFacade SUT;
        THEN("saving returns false") {
            assertionsSuccessfulClose(SUT);
        }
    }
}

SCENARIO("Saving ControllerFacade without setting filepath", "[wrong_usage]") {
    GIVEN("A ControllerFacade without set path of FileController") {
        ControllerFacade SUT;
        THEN("saving returns false") {
            assertionsUnsuccessfulSave(SUT);
        }
    }
}


SCENARIO("Saving ControllerFacade by specigfying file path", "[right_usage]") {
    //  TODO with Image mock
}

void assertionsUnsuccessfulSave(ControllerFacade SUT) {
    REQUIRE_FALSE(SUT.save());
}

void assertionsSuccessfulClose(ControllerFacade SUT) {
    REQUIRE(SUT.close());
}
