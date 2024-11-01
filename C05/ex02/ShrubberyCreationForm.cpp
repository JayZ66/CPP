
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string ptarget) : AForm("ShrubberyCreationForm", 145, 137), _target(ptarget) {}
// "ShrubberyCreationForm" : name that we gave to the form.


ShrubberyCreationForm::~ShrubberyCreationForm() {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other.getTarget()) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other.getTarget();
    }
    return *this;
}


void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    executor.checkExecutionRequirements(executor);
    
}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}