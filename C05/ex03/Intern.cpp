
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern::~Intern() {
    std::cout << "Intern destructor has been called." << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void) other;
    return *this;
}

AForm*  Intern::ShrubberyCreation(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::RobotomyRequestCreation(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm*  Intern::PresidentialPardonCreation(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm*    Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formsName[3] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm",
    };

    AForm*    (Intern::*ptrForm[3]) (const std::string&) = {
        &Intern::ShrubberyCreation,
        &Intern::RobotomyRequestCreation,
        &Intern::PresidentialPardonCreation,
    };

    for (int i = 0; i <  3; i++) {
        if (formsName[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*ptrForm[i])(target);
        }
    }
    std::cout << "Failed to create a form, " << formName << " is not a valid form type !" << std::endl;
    return NULL;
}

/*
Elle devra créer un objet de type Form (ou l'une de ses classes dérivées, comme 
ShrubberyCreationForm, RobotomyRequestForm ou PresidentialPardonForm) selon le 
nom passé.
*/

/*
Si le nom du formulaire fourni ne correspond à aucun type connu, vous devrez 
imprimer un message d'erreur explicite.
*/