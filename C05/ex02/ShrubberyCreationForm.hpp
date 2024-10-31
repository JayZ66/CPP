
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class ShrubberyCreationForm : public AForm {
    private:


    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
}