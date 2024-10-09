
#include "Cat.hpp"

// Check != btwn "Cat" in Animal constructor & _type = "Cat"
/*
Les deux approches aboutissent au même résultat final (l'attribut _type de Cat aura la valeur 
"Cat"), mais la manière d'y parvenir est différente :

1. Avec initialisation dans le corps du constructeur :

    - L'attribut _type est initialisé une première fois par le constructeur de Animal 
    (avec sa valeur par défaut, probablement une chaîne vide).
    - Puis, dans le corps du constructeur de Cat, l'attribut _type est réassigné à "Cat".

2.Avec initialisation via la liste d'initialisation :

    - L'attribut _type est initialisé directement à "Cat" via la liste d'initialisation, grâce au 
    constructeur paramétré de Animal.

Différence principale :
    - La première méthode fait une initialisation puis une réaffectation (donc deux étapes).
    - La deuxième méthode fait une seule initialisation directe, ce qui est plus performant et 
    conforme aux bonnes pratiques en C++.
*/

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "Cat constructor has been called !" << std::endl;
}

Cat::Cat( const Cat& other) : Animal(other) {}
/*
Utiliser _type = other.getType(); dans le constructeur de copie permet de copier les 
valeurs spécifiques de l'objet other dans le nouvel objet sans provoquer d'effets secondaires, 
alors que *this = other; est destiné à être utilisé sur des objets déjà initialisés.
Or, ici nous n'avons pas encore l'objet Cat existant.
*/

Cat& Cat::operator=( const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor has been called !" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Cat sound is Meow !" << std::endl;
}