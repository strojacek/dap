#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

/**
 * @brief IO formatting utilities.
 * @details The IO formatting utilities of the interpreter
 */
class IOFormatter {
public:
    /// Decimal output format for numerical values (no decimal dot if the number is x.0)
    static const std::string numericalOutputFormat;

    /**
     * Formats an error message with the line and the position in the line where the error occurred
     *
     * @param line           The line where the error occurred
     * @param positionInLine The position in the line where the error occurred
     * @param message        The error message that is displayed
     */
    static std::string formatErrorMessage(int line, int positionInLine, const std::string& message) {
        std::stringstream ss;
        ss << "Error at [" << line << ", " << positionInLine << "]: " << message;
        return ss.str();
    }
};

const std::string IOFormatter::numericalOutputFormat = "0.##############";
