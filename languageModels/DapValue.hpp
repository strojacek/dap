#include <iostream>
#include <vector>
#include <functional>
#include <sstream>
#include <iomanip>
#include <algorithm>

class DapValue {
public:
    static const DapValue FalseValue;
    static const DapValue TrueValue;
    static const DapValue NullValue;

    DapValue(std::string value) : value(value) {}
    DapValue(double value) : value(value) {}
    DapValue(std::nullptr_t) : value(nullptr) {}
    DapValue(std::vector<DapValue> values) : value(values) {}
    DapValue(std::vector<std::vector<DapValue>> values) : value(values) {}
    DapValue(std::vector<std::vector<std::vector<DapValue>>> values) : value(values) {}

    DapValue add(const DapValue& right);
    DapValue andOp(const DapValue& right);
    DapValue divide(const DapValue& right);
    DapValue equal(const DapValue& right);
    DapValue greaterThen(const DapValue& right);
    DapValue greaterThenEqual(const DapValue& right);
    bool equals(const DapValue& other) const;
    int hashCode() const;
    bool isAStringValue() const { return std::holds_alternative<std::string>(value); }
    bool isANumericalValue() const { return std::holds_alternative<double>(value); }
    bool isAnArrayValue() const { return isAnOneDimensionalArrayValue() || isATwoDimensionalArrayValue() || isAThreeDimensionalArrayValue(); }
    bool isAnOneDimensionalArrayValue() const { return std::holds_alternative<std::vector<DapValue>>(value); }
    bool isATwoDimensionalArrayValue() const { return std::holds_alternative<std::vector<std::vector<DapValue>>>(value); }
    bool isAThreeDimensionalArrayValue() const { return std::holds_alternative<std::vector<std::vector<std::vector<DapValue>>>>(value); }
    bool isFalsy() const { return isANumericalValue() && underlyingNumber() == 0; }
    bool isNotANumericalValue() const { return !isANumericalValue(); }
    bool isTruthy() const { return isANumericalValue() && underlyingNumber() != 0; }
    DapValue lessThen(const DapValue& right);
    DapValue lessThenEqual(const DapValue& right);
    DapValue modulo(const DapValue& right);
    DapValue multiply(const DapValue& right);
    DapValue notEqual(const DapValue& right);
    DapValue negate();
    DapValue notOp();
    DapValue orOp(const DapValue& right);
    void printValue(std::ostream& outputStream, bool aligned) const;
    DapValue subtract(const DapValue& right);
    double underlyingNumber() const { return std::get<double>(value); }
    std::string underlyingString() const { return std::get<std::string>(value); }
    std::vector<DapValue> underlyingOneDimensionalArray() const { return std::get<std::vector<DapValue>>(value); }
    std::vector<std::vector<DapValue>> underlyingTwoDimensionalArray() const { return std::get<std::vector<std::vector<DapValue>>>(value); }
    std::vector<std::vector<std::vector<DapValue>>> underlyingThreeDimensionalArray() const { return std::get<std::vector<std::vector<std::vector<DapValue>>>>(value); }

private:
    using BiFunction = std::function<double(double, double)>;

    template<typename T>
    DapValue arithmeticEvaluation(const DapValue& right, BiFunction op) const;

    template<typename Comparator>
    DapValue compare(const DapValue& right, Comparator comparison) const;

    std::variant<std::nullptr_t, double, std::string, std::vector<DapValue>, std::vector<std::vector<DapValue>>, std::vector<std::vector<std::vector<DapValue>>>> value;
};

const DapValue DapValue::FalseValue = DapValue(0);
const DapValue DapValue::TrueValue = DapValue(1);
const DapValue DapValue::NullValue = DapValue(nullptr);

DapValue DapValue::add(const DapValue& right) {
    if (isAStringValue() && right.isAStringValue()) {
        return DapValue(underlyingString() + right.underlyingString());
    } else if (isAStringValue() && right.isANumericalValue()) {
        return DapValue(underlyingString() + std::to_string(right.underlyingNumber()));
    } else if (isANumericalValue() && right.isAStringValue()) {
        return DapValue(std::to_string(underlyingNumber()) + right.underlyingString());
    } else {
        return arithmeticEvaluation(right, [](double l, double r) { return l + r; });
    }
}

DapValue DapValue::andOp(const DapValue& right) {
    return isTruthy() && right.isTruthy() ? TrueValue : FalseValue;
}

DapValue DapValue::divide(const DapValue& right) {
    return arithmeticEvaluation(right, [](double l, double r) { return l / r; });
}

DapValue DapValue::equal(const DapValue& right) {
    if (isANumericalValue() && right.isANumericalValue()) {
        return compare(right, [](double l, double r) { return l == r; });
    } else if (isAStringValue() && right.isAStringValue()) {
        return underlyingString() == right.underlyingString() ? TrueValue : FalseValue;
    } else if (isAnOneDimensionalArrayValue() && right.isAnOneDimensionalArrayValue()) {
        return underlyingOneDimensionalArray() == right.underlyingOneDimensionalArray() ? TrueValue : FalseValue;
    } else if (isATwoDimensionalArrayValue() && right.isATwoDimensionalArrayValue()) {
        return underlyingTwoDimensionalArray() == right.underlyingTwoDimensionalArray() ? TrueValue : FalseValue;
    } else if (isAThreeDimensionalArrayValue() && right.isAThreeDimensionalArrayValue()) {
        return underlyingThreeDimensionalArray() == right.underlyingThreeDimensionalArray() ? TrueValue : FalseValue;
    }
    return FalseValue;
}

DapValue DapValue::greaterThen(const DapValue& right) {
    return compare(right, [](double l, double r) { return l > r; });
}

DapValue DapValue::greaterThenEqual(const DapValue& right) {
    return compare(right, [](double l, double r) { return l >= r; });
}

bool DapValue::equals(const DapValue& other) const {
    if (this == &other) {
        return true;
    }
    if (value.index() != other.value.index()) {
        return false;
    }
    return value == other.value;
}


