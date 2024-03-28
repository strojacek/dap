#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "error/InterpreterBaseException.h" // Assuming you have defined InterpreterBaseException
#include "core/IOFormatter.hpp" // Assuming you have defined IOFormatter

class ArrayDimensionMismatchException : public InterpreterBaseException {
public:
    ArrayDimensionMismatchException(const std::string& message, antlr4::ParserRuleContext* context)
        : InterpreterBaseException(message, context) {}
};

