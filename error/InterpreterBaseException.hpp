#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "IOFormatter.hpp"

class InterpreterBaseException : public std::runtime_error {
private:
    int line;
    int positionInLine;

public:
    InterpreterBaseException(const std::string& message, antlr4::ParserRuleContext* context)
        : std::runtime_error(message), line(context->start->getLine()), 
          positionInLine(context->start->getCharPositionInLine()) {}

    std::string getMessage() {
        return IOFormatter::formatErrorMessage(line, positionInLine, what());
    }
};

