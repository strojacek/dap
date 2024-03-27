package com.jazz.core;

/**
 * @file IOFFormatter.java
 * @brief IO formatting utility methods.
 */



import java.text.DecimalFormat;

/**
 * @brief IO formatting utilities.
 * @details The IO formatting utilities of the interpreter
 */
public class IOFormatter {

    /// Decimal output format for numerical values (no decimal dot if the number is x.0)
    public static final DecimalFormat numericalOutputFormat = new DecimalFormat("0.##############");

    /**
     * Formats an error message with the line and the position in the line where the error occurred
     *
     * @param line           The line where the error occurred
     * @param positionInLine The position in the line where the error occurred
     * @param message        The error message that is displayed
     */
    public static String formatErrorMessage(int line, int positionInLine, String message) {
        return "Error at [" + line + ", " + positionInLine + "]: " + message;
    }
}