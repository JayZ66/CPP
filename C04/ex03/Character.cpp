
#include "Character.hpp"

// std::string _name;
// AMateria*   _materials[4];
// C'est l'inventaire de Character avec 4 emplacements pour des instances de AMateria. 
// Chaque case du tableau peut être initialisée à nullptr pour signifier un emplacement vide.


Character::Character() : _name("") { // Need to declare _materials[] ?
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL; // To specify that there isn't not equiped AMateria yet !
    }
    std::cout << "Character default constructor has been called !" << std::endl;
}

Character::Character( std::string pname ) : _name(pname) { // + init empty inventory
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL; // To specify that there isn't not equiped AMateria yet !
    }
    std::cout << "Character constructor has been called !" << std::endl;
}

Character::Character( const Character& other ) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

/*
1. Initialisation de _name :

    - : _name(other._name) : Cela initialise le membre _name de l'objet en cours (l'objet qui 
    est en train d'être créé) avec le même nom que celui de l'objet other.
    - Cela signifie que si tu as un personnage other qui s'appelle "Alice", alors ton nouvel 
    objet (la copie) s'appellera aussi "Alice".

2. Boucle pour copier les AMateria :

    - for (int i = 0; i < 4; i++) : Cette boucle itère sur les 4 emplacements possibles de 
    _materials, qui contiennent des pointeurs vers des objets AMateria.

3. Vérification de la matière :

    - if (other._materials[i]) : Ici, tu vérifies si l'emplacement i dans le tableau _materials 
    de other n'est pas nullptr. Cela signifie que le personnage other a une matière équipée à 
    cet index.

4. Clonage de la matière :

    - this->_materials[i] = other._materials[i]->clone(); :
        > Si la condition est vraie, cela appelle la méthode clone() de l'objet AMateria pointé 
        par other._materials[i].
        > clone() crée une nouvelle instance de la matière, en utilisant le type spécifique de 
        la matière (par exemple, Ice ou Cure). Cela permet d'obtenir une copie profonde de 
        l'objet, c'est-à-dire une nouvelle instance qui a ses propres données et n'est pas liée 
        à l'original.
        > La nouvelle instance est ensuite assignée à l'emplacement correspondant dans le 
        tableau _materials de l'objet courant (this).

5. Gestion des pointeurs nuls :

    - else this->_materials[i] = nullptr; :
        > Si l'emplacement i de other._materials est nullptr, cela signifie que le personnage 
        other n'a pas de matière équipée à cet index.
        > Dans ce cas, tu assignes également nullptr à l'emplacement correspondant dans ton 
        nouvel objet, afin de garder la cohérence (c'est-à-dire que l'inventaire du nouveau 
        personnage reste vide à cet index).


À quoi cela sert-il ?
    1. Gestion des ressources : Cela garantit que chaque Character a sa propre copie des 
    AMateria, évitant ainsi les problèmes de partage de pointeurs entre plusieurs objets. Par 
    exemple, si un personnage utilise ou modifie une matière, cela ne doit pas affecter un 
    autre personnage qui pourrait partager le même pointeur.

    2. Éviter les fuites de mémoire : En clonant les AMateria, tu t'assures que chaque 
    personnage peut gérer ses propres instances de AMateria sans risque de désallocation 
    accidentelle d'un objet qui est encore utilisé par un autre personnage.

    3. Cohérence : Si tu veux avoir une structure où chaque personnage possède ses propres 
    matières (et potentiellement, chaque personnage peut évoluer indépendamment), le 
    constructeur de copie est crucial pour créer des copies profondes.

Conclusion :

En résumé, ton constructeur de copie pour la classe Character fait exactement ce qu'il est 
censé faire : créer une copie d'un personnage existant en s'assurant que toutes les matières 
équipées sont également clonées. Cela évite les problèmes de gestion de mémoire et assure que 
chaque personnage peut évoluer indépendamment. C'est un aspect fondamental du C++ que tu gères 
bien avec cette approche.
*/

