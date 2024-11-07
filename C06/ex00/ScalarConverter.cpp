
#include "ScalarConverter.hpp"

static void    ScalarConverter::convert(const std::string& literal) {
    
    std::string type;
    int integerValue;
    double  doubleValue;
    float   floatValue;
    char    charValue;
    size_t  index = 0;
    // Check si la string literal est vide !

    if (literal.empty()) {
        std::cerr << "Literal string is empty, can't convert void string !" << std::endl;
        return;
    }

    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {

        charValue = literal[1];
        if (!isprint(charValue) {
            std::cout << "This is not a printable character !" << std::endl;
            return; // Check if we return or do something.
        }
        else {
            integerValue = static_cast<int>(charValue);
            std::cout << "int: " << integerValue << std::endl;

            floatValue = static_cast<float>(charValue);
            std::cout << "float: " << floatValue << std::endl;

            doubleValue = static_cast<double>(charValue);
            std::cout << "double: " << doubleValue;
        }
    }

    if (literal[0] == '+' || literal[0] == '-')
        index = 1;
    for (int i = index; i < literal.length() - 1; i++) {
        if (!std::isdigit(literal[i]))
            return ;
        // If it's a digit convert it to an int.
    }
    double  doubleValue = strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0') {
        if (doubleValue < < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max()) {  // Check if we check min/max for double !!
            std::cout << "int: impossible" << std::endl;
            return;
        }
    }
    // long long int value = std::strtol(literal.c_str(), nullptr, 10);
    //     if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
    //         std::cout << "int: impossible" << std::endl;
    //         return;
    //     }
    //     int intValue = static_cast<int>(value);
}