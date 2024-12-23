#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(1) {}

Bureaucrat::Bureaucrat(std::string pname, int pgrade) : _name(pname) { // Because _name is const so list initialization needed.
    if (pgrade >= 1 && pgrade <= 150)
        _grade = pgrade;
    else if (pgrade < 1)
        throw GradeTooHighException("Grade is too high !");
    else
        throw GradeTooLowException("Grade is too low !");

}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor has been called !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other.getGrade(); // Cannot give new value to _name as it's a const value.
    }
    return *this;
}
    
int Bureaucrat::getGrade() const {
    return _grade;
}

std::string Bureaucrat::getName() const {
    return _name;
}

void    Bureaucrat::incrementGrade() {
    if (_grade > 1 && _grade <= 150) {
        _grade--;
    }
    else
        throw GradeTooHighException("Grade is too high !");
}

void    Bureaucrat::decrementGrade() {
    if (_grade < 150 && _grade >= 1) {
        _grade++;
    }
    else
        throw GradeTooLowException("Grade is too low !");
}

std::ostream&   operator<<(std::ostream& info, const Bureaucrat& other) {
    info << other.getName() << ", bureaucrat grade " << other.getGrade();
    return info;
}
