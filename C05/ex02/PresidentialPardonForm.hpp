
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class PresidentialPardonForm : public AForm {
    private:


    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();

        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
}