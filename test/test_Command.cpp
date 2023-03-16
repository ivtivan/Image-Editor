// #define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../Command/Command.h"

SCENARIO("Testing command constructor", "[constructor]") {
    GIVEN("A string") {
        std::string testString = "  tESt string   VALUE  ";
        WHEN("The command is created") {
            Command testCommand(testString);
            
            THEN("The command elements are right") {
                REQUIRE(testCommand[0] == "test");
                REQUIRE(testCommand[1] == "string");
                REQUIRE(testCommand[2] == "VALUE");
            }
        }
    }
}