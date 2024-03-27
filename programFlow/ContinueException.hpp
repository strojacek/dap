#include <stdexcept>

class ContinueException : public std::runtime_error {
public:
    ContinueException() : std::runtime_error("Forces a continue in a loop") {}
};

