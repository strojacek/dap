#include <stdexcept>
#include <functional>
#include "DapParser.h" // Assuming DapParser.h contains the definition of DapParser
#include "FunctionArityException.h" // Assuming FunctionArityException.h contains the definition of FunctionArityException

using namespace std;

class FunctionSafeguard {
public:
    static void guaranteeArityIsNotViolated(const string& functionName, DapParser::FunctionCallArgsContext* context,
                                             const function<bool(int)>& guard) {
        if (!guard(context->expression().size())) {
            throw FunctionArityException(functionName + " can not be called with " + to_string(context->expression().size()) + " arguments", context);
        }
    }
};

