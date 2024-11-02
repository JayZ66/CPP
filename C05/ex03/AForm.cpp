
#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(50), _gradeToExecute(110) {}

AForm::AForm(std::string pname, const int pgradeToSign, const int pGradeToExecute) : _name(pname), _isSigned(false), _gradeToSign(pgradeToSign), _gradeToExecute(pGradeToExecute) {
    if (_gradeToExecute < 1 || _gradeToSign < 1) {
        throw GradeTooHighException("Grade is too high !");
    }
    else if (_gradeToExecute > 150 || _gradeToSign > 150) {
        throw GradeTooLowException("Grade is too low !");
    }
}

AForm::~AForm() {
    std::cout << "Form destructor has been called !" << std::endl;
}

/*
Voici ce qui se passe :

Membres const : Dans ta classe Form, les membres _gradeToSign et _gradeToExecute sont déclarés comme 
const. Cela signifie que leur valeur doit être fournie lors de l'initialisation et ne peut pas être 
modifiée par la suite.

Constructeur de copie : Dans le constructeur de copie Form::Form(const Form& other), tu dois initialiser 
ces membres const à partir de l'objet other passé en paramètre. Cependant, tu n'as pas de liste 
d'initialisation dans ce constructeur, ce qui conduit à l'erreur.

DONC USE INITIALIZATION LIST :
*/

AForm::AForm(const AForm& other)
: _name(other._name), 
      _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), 
      _gradeToExecute(other._gradeToExecute) 
      {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other.getIsSigned(); // Can't copy others attributes bce they are const ??
    }
    return *this;
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= getGradeToSign())
        _isSigned = true;
    else
        throw GradeTooLowException("Bureaucrat's grade is too low compared to the grade to sign.");
        
}

std::string AForm::getName() const {
    return _name;
}

bool		AForm::getIsSigned() const {
    return _isSigned;
}

int			AForm::getGradeToSign() const {
    return _gradeToSign;
}

int			AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& info, const AForm& other) {
    info << "AForm's name: " << other.getName() << ", AForm's grade to sign: " << other.getGradeToSign() << ", AForm's grade to execute: " << other.getGradeToExecute() << ", AForm is signed: " << other.getIsSigned() << std::endl;
    return info;
}


void    AForm::checkExecutionRequirements(const Bureaucrat& executor) const {
    if (executor.getGrade() >= getGradeToExecute())
        throw GradeTooLowException("Grade is too low !");
    else if (!_isSigned)
        throw FormNotSignedException("Form is not signed !");
}