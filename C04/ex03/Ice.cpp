
#include "Ice.hpp"

//  initialiser le type de la materia à "ice"
Ice::Ice() : AMateria("ice") {
    std::cout << "Ice constructor, AMateria derived class, has been called !" << std::endl;
}

Ice::Ice( const Ice& other ) : AMateria(other) {}


Ice& Ice::operator=( const Ice& other ) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}


Ice::~Ice() {
    std::cout << "Ice destructor has been called !" << std::endl;
}


AMateria* Ice::clone() const {
    return new Ice(*this);
}

// Print : Ice : "* shoots an ice bolt at <name> *". <name> est le nom du Character (personnage) passé en paramètre. 
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}