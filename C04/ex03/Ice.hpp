
#pragma once

#include "AMateria.hpp"

Class Ice : public AMateria {
    private:


    public:
    Ice();
    Ice( const Ice& other );
    Ice& operator=( const Ice& other );
    ~Ice();

    AMateria* clone() const;
}