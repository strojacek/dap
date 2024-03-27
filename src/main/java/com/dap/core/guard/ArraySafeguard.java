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
 * @file ArraySafeguard.java
 * @brief Guarding functions for JBASIC arrays.
 */

package com.dap.core.guard;

import dap.DapParser;
import org.antlr.v4.runtime.ParserRuleContext;
import org.dap.languageModels.DapValue;
import org.dap.error.arrays.ArrayDimensionMismatchException;
import org.dap.error.arrays.ArrayDimensionUnsupportedException;

import java.util.List;

/**
 * @brief Guarding functions for JBASIC arrays.
 */
public class ArraySafeguard {

    /**
     * Ensures the argument is a valid array dimension
     *
     * @param argument The argument that is safeguarded
     * @param context The parsing context of the array dimension
     */
    public static void guaranteeArrayDimensionIsValid(DapValue argument, ParserRuleContext context)
            throws ArrayDimensionUnsupportedException {
        ValueTypeSafeguard.guaranteeValueIsNumerical("Could not create array", argument, context);
        if (argument.underlyingNumber() <= 0) {
            throw new ArrayDimensionUnsupportedException("Dimensions can not be negative or zero", context);
        }
        NumericalValueSafeguard.guaranteeIsWhole("Dimensions can not have numbers after the digit",
                argument.underlyingNumber(), context);
    }

    /**
     * Ensures the array dimension count in an expression is valid
     *
     * @param expressionContexts The argument that is safeguarded
     */
    public static void guaranteeArrayDimensionCountIsValid(List<DapParser.ExpressionContext> expressionContexts)
            throws ArrayDimensionUnsupportedException{
        if (expressionContexts.size() > 3 || expressionContexts.size() == 0) {
            throw new ArrayDimensionUnsupportedException(
                    "Unsupported array dimensions count " + expressionContexts.size(),
                    expressionContexts.get(expressionContexts.size() - 1));
        }
    }

    /**
     * Ensures that the amount of dimensions of an array and the specified dimensions in a statement match
     *
     * @param array The array that is accessed
     * @param expressionContexts The parsing context of the expressions that specified the dimension
     */
    public static void guaranteeArrayDimensionsMatch(DapValue array, List<DapParser.ExpressionContext> expressionContexts) {
        switch (expressionContexts.size()) {
            case 1:
                if (!array.isAnOneDimensionalArrayValue()) {
                    throw new ArrayDimensionMismatchException(
                            "The dimensions that were specified do not match the dimensions of the array",
                            expressionContexts.get(expressionContexts.size() - 1));
                }
                break;
            case 2:
                if (!array.isATwoDimensionalArrayValue()) {
                    throw new ArrayDimensionMismatchException(
                            "The dimensions that were specified do not match the dimensions of the array",
                            expressionContexts.get(expressionContexts.size() - 1));
                }
                break;
            case 3:
                if (!array.isAThreeDimensionalArrayValue()) {
                    throw new ArrayDimensionMismatchException(
                            "The dimensions that were specified do not match the dimensions of the array",
                            expressionContexts.get(expressionContexts.size() - 1));
                }
                break;
            default:
                throw new IllegalStateException("Unexpected value: " + expressionContexts.size());
        }
    }
}
