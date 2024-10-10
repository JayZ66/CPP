
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") { //  initialiser le type de la materia à "cure"
    std::cout << "Cure constructor, AMateria derived class, has been called !" << std::endl;
}


Cure::Cure( const Cure& other ) : AMateria(other) {}


Cure& Cure::operator=( const Cure& other ) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}


Cure::~Cure() {
    std::cout << "Cure destructor has been called !" << std::endl;
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
//• Cure : "* heals <name>’s wounds *".  <name> est le nom du Character (personnage) 
// passé en paramètre. 

// Créer une copie de l'objet actuel (une instance de AMateria dérivée comme Ice ou Cure)
// On cree un nouvel objet Cure, depuis l'actuel, via son constructeur de copie avec les "infos" 
// de l'objet Cure actuel (donc * this)
AMateria* Cure::clone() const {
    return new Cure(*this);
}

/*
Exemple d'idée générale :
    - Lorsque tu appelles clone() sur un objet Cure, par exemple :
        Cure* cure = new Cure();
        AMateria* clonedCure = cure->clone();

Le pointeur clonedCure pointera vers une nouvelle instance de Cure qui est une copie de l'objet 
cure. Les "infos" ou les données contenues dans cure seront donc répliquées dans le nouvel 
objet (si des attributs spécifiques existent dans Cure, ils seront aussi copiés si tu utilises 
un constructeur de copie ou le constructeur par défaut).

Conclusion :
 - Tu crées un nouvel objet avec les mêmes "infos" (c'est-à-dire le même état) que l'objet 
 actuel.
 - Le pointeur retourné pointe vers ce nouvel objet.
 - Cela permet de manipuler des objets polymorphiques, tout en ayant la possibilité de les 
 dupliquer proprement, sans connaître leur type exact au moment de l'appel de la fonction.


 Utilité de clone() :
1. Polymorphisme et duplication d'objets :

Dans un contexte où tu manipules des pointeurs vers des classes de base (par exemple, des pointeurs vers AMateria), 
tu peux utiliser clone() pour dupliquer un objet sans savoir son type dérivé exact.
Cela permet à une fonction de créer une copie correcte d'un objet sans avoir besoin de connaître à quel type dérivé 
(Cure, Ice, etc.) cet objet appartient.

2. Création dynamique d'objets :

Quand tu veux dupliquer un objet via un pointeur de base, clone() t'assure que tu copies correctement l'objet dérivé. 
En d'autres termes, tu appelles clone() sur un pointeur de type AMateria*, mais si l'objet pointé est en fait un Cure, alors 
la méthode clone() va créer un nouveau Cure, sans que la fonction appelante ait besoin de connaître ce type.

Exemple d'utilisation :
Imagine un inventaire qui contient plusieurs objets de type AMateria*. Le programme ne sait pas à l'avance si chaque élément 
de l'inventaire est un Cure ou un Ice. Pour faire une copie de chaque élément dans un autre inventaire, tu pourrais écrire 
quelque chose comme :

AMateria* clonedMateria = someMateria->clone();

Peu importe que someMateria soit un Cure, un Ice, ou un autre type dérivé de AMateria, la fonction clone() va appeler le bon 
constructeur et retourner un pointeur vers une nouvelle instance de ce type spécifique.

Résumé des avantages :
- Flexibilité avec le polymorphisme : tu peux dupliquer des objets sans connaître leur type exact.
- Gestion propre des allocations dynamiques : tu crées dynamiquement une nouvelle instance via un pointeur.
- Reproduction fidèle de l'objet : clone() assure que l'objet copié est une réplique exacte de l'original, mais de manière 
polymorphique.

*/