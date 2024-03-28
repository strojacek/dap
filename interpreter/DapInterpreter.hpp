#include <iostream>
#include <string>
#include <memory>
#include "antlr4-runtime.h"
#include "SASLexer.h"
#include "SASParser.h"
#include "SASVisitor.h"
#include "IOFormatter.h"
#include "DapInterpreterState.h"
#include "ErrorListener.h"

class DapInterpreter {
private:
    std::istream& stdin;
    std::ostream& stdout;
    std::ostream& stderr;
    std::unique_ptr<DapInterpreterState> state;

public:
    DapInterpreter(std::istream& stdin, std::ostream& stdout, std::ostream& stderr)
        : stdin(stdin), stdout(stdout), stderr(stderr) {}

    void run(std::istream& inputStream) {
        antlr4::ANTLRInputStream input(inputStream);
        SASLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        SASParser parser(&tokens);

        // Error handling
        parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());
        parser.removeErrorListeners();
        parser.addErrorListener(new ErrorListener(stderr));

        try {
            antlr4::tree::ParseTree* tree = parser.program();
            state = std::make_unique<DapInterpreterState>();
            state->setCurrentScript(input.toString());

            DapVisitor visitor(state, stdin, stdout);
            visitor.visit(tree);
        } catch (InterpreterBaseException& exception) {
            stderr << exception.what() << std::endl;
        } catch (antlr4::ParseCancellationException& exception) {
            antlr4::InputMismatchException* cause = dynamic_cast<antlr4::InputMismatchException*>(exception.getCause());
            if (cause) {
                std::string syntaxErrorMessage = IOFormatter::formatErrorMessage(
                    cause->getOffendingToken()->getLine(),
                    cause->getOffendingToken()->getCharPositionInLine(),
                    "Syntax error"
                );
                stderr << syntaxErrorMessage << std::endl;
            }
        }
    }

    DapInterpreterState* getState() {
        return state.get();
    }

    void clear() {
        state->freeMemory();
        state->eraseLabels();
        state->eraseSubroutines();
    }
};

