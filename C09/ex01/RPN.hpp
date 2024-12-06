
#pragma once

#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <sstream>
#include <limits>
#include <limits.h>
#include <time.h>
#include <ctime>
#include <cstdlib>


class RPN {
    private:
        std::stack<int> _stack;

    public:

    RPN();
    RPN(const RPN& other);
    ~RPN();

    RPN& operator=(const RPN& other);

    void    checkRpnExpression(const std::string& expression) const;
    void    calculateExpression(const std::string& op);
    int   prepareResult(const std::string& expression);

    bool    isBeforeTen(const char& digit) const;
    // bool    isAnOperator(const std::string& operatoor) const;
    bool    isAnOperator(const char op) const;

    class ExpressionException : public std::exception {
        private:
            std::string _message;

        public:
            ExpressionException(const std::string& message) : _message(message) {}
            virtual ~ExpressionException() throw() {}
            virtual const char* what() const throw() {
                return _message.c_str();
            } 
    };
};