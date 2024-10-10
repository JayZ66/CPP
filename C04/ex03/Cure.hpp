
#pragma once

#include "AMateria.hpp"

class AMateria;

class Cure : public AMateria {
private:


public:
    Cure(); //  initialiser le type de la materia à "cure"
    Cure( const Cure& other );
    Cure& operator=( const Cure& other );
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target); //• Cure : "* heals <name>’s wounds *".  <name> est le nom du Character (personnage) passé en paramètre. 
};

// Use as _type from AMateria cure