
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
    checkExecutionRequirements(executor);
    std::ofstream    file((getTarget() + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "       ccee88oo\n"
             << "  C8O8O8Q8PoOb o8oo\n"
             << "dOB69QO8PdUOpugoO9bD\n"
             << "CgggbU8OU qOp qOdoUOdcb\n"
             << "    6OuU  /p u gcoUodpP\n"
             << "       \\\\//  /douUP\n"
             << "         |||\\\\//\\\\\n"
             << "         |||||\\\\//\n"
             << "         |||||\\\\|\n";
        file.close();
    }
    else {
        throw std::ios_base::failure("Failed to open file."); // exception de type std::ios_base::failure est levée
    }

}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}