#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

// Allows the execution of a command in the form of a string.
// The command is formated in the needed way before calling 
// the respective function.

class CommandInterpreter {
    // allows testing private functions through afriend class
    #ifdef COMMAND_INTERPRETER_TEST
        friend class CommandInterpreterTester;
    #endif

    private:
        static const std::size_t MAX_NUMBER_PARAMETERS = 1;

        static void toLower(std::string& str);
        static void removeAdditionalSpaces(std::string& str);

        static void splitInArray(std::string str, std::string commPar[]);

        // Formats the command in the needed form.
        static void formatCommand(std::string commandAndParameters, std::string commPar[]);

        static void callFunction(std::string commPar[]);
    public:
        static void execute(std::string commandAndParameters);
};

#endif