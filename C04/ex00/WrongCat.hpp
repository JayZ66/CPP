
#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal {
    private:

    public:
    WrongCat( void );
    WrongCat( const WrongCat& other );
    WrongCat& operator=( const WrongCat& other );
    ~WrongCat( void );

    void    makeSound() const;
};