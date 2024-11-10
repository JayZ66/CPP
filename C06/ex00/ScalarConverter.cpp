
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
    double  doubleValue;
    char    charValue = 0;
    int     integerValue = 0;
    float   floatValue = 0.0;

    if (literal.empty()) {
        std::cerr << "Error: literal string is empty !" << std::endl;
        return;
    }
    // Check if littéral est un char unique
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        doubleValue = static_cast<double>(literal[0]);
    }
    // Check if littéral est de type char entre simple quote
    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        doubleValue = static_cast<double>(literal[1]);
    else { // so literal is a nb
        char *endPtr = NULL;
        doubleValue = std::strtod(literal.c_str(), &endPtr);
        if (*endPtr != '\0' && !((*endPtr == 'f' || *endPtr == 'F') && *(endPtr + 1) == '\0')) {
            std::cerr << "Error: Invalid input format !" << std::endl;
            return;
        }
    }

    //Convert to char
    std::cout << "char: ";
    if (doubleValue < std::numeric_limits<char>::min() || doubleValue > std::numeric_limits<char>::max() || std::isnan(doubleValue)) {
        std::cout << "conversion is impossible: out of range or NaN." << std::endl;
    }
    else {
        charValue = static_cast< char>(doubleValue);
        if (std::isprint(charValue)) {
            std::cout << "'" << charValue << "'" << std::endl;
        }
        else
            std::cerr << "not a printable character." << std::endl;
    }

    //convert to int
    std::cout << "int: ";
    if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max() || std::isnan(doubleValue))
        std::cout << "conversion is impossible: out of range or NaN." << std::endl;
    else {
        integerValue = static_cast<int>(doubleValue);
        std::cout << integerValue << std::endl;
    }

    //Convert to float
    std::cout << "float: ";
    floatValue = static_cast<float>(doubleValue);
    if (std::isinf(doubleValue) || std::isnan(doubleValue))
        std::cout << floatValue << "f" << std::endl;
    else
        std::cout << floatValue << ".0f" << std::endl;

    //Convert to double
    std::cout << "double: ";
    if (std::isinf(doubleValue) || std::isnan(doubleValue))
        std::cout << doubleValue << std::endl;
    else
        std::cout << doubleValue << ".0" << std::endl;

}


// static void    ScalarConverter::convert(const std::string& literal) {
    
//     int integerValue;
//     double  doubleValue;
//     float   floatValue;
//     char    charValue;
//     size_t  index = 0;
//     // Check si la string literal est vide !

//     if (literal.empty()) {
//         std::cerr << "Literal string is empty, can't convert void string !" << std::endl;
//         return;
//     }

//     if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {

//         charValue = literal[1];
//         if (!isprint(charValue)) {
//             std::cout << "This is not a printable character !" << std::endl;
//             return; // Check if we return or do something.
//         }
//         else {
//             integerValue = static_cast<int>(charValue);
//             std::cout << "int: " << integerValue << std::endl;

//             floatValue = static_cast<float>(charValue);
//             std::cout << "float: " << floatValue << std::endl;

//             doubleValue = static_cast<double>(charValue);
//             std::cout << "double: " << doubleValue;
//         }
//     }
//     else {
//         char *endPtr;
//         doubleValue = strtod(literal.c_str(), &endPtr); // transformer une string, représentant textuellement un nb floattant en double.
//         if ((*endPtr == 'f' || *endPtr == 'F') && *(endPtr + 1) == '\0') { // Check si float
//             floatValue = static_cast<float>(doubleValue);
//             std::cout << "float: " << floatValue << "f" << std::endl;

//             if (doubleValue >= std::numeric_limits<int>::min() && doubleValue <= std::numeric_limits<int>::max()) {
//                 integerValue = static_cast<int>(doubleValue);
//                 std::cout << "int: " << integerValue << std::endl;
//             }
//             else
//                 std::cerr << "int: literal is out of range !" << std::endl;
            
//             // Maybe add a check for the integer value, if the literal is out of range !
//             charValue = static_cast<char>(integerValue);
//             if (isprint(charValue))
//                 std::cout << "char: " << charValue << std::endl;
//             else
//                 std::cerr << "This is not a printable character !" << std::endl;

//             std::cout << "double: " << doubleValue << std::endl;
//         }
//         else if (*endPtr == '\0') { // Check si le littéral a bien été converted.
//             if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max()) {  // Check if we check min/max for double !!
//                 std::cout << "int: literal is out of range !" << std::endl;
//                 return;
//             }
//             else {
//                 integerValue = static_cast<int>(doubleValue);
//                 std::cout << "int: " << integerValue << std::endl;

//                 charValue = static_cast<char>(integerValue);
//                 if (isprint(charValue))
//                     std::cout << "char: " << charValue;
//                 else
//                     std::cerr << "This is not a printable character !" << std::endl;

//                 floatValue = static_cast<float>(integerValue);
//                 std::cout << "float: " << floatValue << std::endl;

//                 doubleValue = static_cast<double>(integerValue);
//                 std::cout << "double: " << doubleValue << std::endl;
//             }
//         }
//         else {
//             std::cerr << "This is not an integer or a char value !" << std::endl;
//         }
//     }
// }