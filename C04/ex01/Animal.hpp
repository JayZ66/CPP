
#pragma once

#include <iostream>

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
};

/*
Concernant le destructeur de la classe Animal :

    - Nécessité de le déclarer virtual : Il est essentiel de déclarer le destructeur de la classe 
    de base (Animal) comme virtual lorsque tu as des classes dérivées (comme Dog et Cat). 
    Cela permet de s'assurer que lorsque tu supprimes un objet via un pointeur de la classe de base,
    le destructeur approprié de la classe dérivée est appelé. Sans un destructeur virtuel, seul 
    le destructeur de la classe de base serait appelé, ce qui peut entraîner des fuites de mémoire 
    si la classe dérivée a des ressources à libérer.

Dans ton cas, si tu n'avais pas mis virtual dans la classe Animal, quand tu ferais delete j; 
ou delete i;, cela appellerait uniquement le destructeur de Animal, et non ceux de Dog ou Cat. 
Ainsi, toute mémoire allouée spécifiquement dans ces classes dérivées ne serait pas libérée 
correctement.
*/