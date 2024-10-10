
#pragma once

#include "AMateria.hpp"

class AMateria;

class Ice : public AMateria {
private:


public:
    Ice(); //  initialiser le type de la materia à "ice"
    Ice( const Ice& other );
    Ice& operator=( const Ice& other );
    ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);// Print : Ice : "* shoots an ice bolt at <name> *". <name> est le nom du Character (personnage) passé en paramètre. 
};
