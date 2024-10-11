
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "MateriaSource default constructor has been called !" << std::endl;
}


MateriaSource::MateriaSource( const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone(); // Need to explain more the clone !!
        else
            this->_inventory[i] = NULL;
    }
}
/*
La méthode clone() est utilisée ici pour créer une nouvelle instance d'une matière (un objet 
AMateria) à partir de l'objet existant. Cela permet de s'assurer que tu as une copie distincte 
de la matière, plutôt que de référencer la même instance que other pourrait supprimer par la 
suite.
*/


MateriaSource&  MateriaSource::operator=( const MateriaSource& other ) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone(); // Need to explain more the clone !!
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}
/*
Avant d'assigner les nouvelles matières, tu vérifies si l'inventaire courant a déjà une matière. 
Si oui, tu la supprimes pour éviter les fuites de mémoire. Encore une fois, utiliser clone() 
pour créer des copies distinctes garantit que chaque instance dans le nouvel objet MateriaSource 
est autonome.
*/


MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete  _inventory[i];
    }
    std::cout << "MateriaSource destructor has been called !" << std::endl;
}

void    MateriaSource::learnMateria(AMateria* m) {
    if (m) {
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] == NULL) {
                _inventory[i] = m->clone();
                break ;
            }
        }
    }
    else
        return ;
}


AMateria*   MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] && _inventory[i]->getType() == type) {
           return _inventory[i]->clone();
        }
    }
    return NULL;
}

/*
Détails de la Fonction
    1. Paramètre d'entrée :

        - std::string const & type : Ce paramètre représente le type de matière que l'on souhaite créer. 
        Par exemple, on peut vouloir créer une matière de type "ice" ou "cure".

    2. Parcours de l'inventaire :

        - La fonction parcourt les 4 emplacements du tableau _inventory. Cela permet de vérifier chacun des emplacements pour 
        voir s'il contient une matière disponible.

    3. Vérification de l'existence de la matière :

        - La condition if (_inventory[i]) vérifie si l'emplacement courant n'est pas vide (c'est-à-dire qu'il y a une matière 
        stockée à cet index).

    4. Comparaison des types :

        - La condition suivante && _inventory[i]->getType() == type compare le type de la matière actuellement stockée à 
        l'index i avec le type demandé en paramètre. Cela permet de s'assurer que l'on a trouvé une matière de type 
        correspondant à la demande.
        - Par exemple, si type est "ice", la fonction va chercher dans _inventory une matière qui a pour type "ice".

    5. Création d'une nouvelle instance :

        - Lorsque les deux conditions sont satisfaites (il y a une matière à l'index i et son type correspond à celui demandé), 
        la fonction appelle clone() sur cette matière.
        - Le clone() crée une nouvelle instance de la matière en question (par exemple, une nouvelle matière Ice si l'emplacement 
        i contient une matière de type Ice), en utilisant le constructeur de copie que tu as défini.
        - La fonction retourne alors cette nouvelle instance.

    6. Retour de nullptr :

        - Si aucune matière correspondante n'est trouvée après avoir vérifié tous les emplacements, la fonction retourne 
        nullptr. Cela signifie qu'il n'y avait pas de matière de ce type dans l'inventaire.

Utilité de createMateria
La fonction createMateria est essentielle pour :

    - Gestion de l'inventaire : Elle permet à d'autres classes ou objets d'obtenir des instances de matières qui ont été 
    apprises et stockées dans MateriaSource. Cela permet d'utiliser ces matières dans le cadre de l'application (par exemple, 
    pour soigner un personnage ou lancer des sorts).
    - Clonage : En retournant une copie (clone) de la matière, on s'assure que l'instance retournée est indépendante de celle 
    stockée dans l'inventaire. Cela signifie que des modifications apportées à la matière clonée n'affecteront pas la matière 
    originale dans l'inventaire.
    - Flexibilité : Cela permet à différents personnages (ou objets) d'avoir leurs propres copies de la même matière, ce qui 
    est crucial pour des jeux ou des systèmes où plusieurs entités peuvent utiliser les mêmes types de compétences ou d'effets.

Résumé
En résumé, la fonction createMateria cherche dans l'inventaire une matière d'un type spécifique et, si elle en trouve une, 
retourne une copie de cette matière. Cela permet de gérer efficacement les matières dans le système de jeu, garantissant que 
les personnages peuvent accéder à des compétences et des effets de manière isolée et flexible.
*/