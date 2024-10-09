
#pragma once

#include "AMateria.hpp"

Class Cure : public AMateria {
    private:


    public:
    Cure();
    Cure( const Cure& other );
    Cure& operator=( const Cure& other );
    ~Cure();

    AMateria* clone() const;
}