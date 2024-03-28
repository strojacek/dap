#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "error/InterpreterBaseException.hpp" // Assuming you have defined InterpreterBaseException
#include "core/IOFormatter.hpp" // Assuming you have defined IOFormatter

class UndefinedVariableException : public InterpreterBaseException {
public:
    UndefinedVariableException(const std::string& message, antlr4::ParserRuleContext* context)
        : InterpreterBaseException(message, context) {}
};

