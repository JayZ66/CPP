
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string ptarget); // Target : nom du fichier à créer et à remplir avec un arbre ASCII
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        void	execute(const Bureaucrat& executor) const;

        std::string getTarget() const;
};