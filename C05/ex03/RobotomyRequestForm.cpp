
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

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecutionRequirements(executor);
    std::cout << "* drilling noises *" << std::endl;
    // To simulate 50% succeed.
    if (rand() % 2) {
        std::cout << getTarget() << " has been robotomized with success !" << std::endl;
    }
    else {
        std::cout << getTarget() << " robotomization has been a failure !" << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}