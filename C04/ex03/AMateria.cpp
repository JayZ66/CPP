
#include "AMateria.hpp"

AMateria::AMateria() : _type("") {
    std::cout << "AMateria default constructor has been called !" << std::endl;
}

AMateria::AMateria( std::string const& type ) : _type(type) {
    std::cout << "AMateria constructor has been called !" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor has been called !" << std::endl;
}

AMateria::AMateria( const AMateria& other ) {
    *this = other;
}

AMateria& AMateria::operator=( const AMateria& other ) {
    if (this != other) {
        _type = other.getType();
    }
    return *this;
}

std::string const& getType() const {
    return _this;
}

void    AMateria::use(ICharacter& target) {

}