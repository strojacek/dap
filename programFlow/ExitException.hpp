#include <stdexcept>

class ExitException : public std::runtime_error {
public:
    ExitException() : std::runtime_error("Forces exit from loop") {}
};

