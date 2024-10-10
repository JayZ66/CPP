
#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;

class Character : public ICharacter {
private:
    std::string _name;
    AMateria*   _inventory[4];
    // C'est l'inventaire de Character avec 4 emplacements pour des instances de AMateria. 
    // Chaque case du tableau peut être initialisée à nullptr pour signifier un emplacement vide.


public:
    Character();
    Character( std::string pname ); // + init empty inventory
    Character( const Character& other );
    Character& operator=( const Character& other );
    ~Character();

    void equip(AMateria* m); // Ajoute une matière à la 1ère case vide.
    void unequip(int idx); // retire une matière sans la supp. (Ne dois PAS delete la Materia)
    void use(int idx, ICharacter& target); // Utilise la matière d'un index spécifique.
    std::string const& getName() const;
};
