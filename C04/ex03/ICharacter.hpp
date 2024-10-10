
#pragma once

#include "AMateria.hpp"

class AMateria;

class ICharacter {
public:
    ICharacter();
    ICharacter( const ICharacter& other );
    ICharacter& operator=( const ICharacter& other );
    virtual ~ICharacter();

    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0; // Équipe une Materia dans l'inventaire
    virtual void unequip(int idx) = 0; // Déséquipe une Materia de l'index spécifié
    virtual void use(int idx, ICharacter& target) = 0; // Utilise la Materia de l'index spécifié
};

// As it's an interface no need to private section !