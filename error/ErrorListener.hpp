#include <iostream>
#include <string>

class ErrorListener {
private:
    // The standard error output stream
    std::ostream& stderr;

public:
    ErrorListener(std::ostream& stderr) : stderr(stderr) {}

    void syntaxError(const std::string& offendingSymbol,
                     int line,
                     int characterPositionInLine,
                     const std::string& message,
                     const std::exception& exception = nullptr) {
        this->stderr << "Error at [" << line << ", " << characterPositionInLine << "]: " << message << std::endl;
    }
};

