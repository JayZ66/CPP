
#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _gradeToSign(50), _gradeToExecute(110) {}

Form::Form(std::string pname, const int pgradeToSign, const int pGradeToExecute) : _name(pname), _isSigned(false), _gradeToSign(pgradeToSign), _gradeToExecute(pGradeToExecute) {
    if (_gradeToExecute < 1 || _gradeToSign < 1) {
        throw GradeTooHighException("Grade is too high !");
    }
    else if (_gradeToExecute > 150 || _gradeToSign > 150) {
        throw GradeTooLowException("Grade is too low !");
    }
}

Form::~Form() {
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

Form::Form(const Form& other)
: _name(other._name), 
      _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), 
      _gradeToExecute(other._gradeToExecute) 
      {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other.getIsSigned(); // Can't copy others attributes bce they are const ??
    }
    return *this;
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= getGradeToSign())
        _isSigned = true;
    else
        throw GradeTooLowException("Bureaucrat's grade is too low compared to the grade to sign.");
        
}

std::string Form::getName() const {
    return _name;
}

bool		Form::getIsSigned() const {
    return _isSigned;
}

int			Form::getGradeToSign() const {
    return _gradeToSign;
}

int			Form::getGradeToExecute() const {
    return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& info, const Form& other) {
    info << "Form's name: " << other.getName() << ", Form's grade to sign: " << other.getGradeToSign() << ", Form's grade to execute: " << other.getGradeToExecute() << ", Form is signed: " << other.getIsSigned() << std::endl;
    return info;
}