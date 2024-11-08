
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
        if (!isprint(charValue)) {
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
    else {
        char *endPtr;
        doubleValue = strtod(literal.c_str(), &endPtr); // transformer une string, représentant textuellement un nb floattant en double.
        if (*endPtr == 'f' && *(endPtr + 1) == '\0') // Check si float
        else if (*endPtr == '\0') { // Check si le littéral a bien été converted.
            if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max()) {  // Check if we check min/max for double !!
                std::cout << "int: literal is out of range !" << std::endl;
                return;
            }
            else {
                integerValue = static_cast<int>(doubleValue);
                std::cout << "int: " << integerValue << std::endl;

                charValue = static_cast<char>(integerValue);
                if (isprint(charValue))
                    std::cout << "char: " << charValue;
                else
                    std::cerr << "This is not a printable character !" << std::endl;

                floatValue = static_cast<float>(integerValue);
                std::cout << "float: " << floatValue << std::endl;

                doubleValue = static_cast<double>(integerValue);
                std::cout << "double: " << doubleValue << std::endl;
            }
        }
        else {
            std::cerr << "This is not an integer or a char value !" << std::endl;
        }
    }
}