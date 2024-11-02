
#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

class Intern {
    private:

    public:
    Intern();
    Intern(const Intern& other);
    ~Intern();

    Intern& operator=(const Intern& other);

    AForm*  ShrubberyCreation(const std::string& target);
    AForm*  RobotomyRequestCreation(const std::string& target);
    AForm*  PresidentialPardonCreation(const std::string& target);

    AForm*    makeForm(const std:string& formName, const std::string& target);
};