
#pragma once

#include <iostream>
#include <string>

class ScalarConverter { // Check why it must be a single ton ?? 
    private:

    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    ~ScalarConverter();

    ScalarConverter& operator=(ScalarConverter& other);

    public:

    static void    convert(const std::string& literal);
};

// class ScalarConverter {
//     private:


//     public:
//     ScalarConverter();
//     ScalarConverter(ScalarConverter& other);
//     ~ScalarConverter();

//     ScalarConverter& operator=(ScalarConverter& other);

//     static void    convert(const std::string& literal);
// };