Character& Character::operator=( const Character& other ) {
    if (this != &other) {
        this->_name = other.getName();
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

/*
Dans le cas de ta classe Character, l'opérateur d'assignation est utilisé pour transférer l'état d'un objet Character à un 
autre objet Character. Voici une explication détaillée de ton implémentation :

Signature de l'opérateur d'assignation: Character& Character::operator=(const Character& other)
    - Character& : Cela signifie que la fonction retourne une référence à l'objet courant (this). Cela permet d'utiliser 
    l'opérateur d'assignation dans une chaîne (par exemple, a = b = c).
    - Character:: : Cela indique que cette fonction est définie pour la classe Character.
    - const Character& other : other est une référence constante à un autre objet de type Character. On utilise une référence 
    pour éviter de faire une copie inutile de l'objet et le mot-clé const pour s'assurer que l'objet other ne sera pas modifié.

Corps de l'opérateur d'assignation
    1. Vérification d'auto-assignation : if (this != &other) {
        - Cette ligne vérifie si l'objet courant (this) est différent de l'objet other. Si this et other pointent vers le 
        même objet (par exemple, dans a = a), il n'est pas nécessaire de procéder à une assignation, car cela pourrait 
        entraîner des comportements indésirables, comme la suppression des ressources avant qu'elles ne soient utilisées.

    2. Copie du nom : this->_name = other.getName();
        - Ici, le nom de l'objet other est copié dans l'objet courant. On utilise getName() pour récupérer le nom. 
        Cela permet d'accéder à la méthode getName() de other, ce qui garantit que nous obtenons une valeur correcte et sûre.

    3. Gestion de l'inventaire : for (int i = 0; i < 4; i++) {
        - La boucle for parcourt les 4 emplacements de l'inventaire pour copier les objets AMateria.
        
        a. Suppression des anciennes matières
        if (this->_inventory[i])
            delete this->_inventory[i];
        
        - Avant d'affecter de nouvelles valeurs, on vérifie si un objet AMateria est déjà présent à cet emplacement dans 
        l'objet courant (this). Si c'est le cas, cet objet est supprimé pour éviter les fuites de mémoire. C'est important, 
        car sinon, on laisserait un pointeur "dangling" (pointant vers une mémoire qui a été libérée), ce qui peut provoquer 
        des erreurs.

        b. Clonage des matières
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = nullptr;

        - Si l'emplacement correspondant de other contient une matière, on appelle clone() sur cet objet pour créer une copie 
        de celui-ci et on l'affecte à l'inventaire de l'objet courant. Cela garantit que chaque Character possède sa propre 
        copie des objets AMateria, ce qui est essentiel pour le polymorphisme.
        - Si other._inventory[i] est nullptr, on affecte simplement nullptr à l'emplacement correspondant dans l'inventaire 
        de l'objet courant, ce qui signifie qu'il n'y a pas de matière à cet emplacement.

    4. Retour de l'objet courant
        return *this;

        - À la fin, la fonction retourne une référence à l'objet courant (*this). Cela permet de chaîner les assignations, 
        comme expliqué précédemment. Par exemple, si on a a = b = c, l'assignation à b renvoie b, et ensuite a est assigné à 
        cette référence.
*/


void Character::equip(AMateria* m) { // Ajoute une matière à la 1ère case vide.
    if (m != NULL) {
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] == NULL) {
                _inventory[i] = m->clone();
                return ;
            }
        }
    }
    else
        return ;
}


void Character::unequip(int idx) { // retire une matière sans la supp. (Ne dois PAS delete la Materia)
    if (idx >= 0 && idx < 4) {
        _inventory[idx] = NULL; // retire une matière sans la supp.
    }
    else
        return ;
}

void Character::use(int idx, ICharacter& target) { // Utilise la matière d'un index spécifique.
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        _inventory[idx]->use(target); // Executer l'effet de la matiere (_inventory[idx]) sur le personnage cible (target)
    }
}


std::string const& Character::getName() const {
    return _name;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
    std::cout << "Character destructor has been called !" << std::endl;
}