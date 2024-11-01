#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string ptarget) : AForm("PresidentialPardonForm", 25, 5), _target(ptarget) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other.getTarget();
    }
    return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const;

std::string PresidentialPardonForm::getTarget() const {
    return _target;
}