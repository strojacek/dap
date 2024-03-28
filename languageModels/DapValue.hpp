#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>

class ParserRuleContext {};

class DapValue {
public:
    static const DapValue FalseValue;
    static const DapValue TrueValue;
    static const DapValue NullValue;

private:
    using BiFunction = std::function<double(double, double)>;

    // Underlying value
    using Value = std::variant<double, std::string, std::vector<DapValue>>;
    Value value;

public:
    DapValue(const std::string& value) : value(value) {}
    DapValue(double value) : value(value) {}
    DapValue(const std::vector<DapValue>& values) : value(values) {}

    DapValue add(const DapValue& right, const ParserRuleContext& context) {
        if (std::holds_alternative<std::string>(value) && std::holds_alternative<std::string>(right.value)) {
            return DapValue(std::get<std::string>(value) + std::get<std::string>(right.value));
        } else if (std::holds_alternative<std::string>(value) && std::holds_alternative<double>(right.value)) {
            return DapValue(std::get<std::string>(value) + std::to_string(std::get<double>(right.value)));
        } else if (std::holds_alternative<double>(value) && std::holds_alternative<std::string>(right.value)) {
            return DapValue(std::to_string(std::get<double>(value)) + std::get<std::string>(right.value));
        } else {
            return arithmeticEvaluation(right, [](double a, double b) { return a + b; }, context);
        }
    }

    DapValue and(const DapValue& right, const ParserRuleContext& context) {
        return isTruthy(context) && right.isTruthy(context) ? TrueValue : FalseValue;
    }

    DapValue divide(const DapValue& right, const ParserRuleContext& context) {
        return arithmeticEvaluation(right, [](double a, double b) { return a / b; }, context);
    }

    DapValue equal(const DapValue& right, const ParserRuleContext& context) {
        if (std::holds_alternative<double>(value) && std::holds_alternative<double>(right.value)) {
            return compare(right, [](double a, double b) { return a == b; }, context);
        } else if (std::holds_alternative<std::string>(value) && std::holds_alternative<std::string>(right.value)) {
            return std::get<std::string>(value) == std::get<std::string>(right.value) ? TrueValue : FalseValue;
        } else if (std::holds_alternative<std::vector<DapValue>>(value) && std::holds_alternative<std::vector<DapValue>>(right.value)) {
            return std::get<std::vector<DapValue>>(value) == std::get<std::vector<DapValue>>(right.value) ? TrueValue : FalseValue;
        } else {
            return FalseValue;
        }
    }

    DapValue greaterThen(const DapValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a > b; }, context);
    }

    DapValue greaterThenEqual(const DapValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a >= b; }, context);
    }

    DapValue lessThen(const DapValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a < b; }, context);
    }

    DapValue lessThenEqual(const DapValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a <= b; }, context);
    }

    DapValue modulo(const DapValue& right, const ParserRuleContext& context) {
        return arithmeticEvaluation(right, [](double a, double b) { return std::fmod(a, b); }, context);
    }

    DapValue multiply(const DapValue& right, const ParserRuleContext& context) {
        return arithmeticEvaluation(right, [](double a, double b) { return a * b; }, context);
    }

    DapValue negate(const ParserRuleContext& context) {
        return arithmeticEvaluation(TrueValue, [](double a, double) { return -a; }, context);
    }

    DapValue notEqual(const DapValue& right, const ParserRuleContext& context) {
        return equal(right, context).value == TrueValue.value ? FalseValue : TrueValue;
    }

    DapValue or(const DapValue& right, const ParserRuleContext& context) {
        return isTruthy(context) || right.isTruthy(context) ? TrueValue : FalseValue;
    }

	 void printValue(std::ostream& printStream, bool aligned) {
        if (std::holds_alternative<double>(value)) {
            printStream << std::get<double>(value);
        } else if (std::holds_alternative<std::string>(value)) {
            printStream << std::get<std::string>(value);
        } else if (std::holds_alternative<std::vector<DapValue>>(value)) {
            printStream << "{ ";
            const auto& array = std::get<std::vector<DapValue>>(value);
            for (size_t i = 0; i < array.size(); ++i) {
                array[i].printValue(printStream, false);
                if (i < array.size() - 1) {
                    printStream << ", ";
                }
            }
            printStream << " }";
        }
    }

    DapValue subtract(const DapValue& right, const ParserRuleContext& context) {
        return arithmeticEvaluation(right, [](double a, double b) { return a - b; }, context);
    }

    double underlyingNumber() const {
        return std::holds_alternative<double>(value) ? std::get<double>(value) : 0.0;
    }

    std::string underlyingString() const {
        return std::holds_alternative<std::string>(value) ? std::get<std::string>(value) : "";
    }

    bool isTruthy(const ParserRuleContext& context) const {
        return underlyingNumber() != 0.0;
    }

    bool isFalsy(const ParserRuleContext& context) const {
        return underlyingNumber() == 0.0;
    }

private:
    DapValue arithmeticEvaluation(const DapValue& right, BiFunction func, const ParserRuleContext& context) {
        double leftValue = underlyingNumber();
        double rightValue = right.underlyingNumber();
        return DapValue(std::invoke(func, leftValue, rightValue));
    }

    DapValue compare(const DapValue& right, BiFunction func, const ParserRuleContext& context) {
        double leftValue = underlyingNumber();
        double rightValue = right.underlyingNumber();
        return std::invoke(func, leftValue, rightValue) ? TrueValue : FalseValue;
    }
};

const DapValue DapValue::FalseValue = DapValue(0.0);
const DapValue DapValue::TrueValue = DapValue(1.0);
const DapValue DapValue::NullValue = DapValue(std::vector<DapValue>());

class SASParser {};

class ParserRuleContext {};
