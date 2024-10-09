
#pragma once

#include <iostream>

class   WrongAnimal {
    protected:
    std::string _type;

    public:
    WrongAnimal( void );
    WrongAnimal( std::string _ptype );
    WrongAnimal( const WrongAnimal& other );
    WrongAnimal& operator=( const WrongAnimal& other );
    ~WrongAnimal( void );

    void    makeSound() const;
    std::string     getType() const;

};

/*
L'idée ici est de démontrer comment le polymorphisme fonctionne avec des méthodes virtuelles 
et comment il échoue lorsque les méthodes ne le sont pas.
*/