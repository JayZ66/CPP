
#pragma once

#include "AMateria.hpp"

class IMateriaSource
{

public:
    IMateriaSource();
    IMateriaSource( const IMateriaSource& other );
    IMateriaSource& operator=( const IMateriaSource& other );

    virtual ~IMateriaSource(); // Déstructeur virtuel pour permettre une destruction correcte via un pointeur de base.

    virtual void learnMateria(AMateria*) = 0; // Permet d'apprendre une nouvelle Materia
    virtual AMateria* createMateria(std::string const & type) = 0; // Crée une Materia en fonction du type
};