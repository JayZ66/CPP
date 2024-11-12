
#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cctype>
#include <iomanip>

class ScalarConverter { // Check why it must be a single ton ?? 
    private:

        ScalarConverter();
        ScalarConverter(ScalarConverter& other);
        ~ScalarConverter();

        ScalarConverter& operator=(ScalarConverter& other);

    public:

        static void    convert(const std::string& literal);
};
