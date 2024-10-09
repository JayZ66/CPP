
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    std::cout << "Dog constructor has been called !" << std::endl;
}

/*
Dans ta classe héritée, Cat, tu dois appeler le constructeur de copie de la classe de base 
Animal via la liste d'initialisation. Cela permet de s'assurer que les attributs hérités de 
Animal sont correctement copiés lorsqu'une instance de Cat est copiée.

If Dog has its own attributs we should add in the function a call to the getter for
Dog attributs only.
*/
Dog::Dog( const Dog& other) : Animal(other) {}

Dog& Dog::operator=( const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor has been called !" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Dog sound is Woof!" << std::endl;
}