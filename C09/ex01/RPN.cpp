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

bool    RPN::isAnOperator(const char op) const {
    return (op == '-' || op == '+' || op == '*' || op == '/');
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
        
        if (!isBeforeTen(expression[i]))
            throw ExpressionException("Error: digit is not contained into [0, 9]");
    }
}

void    RPN::calculateExpression(const std::string& op) {

    // std::istringstream  line(expression);
    // std::string token;

    if (_stack.size() < 2) {
        throw ExpressionException("Error - Minimum two digits needed to calculate");
    }
    int lastDigit = _stack.top();
     _stack.pop();
    int firstDigit = _stack.top();
    _stack.pop();

    // int result = 0;
    if (op == "+") {
        // result = firstDigit + lastDigit;
        _stack.push(firstDigit + lastDigit);
    }
    else if (op == "-") {
        // result = firstDigit - lastDigit;
        _stack.push(firstDigit - lastDigit);
    }
    else if (op == "*") {
        // result = firstDigit * lastDigit;
        _stack.push(firstDigit * lastDigit);
    }
    else if (op == "/") {
        if (lastDigit == 0)
            throw ExpressionException("Error: cannot divide by 0");
        // result = firstDigit / lastDigit;
        _stack.push(firstDigit / lastDigit);
    }
    else
         throw ExpressionException("Error: token is not an operator or digit");
}

int    RPN::prepareResult(const std::string& expression) {

    std::istringstream  line(expression);
    std::string         token;

    // If i wanted to read char by char, could have used : while (line.get(token)) as line >> token extract each thing btwn space
    while (line >> token) { // Token represents each part of the expression (even if its a str)
        if (token.size() == 1 && isAnOperator(token[0])) {
            calculateExpression(token);
        }
        else {
            char*   endPtr;
            long    digit = std::strtol(token.c_str(), &endPtr, 10);
            if (*endPtr == '\0') { // Check if conversion worked for the whole str (went until \0)
                if (digit < INT_MIN || digit > INT_MAX)
                    throw ExpressionException("Error: digit is out of range");
                _stack.push(static_cast<int>(digit));
            }
            else
                throw ExpressionException("Error: digit conversion failed");

        }
    }
    if (_stack.size() != 1)
        throw ExpressionException("Error: there is not just result in the stack");
    return _stack.top();
}

/*
Différences entre >> et get :

>> :
    - Lit des mots ou tokens séparés par des espaces dans 
    un std::string.
    - Ne peut pas être utilisé directement avec un char.

get :
    - Lit un caractère unique directement dans un char.
    - Utile si tu veux analyser l'entrée caractère par caractère.
*/