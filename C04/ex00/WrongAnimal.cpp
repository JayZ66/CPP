
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal") {
    std::cout << "Default constructor has been called !" << std::endl;
}

WrongAnimal::WrongAnimal( std::string _ptype ) : _type(_ptype) {
    std::cout << "WrongAnimal constructor has been called !" << std::endl;
}


WrongAnimal::WrongAnimal( const WrongAnimal& other ) {
    *this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
    if (this != &other) {
        this->_type = other.getType();
    }
    return *this;
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal destructor has been called !" << std::endl;
}

void    WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a sound !" << std::endl;
}

std::string     WrongAnimal::getType() const {
    return _type;
}