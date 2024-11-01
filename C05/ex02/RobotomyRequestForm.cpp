
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("Default") {}
        
RobotomyRequestForm::RobotomyRequestForm(std::string ptarget) : AForm("RobotomyRequestForm", 72, 45), _target(ptarget) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other.getTarget();
    }
    return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const;

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}