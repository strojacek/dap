package com.jazz.interpreter;

//import com.jazz.parser.SASParser.Sas_stmt_blockContext;
import org.antlr.v4.runtime.ParserRuleContext;
import com.jazz.error.variable.UndefinedVariableException;
import com.jazz.visitor.Visitor;
import com.jazz.languageModels.JazzSubroutine;
import com.jazz.error.labels.UndefinedLabelException;
import com.jazz.error.subroutine.SubroutineArityException;
import com.jazz.error.subroutine.SubroutineNotDefinedException;
import com.jazz.error.subroutine.SubroutineRedefinitionException;
import com.jazz.languageModels.JazzValue;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;
import java.util.stream.IntStream;


/*
    @brief Stores the state of the interpreter.
    @details Used to store variables that are declated in the script and subroutines.
 */
public class JazzInterpreterState {
    // Hashtable that stores all the variables with the name of the variable as key of the entry
    private Map<String, JazzValue> memory = new HashMap<>();
    // Stores the defined functions of the executed script
    private final Map<String, JazzSubroutine> subroutines = new HashMap<>();
    private final Map<String, Sas_stmt_blockContext> labeledBlock = new HashMap<>();
    private String currentScript;
    private final ArrayDeque<JazzValue> dataSegment = new ArrayDeque<>();

    private final Stack<JazzValue> poppedDataList = new Stack<>();

    public ArrayDeque<JazzValue> getDataSegment() {
        return this.dataSegment;
    }

    public void addLabel(String labelName, Sas_stmt_blockContext blockContext) {
        this.labeledBlock.put(labelName, blockContext);
    }

    public JazzValue gotoLabel(String labelName, Visitor visitor, ParserRuleContext context) throws UndefinedLabelException {
        Sas_stmt_blockContext blockContext = this.labeledBlock.get(labelName);
        if (blockContext == null) {
            throw new UndefinedLabelException("A label called " + labelName + " is not defined", context);
        }
        return visitor.visit(blockContext);
    }


}
