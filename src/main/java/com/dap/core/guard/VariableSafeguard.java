/****************************************************************************
 * Copyright (C) 2022 by Frederik Tobner                                    *
 *                                                                          *
 * This file is part of JBASIC.                                             *
 *                                                                          *
 * Permission to use, copy, modify, and distribute this software and its    *
 * documentation under the terms of the GNU General Public License is       *
 * hereby granted.                                                          *
 * No representations are made about the suitability of this software for   *
 * any purpose.                                                             *
 * It is provided "as is" without express or implied warranty.              *
 * See the <"https://www.gnu.org/licenses/gpl-3.0.html">GNU General Public  *
 * License for more details.                                                *
 ****************************************************************************/

/**
 * @file VariableSafeguard.java
 * @brief Guarding functions for JBASIC variables.
 */

package com.dap.core.guard;

import dap.DapParser;
import org.antlr.v4.runtime.ParserRuleContext;
import org.dap.error.type.TypeException;
import org.dap.error.variable.UndefinedVariableException;
import org.dap.languageModels.DapValue;

/**
 * @brief Guarding functions for JBASIC variables.
 */
public class VariableSafeguard {

    /**
     * Ensures that a variable is defined
     *
     * @param variableValue The value of the variable
     * @param variableName The name of the variable
     * @param context The parsing context where the variable was referred to
     */
    public static void guaranteeVariableIsDefined(DapValue variableValue, String variableName, ParserRuleContext context)
            throws UndefinedVariableException {
        if (variableValue == null) {
            throw new UndefinedVariableException(
                    "A variable with the name " + variableName + "is not defined",
                    context);
        }
    }

    /**
     * Ensures that a value is an array
     *
     * @param assignedValue The value that is safeguarded
     * @param context The parsing context where the value was used
     */
    public static void guaranteeVariableSuffixIsNotViolated(DapValue assignedValue, DapParser.VariableSuffixContext context)
            throws TypeException {
        if ("$".equals(context.getText())) {
            if (!assignedValue.isAStringValue()) {
                throw new TypeException("Type suffix does not match specified type", context);
            }
        }
        else if ("%".equals(context.getText())) {
            if (!assignedValue.isANumericalValue()) {
                throw new TypeException("Type suffix does not match specified type", context);
            }
        }
    }
}
