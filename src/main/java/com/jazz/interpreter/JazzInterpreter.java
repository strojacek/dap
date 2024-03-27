package com.jazz.interpreter;

/**
 * @file JazzInterpreter.java
 * @brief The Jazz Interpreter
 */

import com.jazz.parser.SASVisitor;
import com.jazz.parser.SASLexer;
import com.jazz.parser.SASParser;
import org.antlr.v4.runtime.BailErrorStrategy;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.InputMismatchException;
import org.antlr.v4.runtime.RecognitionException;
import org.antlr.v4.runtime.misc.ParseCancellationException;
import org.antlr.v4.runtime.tree.ParseTree;
import com.jazz.core.IOFormatter;
import com.jazz.error.ErrorListener;
import com.jazz.error.InterpreterBaseException;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;

public class JazzInterpreter {
    /// The standard input stream used by the interpreter
    private final InputStream stdin;
    /// The standard output stream used by the interpreter
    private final PrintStream stdoutPrint;
    /// The standard error output stream used by the interpreter
    private final PrintStream stderrPrint;
    /// The Memory object instance used to store variables
    private JazzInterpreterState state;

    /**
     * @brief Constructor a new Interpreter object instance
     * @param stdin The standard input stream used by the interpreter
     * @param stdout The standard output stream used by the interpreter
     * @param stderr The standard error stream used by the interpreter
     */
    public JazzInterpreter(InputStream stdin, OutputStream stdout, OutputStream stderr) {
        this.stdin = stdin;
        this.stdoutPrint = new PrintStream(stdout, true);
        this.stderrPrint = new PrintStream(stderr, true);
    }

    public void run(InputStream inputStream) throws IOException, RecognitionException {
			        // Wrapping the sourcecode in a ANTLRInputStream
        CharStream input = CharStreams.fromStream(programInput);
        // Initializing a newly created lexer object with the ANTLRInputStream
        SASLexer lexer = new SASLexer(input);
        // Creating a stream of tokens with the lexer
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        // Creating a parser object with the stream of tokens
        SASParser parser = new SASParser(tokens);
        // Default bailout error strategy
        parser.setErrorHandler(new BailErrorStrategy());
        // Removing default error listeners
        parser.removeErrorListeners();
        // Adding our own error listener
        parser.addErrorListener(new ErrorListener(this.stderrPrint));
        try {
            // We create an abstract syntax tree from the tokens
            ParseTree tree = parser.program();
            // Memory used by the program
            this.state = new JazzInterpreterState();
            this.state.setCurrentScript(input.toString());
            // Creating the visitor to visit the nodes in the abstract syntax tree
            JazzVisitor visitor = new JazzVisitor(this.state, this.stdin, this.stdoutPrint);
            // Executing the program with the visitor
            visitor.visit(tree);
        }
        catch (InterpreterBaseException exception) {
            this.stderrPrint.println(exception.getMessage());
        }
        catch (ParseCancellationException exception) {
            if (exception.getCause() instanceof InputMismatchException) {
                InputMismatchException exceptionCause = (InputMismatchException) exception.getCause();
                String syntaxErrorMessage = IOFormatter.formatErrorMessage(
                        exceptionCause.getOffendingToken().getLine(),
                        exceptionCause.getOffendingToken().getCharPositionInLine(),
                        "Syntax error");
                this.stderrPrint.println(syntaxErrorMessage);
            }
        }
    }


    }

        /**
     * @return The memory of the interpreter
     * @brief Gets the memory associated with the interpreter
     * @details The memory associated with the interpreter is a simple hashtable that stores all the variables that are declared in the program
     */
    public JBasicInterpreterState getState() {
        return this.state;
    }

    /**
     * Deallocates the memory used by the interpreter and
     * erases all the label and function definitions
     */
    public void clear() {
        this.state.freeMemory();
        this.state.eraseLabels();
        this.state.eraseSubroutines();
    }

}
