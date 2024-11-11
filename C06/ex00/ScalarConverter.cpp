
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
        charValue = static_cast<char>(doubleValue);
        if (std::isprint(charValue)) {
            std::cout << "'" << charValue << "'" << std::endl;
        }
        else
            std::cerr << "not a printable character." << std::endl;
    }

    //Convert to int
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
        std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;

    //Convert to double
    std::cout << "double: ";
    if (std::isinf(doubleValue) || std::isnan(doubleValue))
        std::cout << doubleValue << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;

}

/*
std::fixed et std::setprecision => Cela permet d'éviter l'ajout de .0 dans les affichages de float et double lorsqu'il n'y a 
pas de décimales ou d'obtenir des valeurs correctement formatées.

- std::fixed : Permet d’afficher les nombres à virgule flottante avec un nombre de décimales constant.
on force l'affichage en notation décimale fixe (exemple : 123456.0 au lieu de 1.23456e+05)
- std::setprecision(1) : Fixe le nombre de chiffres après la virgule. Ici, 1 est utilisé pour obtenir un seul chiffre après 
la virgule (comme .0), mais vous pouvez l’adapter selon vos besoins.
std::setprecision(n) détermine le nombre total de chiffres significatifs affichés (à droite et à gauche de la virgule) si 
std::fixed n’est pas utilisé.
*/
