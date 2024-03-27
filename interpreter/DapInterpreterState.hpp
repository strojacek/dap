#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
#include <stack>
#include "JazzValue.h" // Assuming you have defined JazzValue
#include "UndefinedLabelException.h" // Assuming you have defined UndefinedLabelException
#include "Sas_stmt_blockContext.h" // Assuming you have defined Sas_stmt_blockContext
#include "Visitor.h" // Assuming you have defined Visitor

class JazzInterpreterState {
private:
    std::unordered_map<std::string, JazzValue> memory;
    std::unordered_map<std::string, JazzSubroutine> subroutines;
    std::unordered_map<std::string, Sas_stmt_blockContext> labeledBlock;
    std::string currentScript;
    std::deque<JazzValue> dataSegment;
    std::stack<JazzValue> poppedDataList;

public:
    std::deque<JazzValue>& getDataSegment() {
        return dataSegment;
    }

    void addLabel(const std::string& labelName, const Sas_stmt_blockContext& blockContext) {
        labeledBlock[labelName] = blockContext;
    }

    JazzValue gotoLabel(const std::string& labelName, Visitor& visitor, ParserRuleContext& context) {
        auto it = labeledBlock.find(labelName);
        if (it != labeledBlock.end()) {
            return visitor.visit(it->second);
        } else {
            throw UndefinedLabelException("A label called " + labelName + " is not defined", context);
        }
    }
};

