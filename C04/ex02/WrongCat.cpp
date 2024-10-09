
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor has been called !" << std::endl;
}

// Use initialization list to call WrongAnimal copy const. to initialize WrongCat part
// who is heriting from WrongAnimal.
WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other) {}
/*
Si WrongCat n’a pas d’attribut propre à copier, il est préférable de conserver la liste 
d'initialisation et d'appeler le constructeur de copie de WrongAnimal.

1. Copie de _type : Dans le constructeur de copie de WrongCat, tu copies toujours le _type qui 
est un attribut de WrongAnimal. Étant donné que WrongCat n'a pas d'attributs propres, tu n'as 
pas besoin de te soucier d'autres éléments.

2. Utilisation de la Liste d'Initialisation : En utilisant la liste d'initialisation pour appeler 
le constructeur de copie de WrongAnimal, tu te assures que _type est correctement initialisé à 
partir de l'objet other.
*/

WrongCat& WrongCat::operator=( const WrongCat& other ) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}


WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat destructor has been called !" << std::endl;
}

void    WrongCat::makeSound() const {
    std::cout << "WrongCat makes a sound !" << std::endl;
}