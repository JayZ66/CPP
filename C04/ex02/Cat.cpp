
#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    _brain = new Brain(); // Init our pointer _brain with our Brain obj. So each Cat instance has its own Brain !
    std::cout << "Cat constructor has been called !" << std::endl;
}

Cat::Cat( const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {}

/*
- Initialisation: Quand tu utilises la syntaxe _brain(new Brain()) ou _
    brain(new Brain(*other._brain)), tu initialises le pointeur _brain pour qu'il pointe vers un 
    nouvel objet Brain.
- Indépendance des Objets : En utilisant new Brain(*other._brain), tu crées une copie profonde 
    du cerveau de l'objet source, garantissant que chaque instance de Cat a son propre Brain, sans 
    interférence entre les objets.

Voici une explication détaillée de ce processus :

1. Création d'un Nouvel Objet : Lors de la création d'un nouvel objet Cat (par exemple, dans 
le constructeur de copie), tu initialises l'attribut _brain de cet objet avec 
new Brain(*other._brain).

2. Copie des Informations : Le *other._brain fait référence à l'objet Brain associé à l'objet 
source (celui que tu es en train de copier). En utilisant cette syntaxe, tu dis que tu veux 
créer un nouveau Brain pour le nouvel objet, en copiant les informations (les idées, dans ce cas) 
de l'instance de Brain de l'objet source.

3. Indépendance : Grâce à cette approche, le nouvel objet Cat a son propre pointeur _brain qui 
pointe vers une nouvelle instance de Brain. Cela signifie que les deux objets (Cat source et 
Cat nouvellement créé) ont des Brain distincts. Ainsi, si tu modifies les informations dans le 
Brain de l'un, cela n'affectera pas l'autre.

Résumé :
    - Tu crées un nouvel objet Brain pour l'attribut _brain du nouvel objet Cat.
    - Ce nouvel objet Brain est initialisé avec les informations de l'objet Brain de l'objet 
    source (*other._brain).
    - Cela permet d'avoir deux objets Cat distincts, chacun avec son propre Brain, évitant 
    ainsi les interférences entre eux.
*/

Cat& Cat::operator=( const Cat& other ) {
    if (this != &other) {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat( void ) {
    delete  _brain;
    std::cout << "Cat destructor has been called !" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Cat sound is Meow !" << std::endl;
}