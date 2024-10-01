
#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixComaNb(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixComaNb;
}

void    Fixed::setRawBits( int const raw )
{
    this->_fixComaNb = raw; // Why this ??
}

Fixed::Fixed(const Fixed &other) // Copy constructor
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // Déréférencer pour donner la "valeur" de l'instance other à la nouvelle (l'actuelle)
}
// On utilise le "=" grâce à l'opérateur d'affectation créé ci-dessous.

Fixed   &Fixed::operator=(const Fixed &other) // Assignment operator
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // Comparing if we are assigning the same add.
        this->_fixComaNb = other.getRawBits();
    return *this;
}

/*
Voyons en détail ce qui se passe dans cette fonction d'opérateur d'affectation 
pour comprendre pourquoi on utilise &other dans la condition et pourquoi on 
renvoie *this.

1. Pourquoi utiliser &other dans la condition if (this != &other) ?

La condition if (this != &other) vérifie si l'adresse mémoire de l'objet courant 
(this) est différente de celle de l'objet other à assigner.

    - this est un pointeur qui pointe vers l'objet courant (l'instance sur 
    laquelle l'opérateur d'affectation est appelé).
    - &other est l'adresse de l'objet passé par référence en argument.

Le but de cette condition est d'empêcher l'auto-affectation (self-assignment). 
C'est-à-dire que si tu fais quelque chose comme a = a, sans cette condition, 
tu tenterais d'assigner un objet à lui-même, ce qui n'a aucun sens et pourrait 
causer des erreurs ou des comportements inattendus (surtout dans des cas où il y a 
de la gestion de mémoire).

En résumé, if (this != &other) signifie : "Ne copie les données que si l'objet 
other est différent de l'objet courant."

2. Pourquoi renvoyer *this ?

Dans la plupart des surcharges de l'opérateur d'affectation, on renvoie une 
référence à l'objet courant pour permettre des affectations en chaîne comme ceci :

a = b = c;

Cela fonctionne grâce au fait que l'opérateur d'affectation renvoie l'objet 
assigné (*this), ce qui permet d'utiliser l'opérateur sur plusieurs objets à la 
suite.

    - this est un pointeur vers l'objet courant.
    - *this déréférence ce pointeur pour obtenir une référence à l'objet lui-même. 
    Ainsi, la ligne return *this; renvoie une référence à l'objet courant (celui 
    qui est en train d'être affecté).

Voici un exemple simplifié de ce qui se passe dans l'opérateur d'affectation :

Fixed a;
Fixed b;

a = b;  // Appelle l'opérateur d'affectation pour copier les valeurs de b dans a

    - Sans la condition if (this != &other), si tu faisais a = a;, cela tenterait 
    de copier a dans lui-même, ce qui est inutile et pourrait être problématique 
    dans des cas plus complexes.
    - Avec le return *this;, la fonction renvoie l'objet a, permettant d'écrire 
    des choses comme a = b = c; dans le cas où l'opérateur est appelé 
    successivement.

En résumé :

    &other dans la condition vérifie que tu ne fais pas une auto-affectation.
    Renvoyer *this permet de renvoyer l'objet courant, facilitant les affectations en chaîne tout en respectant les conventions d'utilisation de l'opérateur d'affectation.
*/


/*
Le déréférencement de this dans le constructeur de recopie.

    Déréférencement de this :
        - this est un pointeur qui pointe vers l'instance courante de la classe 
        (celle qui est en train d'être construite dans ce cas).
        - Quand tu utilises *this = other, tu déréférences this, ce qui signifie 
        que tu accèdes à l'objet lui-même, et non au pointeur.
        - Cela revient à dire : « Je veux copier les données de other dans l'objet 
        actuel ».

    Utilisation de l'opérateur d'affectation :
        - En faisant *this = other, tu appelles l'opérateur d'affectation que tu 
        as défini. Cela permet de copier les attributs de other dans l'objet courant.
        - L'opérateur d'affectation copie tous les attributs définis dans cet 
        opérateur, et ce processus est contrôlé par la logique que tu as mise en 
        place dans la surcharge de cet opérateur (operator=).

    Référence et pointeur :
        - Si other était un pointeur, tu aurais effectivement utilisé *other pour 
        déréférencer le pointeur et accéder à l'objet pointé.
        - Mais ici, other est une référence constante (un alias vers l'objet passé 
        en argument), donc pas besoin de le déréférencer directement. Cependant, 
        tu déréférences this pour accéder à l'objet à gauche de l'opérateur =.

    Pourquoi *this = other dans le constructeur de recopie ?
        - Cela te permet de réutiliser la logique de ton opérateur d'affectation 
        au lieu de réécrire le code pour copier chaque attribut manuellement. 
        En faisant cela, tu centralises la logique de copie au même endroit (
        dans l'opérateur =), ce qui simplifie la maintenance du code et réduit 
        les erreurs.

Pour résumer : en faisant *this = other, tu délègues la copie des attributs à 
l'opérateur d'affectation, qui est déjà conçu pour copier correctement les valeurs 
d'un objet à l'autre. Cela te permet de réutiliser du code au lieu de le dupliquer.
*/