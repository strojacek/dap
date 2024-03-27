#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "InterpreterBaseException.h" // Assuming you have defined InterpreterBaseException
#include "IOFormatter.h" // Assuming you have defined IOFormatter

class SubroutineRedefinitionException : public InterpreterBaseException {
public:
    SubroutineRedefinitionException(const std::string& message, antlr4::ParserRuleContext* context)
        : InterpreterBaseException(message, context) {}
};

