package com.dap.error;

import org.antlr.v4.runtime.BaseErrorListener;
import org.antlr.v4.runtime.RecognitionException;
import org.antlr.v4.runtime.Recognizer;

import java.io.PrintStream;
public class ErrorListener extends BaseErrorListener {

    // The standard error output stream
    private final PrintStream stderr;

    public ErrorListener(PrintStream stderr) {
        this.stderr = stderr;
    }

    @Override
    public void syntaxError(Recognizer<?, ?> recognizer,
                            Object offendingSymbol,
                            int line,
                            int characterPositionInLine,
                            String message,
                            RecognitionException exception) {
        this.stderr.println(message);
    }
}
