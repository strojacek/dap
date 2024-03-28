#include <vector>
#include "parser/SASParser.h" // Assuming you have defined SASParser

class DapSubroutine {
private:
    std::vector<std::string> arguments;
    std::vector<SASParser::ParseContext*> statementsInBodyContexts;

public:
    DapSubroutine(const std::vector<std::string>& arguments, const std::vector<SASParser::ParseContext*>& statementsInBodyContexts)
        : arguments(arguments), statementsInBodyContexts(statementsInBodyContexts) {}

    const std::vector<std::string>& getArguments() const {
        return arguments;
    }

    const std::vector<SASParser::ParseContext*>& getSubroutineBody() const {
        return statementsInBodyContexts;
    }

    int getArity() const {
        return arguments.size();
    }
};

