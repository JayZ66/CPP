
#include "ScalarConverter.hpp"

static void    ScalarConverter::convert(const std::string& literal) {
    
    std::string type;
    size_t  index = 0;
    // Check si la string literal est vide !

    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {

        char character = literal[1];
        if (character < 32 || character > 126)
            std::cout << "This is not a printable character !" << std::endl;
    }
    if (literal[0] == '+' || literal[0] == '-')
        index = 1;
    for (int i = index; i < literal.length() - 1; i++) {
        if (!std::isdigit(literal[i]))
            return ;
        // If it's a digit convert it to an int.
    }
}