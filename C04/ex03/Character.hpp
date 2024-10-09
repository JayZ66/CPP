
#pragma once

#include "AMateria.hpp"

class Charater {
    private:
    std::string _name;
    AMateria*   materials[4];

    public:
    Charater();
    Charater( std::string pname ); // + init empty inventory
    virtual void equip(AMateria* m) = 0; // Ajoute une matière à la 1ère case vide.
    virtual void unequip(int idx) = 0; // retire une matière sans la supp.
    virtual void use(int idx, ICharacter& target) = 0; // Utilise la matière d'un index spécifique.
}