#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() / _grade(0), _name("") {}

Bureaucrat::Bureaucrat(std::string pname, int pgrade) { // Check if necessary
    _name = pname;
    if (pgrade >= 1 && pgrade <= 150)
        _grade = pgrade;
    else

}

Bureaucrat::~Bureaucrat();

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other.getGrade();
        this->_name = other.getName();
    }
    return *this;
}
    
int Bureaucrat::getGrade() const {
    return _grade;
}

std::string Bureaucrat::getName() const {
    return _name;
}

void    Bureaucrat::incrementGrade();

void    Bureaucrat::decrementGrade();

std::ostream&   Bureaucrat::operator<<(std::ostream& info, const Bureaucrat& other) {
    info << other.getName() << ", bureaucrat grade " << other.getGrade();
    return info;
}
