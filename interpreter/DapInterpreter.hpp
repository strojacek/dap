#include <iostream>
#include <string>
#include <memory>
#include "antlr4-runtime.h"
#include "SASLexer.h"
#include "SASParser.h"
#include "SASVisitor.h"
#include "IOFormatter.h"
#include "JazzInterpreterState.h"
#include "ErrorListener.h"

class JazzInterpreter {
private:
    std::istream& stdin;
    std::ostream& stdout;
    std::ostream& stderr;
    std::unique_ptr<JazzInterpreterState> state;

public:
    JazzInterpreter(std::istream& stdin, std::ostream& stdout, std::ostream& stderr)
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
            state = std::make_unique<JazzInterpreterState>();
            state->setCurrentScript(input.toString());

            JazzVisitor visitor(state, stdin, stdout);
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

    JazzInterpreterState* getState() {
        return state.get();
    }

    void clear() {
        state->freeMemory();
        state->eraseLabels();
        state->eraseSubroutines();
    }
};

