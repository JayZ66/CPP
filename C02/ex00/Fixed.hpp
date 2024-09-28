
#pragma once

#include <iostream>

class   Fixed {
    private:
        int _fixComaNb;
        static const int _fractionalBits = 8;

    public:
        Fixed( void );

        Fixed(const Fixed &other); // Copy constructor
        Fixed &operator=(const Fixed &other); // Assignment operator

         ~Fixed( void );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

/*

1. Constructeur par défaut : 
Ce constructeur ne prend aucun paramètre et 
initialise les attributs de la classe. Il est essentiel pour permettre 
la création d'objets sans avoir besoin de données initiales.

2. Constructeur de recopie (copy constructor) : 
Ce constructeur permet de créer une copie d'un objet existant. Il est utilisé 
lorsqu’un objet doit être passé par valeur ou copié.

ClassName(const ClassName &other);

3. Opérateur d’affectation (assignment operator) : 
Cette fonction permet de copier les valeurs d'un objet à un autre déjà existant, 
après leur création.

ClassName &operator=(const ClassName &other);

4. Destructeur : C’est la fonction qui est appelée lorsque l’objet est détruit 
(généralement en fin de vie ou lors de l’appel à delete).

~ClassName();
*/

/*
CONSTRUCTEUR DE COPIE VS OPERATEUR D'AFFECTATION : 

1. Quand sont-ils appelés ?

- Constructeur de copie : Il est appelé lors de la création d'un nouvel objet 
à partir d'un objet existant. Cela signifie qu'il est utilisé quand tu veux 
initialiser un nouvel objet avec une copie d'un autre objet.

    Exemple :
MaClasse obj1;
MaClasse obj2 = obj1;  // Constructeur de copie appelé

- Opérateur d'affectation : Il est utilisé lorsque tu assignes une valeur d'un 
objet existant à un objet déjà créé. Ici, l'objet cible existe déjà, et tu veux 
remplacer ses valeurs par celles d'un autre objet.

Exemple :
    MaClasse obj1;
    MaClasse obj2;
    obj2 = obj1;  // Opérateur d'affectation appelé


2. La gestion de la mémoire

Dans les deux cas, si ta classe gère des ressources dynamiques (par exemple des 
pointeurs), il y a un enjeu de copie profonde pour s'assurer que chaque objet 
possède sa propre copie des ressources (et non simplement une référence partagée).
Le comportement est similaire, mais l'ordre des opérations diffère.

    - Constructeur de copie : Alloue les ressources pour l'objet nouvellement créé 
    en fonction de l'objet source.
    - Opérateur d'affectation : Libère d'abord les ressources déjà utilisées par 
    l'objet (s'il y en a) avant de copier les ressources de l'objet source.

3. Différences en termes de logique

    - Constructeur de copie : Il s'exécute sur un objet qui n'existe pas encore 
    (ou qui vient juste d'être créé en mémoire), donc il initialise complètement 
    l'objet cible.

    - Opérateur d'affectation : Il agit sur un objet déjà existant, et son rôle 
    est de remplacer les données de cet objet sans nécessairement allouer ou 
    libérer la mémoire (sauf s'il doit gérer la mémoire dynamique).

4. Exemple comparatif :

Voici un exemple qui met en évidence la différence entre les deux :

class MaClasse {
    int* data;
public:
    // Constructeur de copie
    MaClasse(const MaClasse& other) {
        data = new int(*other.data);  // Copie profonde
    }

    // Opérateur d'affectation
    MaClasse& operator=(const MaClasse& other) {
        if (this != &other) {  // Eviter l'auto-affectation
            delete data;       // Libérer la mémoire existante
            data = new int(*other.data);  // Copier les données de l'autre objet
        }
        return *this;
    }

    ~MaClasse() {
        delete data;  // Nettoyage de la mémoire
    }
};


5. Auto-affectation (self-assignment)

L'opérateur d'affectation doit gérer un cas particulier : l'auto-affectation. 
C'est le cas où tu assignes un objet à lui-même, comme ceci :

obj1 = obj1;  // Auto-affectation

Dans ce cas, si l'opérateur d'affectation n'est pas correctement implémenté 
(comme l'exemple ci-dessus avec le test if (this != &other)), tu risques de 
libérer la mémoire que l'objet utilise avant même de la copier, causant des 
comportements indésirables.

Conclusion

    - Le constructeur de copie est utilisé lors de la création d'un objet à partir 
    d'un autre objet.
    - L'opérateur d'affectation est utilisé pour assigner les données d'un objet 
    existant à un autre objet déjà initialisé.

En résumé, ils sont similaires mais se comportent dans des contextes différents. 
Dans un code bien conçu, tu implémenteras probablement les deux, mais en gardant à 
l'esprit leurs rôles spécifiques.
*/