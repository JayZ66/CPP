
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    std::cout << "Dog constructor has been called !" << std::endl;
}

Dog::Dog( const Dog& other) : Animal(other) {
    // *this = other;
    _type = other.getType();
}

Dog& Dog::operator=( const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor has been called !" << std::endl;
}

void    Dog::makeSound()
{
    std::cout << "Dog sound is Woof!" << std::endl;
}