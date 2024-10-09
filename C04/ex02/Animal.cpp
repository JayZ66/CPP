
#include "Animal.hpp"

Animal::Animal( void ) : _type("") {
    std::cout << "Default constructor has been called !" << std::endl;
}

Animal::Animal( std::string _ptype ) : _type(_ptype) {
    std::cout << "Animal constructor has been called !" << std::endl;
}

Animal::Animal( const Animal& other) {
    *this = other;
}

Animal& Animal::operator=( const Animal& other) {
    if (this != &other)
        this->_type = other.getType();
    return *this;
}

Animal::~Animal( void ) {
    std::cout << "Animal destructor has been called !" << std::endl;
}

void    Animal::makeSound() const {}

std::string     Animal::getType() const {
    return _type;
}