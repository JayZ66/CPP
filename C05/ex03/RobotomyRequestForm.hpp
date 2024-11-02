
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdlib.h>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm {
    private:
        std::string _target; // personne ou l’objet que l’on tente de « robotomiser »

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string ptarget);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        void	execute(const Bureaucrat& executor) const;

        std::string getTarget() const;
};