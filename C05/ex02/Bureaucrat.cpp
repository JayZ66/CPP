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
        std::cout << "Grade's incrementation, grade is now equal to :" << _grade << std::endl;
    }
    else
        throw GradeTooHighException("Grade is too high !");
}

void    Bureaucrat::decrementGrade() {
    if (_grade < 150 && _grade >= 1) {
        _grade++;
        std::cout << "Grade's decrementation, grade is now equal to :" << _grade << std::endl;
    }
    else
        throw GradeTooLowException("Grade is too low !");
}

std::ostream&   operator<<(std::ostream& info, const Bureaucrat& other) {
    info << other.getName() << ", bureaucrat grade " << other.getGrade();
    return info;
}

void    Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this); // Actual instance
        std::cout << "Bureaucrat " << getName() << " signed form " << form.getName() << std::endl;
    }
    catch (const std::exception& e) { // Catch everything that has been throw
        std::cout << "Bureaucrat " << getName() << " couldn't sign form " << form.getName() << " because " << e.what() << std::endl;
    }
}

/*
Can use *this for name ?

Utilisation de *this pour le nom : Oui, tu peux utiliser *this pour obtenir le nom du bureaucrate qui 
essaie de signer le formulaire, car getName() est une méthode de la classe Bureaucrat et *this fait 
référence à l'instance actuelle de Bureaucrat.
*/

/*
catch (const Form::GradeTooLowException& e) => To catch specific exception
OR
catch (const std::exception& e) => To catch all exceptions that were defined in Form class.
*/
