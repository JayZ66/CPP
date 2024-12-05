#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN::~RPN() {}

RPN&    RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

bool    RPN::isBeforeTen(const char& digit) const {
    if (digit < '0' || digit > '9')
        return false;
    return true;
}

bool    RPN::isAnOperator(const std::string& operatoor) const {
    return (operatoor == "-" || operatoor == "+" || operatoor == "*" || operatoor == "/");
}

void    RPN::checkRpnExpression(const std::string& expression) const {

    // Check if start by an operator & finish by a digit
    if (isAnOperator(expression[0]))
        throw ExpressionException("Error: Expression is starting by an operator");
    else if (std::isdigit(expression[expression.size() - 1]))
        throw ExpressionException("Error: Expression is finishing by a digit");

    for (size_t i = 0; i < expression.size(); i++) {

        if (std::isspace(expression[i]))
            continue;
        if (!isAnOperator(expression[i]) && !std::isdigit(expression[i]))
            throw ExpressionException("Error: Bad character in the expression");
        
        if (std::isdigit(expression[i]) && !isBeforeTen(expression[i]))
            throw ExpressionException("Error: digit is not contained into [0, 9]");
    }
}

void    RPN::calculateExpression(const std::string& expression) {

    std::istringstream  line(expression);
    std::string token;

    if (_stack.size() < 2) {
        throw ExpressionException("Error - Minimum two digits needed to calculate");
    }
    int lastDigit = _stack.top();
     _stack.pop();
    int firstDigit = _stack.top();
    _stack.pop();

    int result = 0;
    if (token == "+") {
        result = firstDigit + lastDigit;
        _stack.push(result);
    }
    else if (token == "-") {
        result = firstDigit - lastDigit;
        _stack.push(result);
    }
    else if (token == "*") {
        result = firstDigit * lastDigit;
        _stack.push(result);
    }
    else if (token == "/") {
        if (lastDigit == 0)
            throw ExpressionException("Error: cannot divide by 0");
        result = firstDigit / lastDigit;
        _stack.push(result);
    }
    else
         throw ExpressionException("Error: token is not an operator or digit");
    // }
}

int    RPN::prepareResult(const std::string& expression) {

    std::istringstream  line(expression);
    std::string         token;

    while (line >> token) {
        if (isAnOperator(token)) {
            calculateExpression(token);
        }
        else {
            char*   endPtr;
            long    digit = std::strtol(token.c_str(), &endPtr, 10);
            if (*endPtr == '\0') {
                if (digit < INT_MIN || digit > INT_MAX)
                    throw ExpressionException("Error: digit is out of range");
                _stack.push(static_cast<int>(digit));
            }
            else

        }
    }
    if (_stack.size() != 1)
        throw ExpressionException("Error: there is not just result in the stack");
    return _stack.top();
}