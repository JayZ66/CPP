
#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    _type = "Cat";
    std::cout << "Cat constructor has been called !" << std::endl;
}

Cat::Cat( const Cat& other) : Animal(other) {
    // *this = other;
    _type = other.getType(); // WHY ?
}

Cat& Cat::operator=( const Cat& other) {
    if (this != other) {
        Animal::operator=(other);
    }
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor has been called !" << std::endl;
}

void    Cat::makeSound()
{
    std::cout << "Cat sound is Meow !" << std::endl;
}