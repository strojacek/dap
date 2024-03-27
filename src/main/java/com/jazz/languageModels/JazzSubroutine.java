package com.jazz.languageModels;

import com.jazz.parser.SASParser;
public class JazzSubroutine {

    private final String[] arguments;

    /// Stores the parsing context of the functionBody, so we can execute it later
    private final SASParser.ParseContext [] statementsInBodyContexts;

    /**
     * Constructor of the JBASICSubroutine class
     *
     * @param arguments                   The names of the arguments of the subroutine
     * @param statementsInBodyContexts The parsing context of the body of the subroutine
     */
    public JazzSubroutine(String[] arguments, SASParser.ParseContext[] statementsInBodyContexts) {
        this.arguments = arguments;
        this.statementsInBodyContexts = statementsInBodyContexts;
    }

    /**
     * Gets the names of the arguments of the subroutine
     * @return The names of the arguments
     */
    public String[] getArguments() {
        return this.arguments;
    }

    /**
     * Gets the body of the subroutine
     *
     * @return The body of the subroutine
     */
    public SASParser.ParseContext[] getSubroutineBody() {
        return this.statementsInBodyContexts;
    }

    /**
     * Gets the arity, meaning the amount arguments the subroutine expects
     * @return The arity of the subroutine
     */
    public int getArity() {
        return this.arguments.length;
    }
}
