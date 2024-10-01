/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:46:34 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/01 11:46:35 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixComaNb(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixComaNb;
}
void    Fixed::setRawBits( int const raw ) {
	_fixComaNb = raw;
}

// Creating a new object based on the "main" one.
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Copie l'objet entier via l'opérateur d'affectation 
	// or this->_fixComaNb = other._fixComaNb ? ASK
}
/*
Explications : 
Le constructeur de recopie sert à créer un nouvel objet en le 
basant sur un objet déjà existant, en copiant ses attributs.

1. this :

    - Le mot-clé this fait référence à l'instance courante de la 
	classe, c'est-à-dire l'objet que tu es en train de créer ou 
	de manipuler.
    - Dans le contexte du constructeur de recopie, this est 
	l'objet qui est en train d'être initialisé, c'est-à-dire le 
	nouvel objet que tu veux créer en recopiant un autre objet 
	existant.

2. other :

   -  utiliser l'opérateur d'affectation pour éviter de dupliquer du code (=)
   - "= other" appelle l'opérateur d'affectation sur cet objet courant pour lui assigner 
   tous les attributs de other.

3. Ce que fait la ligne :

    - Ici, tu utilises l'opérateur d'affectation que tu as défini pour gérer la 
	copie. Cela assure que le comportement de la copie est centralisé dans 
	l'opérateur d'affectation, ce qui rend ton code plus propre et évite les 
	duplications.
*/


// Don't forget to check if the object is not itself.
Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixComaNb = other.getRawBits(); // Don't forget to use get functions !!
	return *this; // Return a ref to the actual object.
}

/*
Explications : 

1. Condition if (this != &other) :

   -  Cette ligne vérifie si l'objet courant (this) n'est pas 
	le même que l'objet passé en argument (other).

    - Pourquoi cette vérification ? Si tu fais par exemple : 
	a = a;, sans cette condition, l'objet copierait ses propres 
	valeurs, ce qui est inutile. Cela évite aussi d'effacer 
	accidentellement ses propres données.

2. Copie de l'attribut _fixComaNb :

this->_fixComaNb = other.getRawBits();

    - Si les objets sont différents (grâce à la condition 
	précédente), on procède à la copie de l'attribut _fixComaNb 
	de other vers l'objet actuel (this) via mon getteur, plus sûr et flexible 
	d'utiliser les fonctions d'accès (comme getRawBits()) lorsqu'on a des attributs
	privés !

    - Cela permet à l'objet courant de "devenir" une copie de 
	l'autre, en transférant les valeurs des attributs membres.

3. Pourquoi renvoyer *this et non pas this ?

    - this est un pointeur vers l'objet actuel. Si tu retournes 
	simplement this, tu retournerais un pointeur, pas l'objet en 
	lui-même.

    - En revanche, *this déréférence ce pointeur, c'est-à-dire qu'il 
	retourne l'objet actuel en tant que référence (et non un 
	pointeur).

    - En retournant *this, tu permets l'enchaînement d'affectations, 
	ce qu'on appelle du "chaining". Par exemple, avec cette 
	implémentation, tu peux écrire :
		a = b = c;

Cela fonctionne parce que l'opérateur d'affectation renvoie une 
référence à l'objet, permettant ainsi l'affectation en cascade.

En résumé :

    - La vérification if (this != &other) protège contre l'auto-affectation.
    - La copie de l'attribut se fait seulement si les objets sont différents.
    - Le retour de *this permet d'enchaîner les affectations et de garantir 
	que l'opérateur renvoie une référence à l'objet modifié.
*/
