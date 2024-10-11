
#pragma once

#include <iostream>

 #include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource
{
private:
    AMateria*   _inventory[4];

public:
    MateriaSource();
    MateriaSource( const MateriaSource& other);
    MateriaSource& operator=( const MateriaSource& other );
    ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

/*
learnMateria(AMateria*) :
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.

createMateria(std::string const &) :
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la 
MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type 
est inconnu.
*/

/*
votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.
*/