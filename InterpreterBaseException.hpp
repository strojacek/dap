#include "antlr4-runtime.h"
#include "IOFormatter.h" // Assuming IOFormatter is a custom class or library

class InterpreterBaseException : public std::runtime_error {
private:
    int line;
    int positionInLine;

public:
    InterpreterBaseException(const std::string& message, antlr4::ParserRuleContext* context)
        : std::runtime_error(message), line(context->getStart()->getLine()), 
        positionInLine(context->getStart()->getCharPositionInLine()) {}

    int getLine() const { return line; }
    int getPositionInLine() const { return positionInLine; }

    virtual const char* what() const noexcept override {
        return IOFormatter::formatErrorMessage(line, positionInLine, std::runtime_error::what()).c_str();
    }
};
