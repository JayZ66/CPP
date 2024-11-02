
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string ptarget);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        void	execute(const Bureaucrat& executor) const;

        std::string getTarget() const;
};