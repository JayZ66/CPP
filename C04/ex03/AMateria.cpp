
#include "AMateria.hpp"

AMateria::AMateria() : _type("") {
    std::cout << "AMateria default constructor has been called !" << std::endl;
}

AMateria::AMateria( std::string const& type ) : _type(type) {
    std::cout << "AMateria constructor has been called !" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor has been called !" << std::endl;
}

AMateria::AMateria( const AMateria& other ) {
    *this = other;
}

AMateria& AMateria::operator=( const AMateria& other ) {
    if (this != &other) {
        _type = other.getType();
    }
    return *this;
}

std::string const& AMateria::getType() const {
    return _type;
}

// appliquer l'effet de la matière sur un personnage (ICharacter) cible.
void    AMateria::use(ICharacter& target) {
    std::cout << "Using AMateria on " << target.getName() << std::endl;
}

/*
Voici quelques précisions pour mieux comprendre :

1. Rôle d'AMateria : En effet, AMateria représente une sorte de "sort" ou "capacité" que les 
personnages peuvent utiliser. Chaque classe dérivée, comme Ice ou Cure, représente un type 
spécifique de matière avec des effets uniques.

2. Utilisation par un personnage : Lorsqu'un personnage (qui implémente ICharacter) utilise une 
matière, il appelle la méthode use de cette matière en lui passant lui-même comme cible. Cela 
permet à la matière d'appliquer ses effets au personnage ou à un autre personnage en fonction 
de la logique de ton jeu.

3. Mise en œuvre des effets spécifiques : Dans la classe dérivée (comme Ice ou Cure), tu devras 
probablement remplacer la méthode use pour ajouter le comportement spécifique. Par exemple, dans 
Cure, tu afficherais un message indiquant que le personnage est soigné, tandis que dans Ice, tu 
indiquerais qu'un projectile de glace est tiré.

4. Le polymorphisme : Grâce à la méthode virtuelle, lorsque tu appelles use sur une instance de 
AMateria, le comportement spécifique de la classe dérivée sera exécuté, même si la méthode est 
appelée sur une référence de type AMateria.


Voici une explication plus détaillée pour clarifier :

1. Utilisation de use(ICharacter& target) : Lorsque tu appelles la méthode use sur une instance 
d'une matière (comme Ice ou Cure), tu passes une référence à un personnage qui est une instance 
de la classe qui implémente ICharacter. Cela signifie que tu dis : "Je veux utiliser cette 
matière sur ce personnage spécifique."

2. La référence à ICharacter : En passant une référence à ICharacter, tu peux appeler des 
méthodes définies dans l'interface, comme getName(). Cela te permet d'accéder au nom du 
personnage cible sans savoir exactement quel type de personnage tu utilises. Cela rend ton code 
plus flexible, car tu peux utiliser n'importe quel type de personnage qui implémente 
l'interface ICharacter.

3. Effets de la matière sur le personnage : La méthode use dans AMateria est généralement 
conçue pour être une sorte de "gabarit" ou de point d'entrée. Lorsqu'elle est appelée, elle 
peut simplement préparer le terrain pour que les classes dérivées, comme Ice ou Cure, 
appliquent leurs effets spécifiques sur le personnage. Par exemple, l’effet de Cure pourrait 
augmenter les points de vie du personnage, tandis que l’effet de Ice pourrait infliger des 
dégâts.

4. Interaction entre classes : Ainsi, lorsque tu écris someAMateria->use(someCharacter);, tu 
dis à la matière : "Utilise-toi sur ce personnage." La méthode va alors appeler la méthode 
spécifique (dans Ice ou Cure) pour effectuer les actions nécessaires.

En résumé, lorsque tu fais someAMateria->use(someCharacter);, cela va directement appeler la 
version de use définie dans la classe dérivée (par exemple, Ice ou Cure) qui contient la 
logique spécifique pour cet effet de matière sur le personnage someCharacter. La méthode dans 
AMateria n'est pas utilisée dans ce cas, sauf si tu l'appelles directement à l'intérieur de la 
méthode de la classe dérivée, soit un appel explicite à AMateria::use à l'intérieur des classes 
dérivées. 
En général, la méthode use dans AMateria sert de déclaration de base
*/