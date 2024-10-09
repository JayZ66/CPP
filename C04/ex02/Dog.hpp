
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Animal;

class   Dog : public Animal {
    private:
    Brain*  _brain;

    public:
    Dog( void );
    Dog( const Dog& other);
    Dog& operator=( const Dog& other);
    ~Dog( void );

    void    makeSound() const; // Cannot use override so need to have the same method as Animal Class.

};