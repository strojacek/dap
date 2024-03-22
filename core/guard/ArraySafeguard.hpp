#include <stdexcept>
#include <vector>
#include "DapValue.hpp" // Assuming DapValue.h contains the definition of DapValue

using namespace std;

class ArraySafeguard {
public:
    static void guaranteeArrayDimensionIsValid(const DapValue& argument, ParserRuleContext* context) {
        ValueTypeSafeguard::guaranteeValueIsNumerical("Could not create array", argument, context);
        if (argument.underlyingNumber() <= 0) {
            throw ArrayDimensionUnsupportedException("Dimensions cannot be negative or zero", context);
        }
        NumericalValueSafeguard::guaranteeIsWhole("Dimensions cannot have numbers after the digit",
                argument.underlyingNumber(), context);
    }

    static void guaranteeArrayDimensionCountIsValid(const vector<DapParser::ExpressionContext*>& expressionContexts) {
        if (expressionContexts.size() > 3 || expressionContexts.empty()) {
            throw ArrayDimensionUnsupportedException(
                    "Unsupported array dimensions count " + to_string(expressionContexts.size()),
                    expressionContexts.back());
        }
    }

    static void guaranteeArrayDimensionsMatch(const DapValue& array, const vector<DapParser::ExpressionContext*>& expressionContexts) {
        switch (expressionContexts.size()) {
            case 1:
                if (!array.isAnOneDimensionalArrayValue()) {
                    throw ArrayDimensionMismatchException(
                            "The dimensions that were specified do not match the dimensions of the array",
                            expressionContexts.back());
                }
                break;
            case 2:
                if (!array.isATwoDimensionalArrayValue()) {
                    throw ArrayDimensionMismatchException(
                            "The dimensions that were specified do not match the dimensions of the array",
                            expressionContexts.back());
                }
                break;
            case 3:
                if (!array.isAThreeDimensionalArrayValue()) {
                    throw ArrayDimensionMismatchException(
                            "The dimensions that were specified do not match the dimensions of the array",
                            expressionContexts.back());
                }
                break;
            default:
                throw logic_error("Unexpected value: " + to_string(expressionContexts.size()));
        }
    }
};

