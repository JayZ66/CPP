
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    _brain = new Brain();
    std::cout << "Dog constructor has been called !" << std::endl;
}

Dog::Dog( const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {}

Dog& Dog::operator=( const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

/*
Objectif de l'Opérateur d'Assignation
1. Éviter le Partage de Pointeurs :

    Lorsque tu as des pointeurs vers des objets dynamiques (comme Brain), il est crucial de ne pas 
    partager le même pointeur entre plusieurs instances d'une classe. Si deux instances de Cat 
    partageaient le même pointeur _brain, alors si l'une des instances était détruite (via delete), 
    l'autre instance se retrouverait avec un pointeur "dangling" (pointeur qui ne pointe plus vers 
    un objet valide), ce qui pourrait entraîner des erreurs de segmentation ou des comportements 
    indéfinis lors d'un accès à ce pointeur.

2. Suppression de l'Ancienne Instance :

    En utilisant delete _brain sur l'instance courante (celle qui reçoit l'assignation), tu libères 
    l'espace mémoire occupé par l'ancien objet Brain. Cela permet de libérer cette mémoire pour 
    éviter les fuites de mémoire et pour garantir que l'instance courante puisse prendre possession 
    d'un nouvel objet.

3. Création d'un Nouvel Objet :

    En faisant new Brain(*other._brain), tu crées un nouvel objet Brain qui est une copie 
    profonde de l'objet Brain associé à l'autre instance (other). Ce nouvel objet est distinct
    et indépendant de l'ancien.

Impact sur l'Instance Courante et other
    - L'Instance Courante :
    Elle perd son ancien pointeur (qui a été supprimé) et reçoit maintenant un pointeur vers un 
    nouvel objet Brain que tu as créé. Cela signifie que son état est à jour et qu'elle a sa 
    propre copie de Brain.

    - L'Instance other :
    L'instance other conserve son propre pointeur vers son Brain, et rien dans l'opération 
    d'assignation ne change cet état. Son Brain reste intact et valide tant que other existe. 
    C'est pourquoi tu peux faire une copie profonde : tu ne veux pas modifier ou affecter 
    l'état de other.

Résumé
    - En résumé, tu ne partages pas le même pointeur entre instances et tu évites des problèmes 
    potentiels de gestion de mémoire.
    - Chaque instance a maintenant son propre objet Brain, garantissant que chaque instance de 
    Cat fonctionne de manière autonome sans interférences.
*/

Dog::~Dog( void ) {
    delete _brain;
    std::cout << "Dog destructor has been called !" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Dog sound is Woof!" << std::endl;
}