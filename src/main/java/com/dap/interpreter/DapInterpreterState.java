package com.dap.interpreter;

//import com.dap.parser.SASParser.Sas_stmt_blockContext;
import org.antlr.v4.runtime.ParserRuleContext;
import com.dap.error.variable.UndefinedVariableException;
import com.dap.visitor.Visitor;
import com.dap.languageModels.DapSubroutine;
import com.dap.error.labels.UndefinedLabelException;
import com.dap.error.subroutine.SubroutineArityException;
import com.dap.error.subroutine.SubroutineNotDefinedException;
import com.dap.error.subroutine.SubroutineRedefinitionException;
import com.dap.languageModels.DapValue;

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
public class DapInterpreterState {
    // Hashtable that stores all the variables with the name of the variable as key of the entry
    private Map<String, DapValue> memory = new HashMap<>();
    // Stores the defined functions of the executed script
    private final Map<String, DapSubroutine> subroutines = new HashMap<>();
    private final Map<String, Sas_stmt_blockContext> labeledBlock = new HashMap<>();
    private String currentScript;
    private final ArrayDeque<DapValue> dataSegment = new ArrayDeque<>();

    private final Stack<DapValue> poppedDataList = new Stack<>();

    public ArrayDeque<DapValue> getDataSegment() {
        return this.dataSegment;
    }

    public void addLabel(String labelName, Sas_stmt_blockContext blockContext) {
        this.labeledBlock.put(labelName, blockContext);
    }

    public DapValue gotoLabel(String labelName, Visitor visitor, ParserRuleContext context) throws UndefinedLabelException {
        Sas_stmt_blockContext blockContext = this.labeledBlock.get(labelName);
        if (blockContext == null) {
            throw new UndefinedLabelException("A label called " + labelName + " is not defined", context);
        }
        return visitor.visit(blockContext);
    }


}
