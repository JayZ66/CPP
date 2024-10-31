
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class RobotomyRequestForm : public AForm {
    private:


    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();

        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
}