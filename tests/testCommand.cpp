#include "../Catch2/catch.hpp"
#include "../src/CommandLogic/Command/Command.h"

/*
//  Helpers decalration and default data
*/

struct {
    std::string command = "default_command";
    std::string param = "default_param_"; // should be concatinated with a number
} DEFAULT_COMMAND_DATA;

void assertionsEmptyCommand(Command commandWithParams);
void assertionsNonemptyCommandWithNumParams(Command commandWithParams,
        std::size_t numParams);

Command getCommandWithNumParams(const std::size_t numParams);
Command getCommandWithNumParamsFromUntrimmed(const std::size_t numParams);
std::string getUniqueParamAt(const std::size_t index);

/*
//  Tests
*/

SCENARIO("Creating command with no params", "[no_params]") {
    GIVEN("A command with no params") {
        std::size_t numParams = 0;
        Command commandWithoutParams = getCommandWithNumParams(numParams);
            
        THEN("The assertions for an empty command hold") {
            assertionsEmptyCommand(commandWithoutParams);
        }
    }
}

SCENARIO("Creating command with no params from untrimmed", "[no_params]") {
    GIVEN("A command with no params") {
        std::size_t numParams = 0;
        Command commandWithoutParams = 
            getCommandWithNumParamsFromUntrimmed(numParams);
            
        THEN("The assertions for an empty command hold") {
            assertionsEmptyCommand(commandWithoutParams);
        }
    }
}

SCENARIO("Creating command with one param", "[with_params]") {
    GIVEN("A command with one param") {
        std::size_t numParams = 1;
        Command oneParamCommand = getCommandWithNumParams(numParams);
            
        THEN("The assertions for a nonempty command hold") {
            assertionsNonemptyCommandWithNumParams(oneParamCommand, 
                numParams);
        }
    }
}

SCENARIO("Creating command with two params", "[with_params]") {
    GIVEN("A command with two params") {
        std::size_t numParams = 2;    
        Command twoParamCommand = getCommandWithNumParams(numParams);
            
        THEN("The assertions for a nonempty command hold") {
            assertionsNonemptyCommandWithNumParams(twoParamCommand, 
                numParams);
        }
    }
}

SCENARIO("Creating command with two params from untrimmed", "[with_params]") {
    GIVEN("A command with two params from untrimmed string") {
        std::size_t numParams = 2;    
        Command commandFromUntrimmed = 
            getCommandWithNumParamsFromUntrimmed(numParams);
            
        THEN("The assertions for a nonempty command hold") {
            assertionsNonemptyCommandWithNumParams(commandFromUntrimmed, 
                numParams);
        }
    }
}

/*
//  Helpers implementation
*/

void assertionsEmptyCommand(Command commandWithoutParams) {
    REQUIRE(commandWithoutParams.getCommand() == DEFAULT_COMMAND_DATA.command);
    REQUIRE(commandWithoutParams.getParams().empty());
}

void assertionsNonemptyCommandWithNumParams(Command commandWithParams,
        std::size_t numParams) {
    REQUIRE(commandWithParams.getCommand() == DEFAULT_COMMAND_DATA.command);
    REQUIRE_FALSE(commandWithParams.getParams().empty());
    REQUIRE(commandWithParams.getParams().size() == numParams);
    for (std::size_t i = 0; i < numParams; ++i) {
        REQUIRE(commandWithParams.getParams().at(i) == getUniqueParamAt(i));
    }
}

Command getCommandWithNumParams(const std::size_t numParams) {
    std::string srcCommand = DEFAULT_COMMAND_DATA.command;
    std::string uniqueParam;

    for (std::size_t indexParam = 0; indexParam < numParams; ++indexParam) {
        uniqueParam = getUniqueParamAt(indexParam);
        srcCommand += " " + uniqueParam;
    }

    return Command(srcCommand);
}

Command getCommandWithNumParamsFromUntrimmed(const std::size_t numParams) {
    std::string srcCommand = "   " + DEFAULT_COMMAND_DATA.command + "  ";
    std::string uniqueParam;

    for (std::size_t indexParam = 0; indexParam < numParams; ++indexParam) {
        uniqueParam = getUniqueParamAt(indexParam);
        srcCommand += "  " + uniqueParam + "  ";
    }

    return Command(srcCommand);
}

std::string getUniqueParamAt(const std::size_t index) {
    return DEFAULT_COMMAND_DATA.param + std::to_string(index);
}