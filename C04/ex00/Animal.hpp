
#pragma once

class   Animal {
    protected:
    std::string _type;

    public:
    Animal( void );
    Animal( std::string _ptype );
    Animal( const Animal& other);
    Animal& operator=( const Animal& other);
    virtual ~Animal( void ); // Destructeur virtual pour s'assurer de la destruction des objets dérivés.

    virtual void    makeSound() const; // Virtual method for polymosphism.
    std::string     getType() const;
}