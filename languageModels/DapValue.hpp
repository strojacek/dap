#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>

class ParserRuleContext {};

class JazzValue {
public:
    static const JazzValue FalseValue;
    static const JazzValue TrueValue;
    static const JazzValue NullValue;

private:
    using BiFunction = std::function<double(double, double)>;

    // Underlying value
    using Value = std::variant<double, std::string, std::vector<JazzValue>>;
    Value value;

public:
    JazzValue(const std::string& value) : value(value) {}
    JazzValue(double value) : value(value) {}
    JazzValue(const std::vector<JazzValue>& values) : value(values) {}

    JazzValue add(const JazzValue& right, const ParserRuleContext& context) {
        if (std::holds_alternative<std::string>(value) && std::holds_alternative<std::string>(right.value)) {
            return JazzValue(std::get<std::string>(value) + std::get<std::string>(right.value));
        } else if (std::holds_alternative<std::string>(value) && std::holds_alternative<double>(right.value)) {
            return JazzValue(std::get<std::string>(value) + std::to_string(std::get<double>(right.value)));
        } else if (std::holds_alternative<double>(value) && std::holds_alternative<std::string>(right.value)) {
            return JazzValue(std::to_string(std::get<double>(value)) + std::get<std::string>(right.value));
        } else {
            return arithmeticEvaluation(right, [](double a, double b) { return a + b; }, context);
        }
    }

    JazzValue and(const JazzValue& right, const ParserRuleContext& context) {
        return isTruthy(context) && right.isTruthy(context) ? TrueValue : FalseValue;
    }

    JazzValue divide(const JazzValue& right, const ParserRuleContext& context) {
        return arithmeticEvaluation(right, [](double a, double b) { return a / b; }, context);
    }

    JazzValue equal(const JazzValue& right, const ParserRuleContext& context) {
        if (std::holds_alternative<double>(value) && std::holds_alternative<double>(right.value)) {
            return compare(right, [](double a, double b) { return a == b; }, context);
        } else if (std::holds_alternative<std::string>(value) && std::holds_alternative<std::string>(right.value)) {
            return std::get<std::string>(value) == std::get<std::string>(right.value) ? TrueValue : FalseValue;
        } else if (std::holds_alternative<std::vector<JazzValue>>(value) && std::holds_alternative<std::vector<JazzValue>>(right.value)) {
            return std::get<std::vector<JazzValue>>(value) == std::get<std::vector<JazzValue>>(right.value) ? TrueValue : FalseValue;
        } else {
            return FalseValue;
        }
    }

    JazzValue greaterThen(const JazzValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a > b; }, context);
    }

    JazzValue greaterThenEqual(const JazzValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a >= b; }, context);
    }

    JazzValue lessThen(const JazzValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a < b; }, context);
    }

    JazzValue lessThenEqual(const JazzValue& right, const ParserRuleContext& context) {
        return compare(right, [](double a, double b) { return a <= b; }, context);
    }

    JazzValue modulo(const JazzValue& right, const ParserRuleContext& context) {
        return arithmeticEvaluation(right, [](double a, double b) { return std::fmod(a, b); }, context);
    }

    JazzValue multiply(const JazzValue& right, const ParserRuleContext& context) {
        return arithmeticEvaluation(right, [](double a, double b) { return a * b; }, context);
    }

    JazzValue negate(const ParserRuleContext& context) {
        return arithmeticEvaluation(TrueValue, [](double a, double) { return -a; }, context);
    }

    JazzValue notEqual(const JazzValue& right, const ParserRuleContext& context) {
        return equal(right, context).value == TrueValue.value ? FalseValue : TrueValue;
    }

    JazzValue or(const JazzValue& right, const ParserRuleContext& context) {
        return isTruthy(context) || right.isTruthy(context) ? TrueValue : FalseValue;
    }

	 void printValue(std::ostream& printStream, bool aligned) {
        if (std::holds_alternative<double>(value)) {
            printStream << std::get<double>(value);
        } else if (std::holds_alternative<std::string>(value)) {
            printStream << std::get<std::string>(value);
        } else if (std::holds_alternative<std::vector<JazzValue>>(value)) {
            printStream << "{ ";
            const auto& array = std::get<std::vector<JazzValue>>(value);
            for (size_t i = 0; i < array.size(); ++i) {
                array[i].printValue(printStream, false);
                if (i < array.size() - 1) {
                    printStream << ", ";
                }
            }
            printStream << " }";
        }
    }

    JazzValue subtract(const JazzValue& right, const ParserRuleContext& context) {
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
    JazzValue arithmeticEvaluation(const JazzValue& right, BiFunction func, const ParserRuleContext& context) {
        double leftValue = underlyingNumber();
        double rightValue = right.underlyingNumber();
        return JazzValue(std::invoke(func, leftValue, rightValue));
    }

    JazzValue compare(const JazzValue& right, BiFunction func, const ParserRuleContext& context) {
        double leftValue = underlyingNumber();
        double rightValue = right.underlyingNumber();
        return std::invoke(func, leftValue, rightValue) ? TrueValue : FalseValue;
    }
};

const JazzValue JazzValue::FalseValue = JazzValue(0.0);
const JazzValue JazzValue::TrueValue = JazzValue(1.0);
const JazzValue JazzValue::NullValue = JazzValue(std::vector<JazzValue>());

class SASParser {};

class ParserRuleContext {};
