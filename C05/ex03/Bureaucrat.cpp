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

void    Bureaucrat::signForm(AForm& form) {
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

void    Bureaucrat::executeForm(const AForm& form) {
    try {
        form.execute(*this); // Will try to execute the right form, that'll check requirements to exec, with Bureaucrat's data.
        std::cout << *this << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << *this << " cannot execute form " << form.getName() << " because " << e.what() << std::endl;
    }
}

/*
Étape 1 : Appel de la Méthode executeForm

Lorsque la méthode executeForm est appelée sur un objet Bureaucrat, elle reçoit en 
paramètre une référence à un objet de type AForm. Cette méthode va essayer d’exécuter le 
formulaire en appelant form.execute(*this);.

Étape 2 : Polymorphisme et Fonction execute

Le paramètre form est de type AForm, mais comme AForm est une classe abstraite (grâce à 
la méthode virtuelle pure execute), form doit en réalité être une instance d’une des 
classes dérivées de AForm : ShrubberyCreationForm, RobotomyRequestForm, ou 
PresidentialPardonForm.

Le polymorphisme entre en jeu ici : en utilisant une référence (ou un pointeur) vers 
AForm, on peut manipuler un objet de n’importe quelle sous-classe de AForm grâce aux 
méthodes virtuelles.

Étape 3 : Appel de la Méthode Virtuelle execute

Quand form.execute(*this); est appelé :

    - En raison de la nature polymorphique de AForm, le programme va chercher la méthode 
    execute dans la classe dérivée réelle de form.
    - Par exemple, si form est une instance de ShrubberyCreationForm, alors c’est 
    ShrubberyCreationForm::execute qui sera appelée.

Ce comportement est rendu possible grâce au mot-clé virtual de la méthode execute dans 
AForm, qui permet au programme de choisir dynamiquement la bonne implémentation de 
execute selon le type réel de l’objet.

Étape 4 : Vérifications d’Exécution dans la Méthode execute

Dans chaque implémentation de execute des sous-classes (ShrubberyCreationForm, 
RobotomyRequestForm, etc.), il y a un appel à checkExecutionRequirements, qui vérifie :

    - Si le formulaire est signé.
    - Si le grade du Bureaucrat exécutant est suffisant.

Ces vérifications peuvent lever des exceptions (comme GradeTooLowException ou 
FormNotSignedException) si l’une des conditions n’est pas remplie.

Étape 5 : Gestion des Exceptions

Si une exception est levée pendant l’appel de form.execute(*this);, elle sera 
interceptée par le bloc catch dans executeForm. Cela permet à Bureaucrat d’afficher un 
message d’erreur indiquant pourquoi l’exécution du formulaire a échoué.

*/
