#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
#include <stack>
#include "languageModels/DapValue.hpp" // Assuming you have defined DapValue
#include "UndefinedLabelException.h" // Assuming you have defined UndefinedLabelException
#include "Sas_stmt_blockContext.h" // Assuming you have defined Sas_stmt_blockContext
#include "Visitor.h" // Assuming you have defined Visitor

class DapInterpreterState {
private:
    std::unordered_map<std::string, DapValue> memory;
    std::unordered_map<std::string, DapSubroutine> subroutines;
    std::unordered_map<std::string, Sas_stmt_blockContext> labeledBlock;
    std::string currentScript;
    std::deque<DapValue> dataSegment;
    std::stack<DapValue> poppedDataList;

public:
    std::deque<DapValue>& getDataSegment() {
        return dataSegment;
    }

    void addLabel(const std::string& labelName, const Sas_stmt_blockContext& blockContext) {
        labeledBlock[labelName] = blockContext;
    }

    DapValue gotoLabel(const std::string& labelName, Visitor& visitor, ParserRuleContext& context) {
        auto it = labeledBlock.find(labelName);
        if (it != labeledBlock.end()) {
            return visitor.visit(it->second);
        } else {
            throw UndefinedLabelException("A label called " + labelName + " is not defined", context);
        }
    }
};

