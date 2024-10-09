
#pragma once

#include "Animal.hpp"

class Animal;

class   Cat : public Animal {
    private:

    public:
    Cat( void );
    Cat( const Cat& other);
    Cat& operator=( const Cat& other);
    ~Cat( void );

    void    makeSound() const; // Cannot use override so need to have the same method as Animal Class.

};