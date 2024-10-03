/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:23:39 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/03 10:33:20 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

Fixed::Fixed( void ) : _fixComaNb(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int integer)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixComaNb = integer << _fractionalBit;
}

// Fixed::Fixed( const float float_nb )
// {
// 	// std::cout << "Float constructor called" << std::endl;
// 	this->_fixComaNb = (int)roundf(float_nb * 256); 
// }

Fixed::Fixed(const float float_nb) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixComaNb = static_cast<int>(roundf(float_nb * (1 << _fractionalBit)));
    std::cout << "Fixed value (raw bits): " << this->_fixComaNb << std::endl;
}


Fixed::Fixed( const Fixed& other )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=( const Fixed& other )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixComaNb = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return _fixComaNb;
}

void	Fixed::setRawBits( int const raw )
{
	_fixComaNb = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(_fixComaNb) / 256; // NPO : Cast attribute and THEN divide !!
}

// No need to use this in toInt() & toFloat function as there is no param. or use of object.

int Fixed::toInt( void ) const {
	return _fixComaNb >> _fractionalBit;
}

std::ostream& operator<<(std::ostream& nb, const Fixed& other) {
	nb << other.toFloat();
	return nb;
}

// ------------------- Operateur de comparaison -----------------

bool    Fixed::operator>( const Fixed& other ) const {
	if (this->_fixComaNb > other.getRawBits()) // Sending by default a bool.
		return true;
	else
		return false;
}
// Also, we can do : return this->_fixComaNb > other.getRawBits();

bool    Fixed::operator<( const Fixed& other ) const {
	return this->_fixComaNb < other.getRawBits();
}

bool    Fixed::operator>=( const Fixed& other ) const
{
	return this->_fixComaNb >= other.getRawBits();
}

bool    Fixed::operator<=( const Fixed& other ) const {
	return this->_fixComaNb <= other.getRawBits();
}

bool    Fixed::operator==( const Fixed& other ) const {
	return this->_fixComaNb == other.getRawBits();
}

bool    Fixed::operator!=( const Fixed& other ) const {
	return this->_fixComaNb != other.getRawBits();
}


// ----------------- Operateurs arithmetiques -----------------


// Fixed   Fixed::operator+( const Fixed& other ) {
// 	return Fixed(this->_fixComaNb + other.getRawBits());
// } TO TEST !!!!

Fixed   Fixed::operator+( const Fixed& other ) {
	Fixed	result;
	result.setRawBits(this->_fixComaNb + other.getRawBits());
	return result;
}

// Fixed   Fixed::operator-( const Fixed& other ) {
// 	int result = this->_fixComaNb - other.getRawBits();
// 	Fixed	newObject(result);
// 	return newObject;
// }

Fixed   Fixed::operator-( const Fixed& other ) {
	Fixed	result;
	result.setRawBits(this->_fixComaNb - other.getRawBits());
	return result;
}

// Fixed   Fixed::operator*( const Fixed& other ) {
// 	int result = (this->_fixComaNb * other.getRawBits()) / 256;
// 	Fixed	newObject(result);
// 	return newObject;
// }

Fixed   Fixed::operator*( const Fixed& other ) {
	Fixed	result;
	result.setRawBits((this->_fixComaNb * other.getRawBits()) / 256);
	return result;
}

/*
WHY DIV BY 256 ?

Tu obtiens un résultat qui est potentiellement trop grand (multiplication de deux nombres 
à virgule fixe). Pour maintenir la précision du nombre à virgule fixe, tu devras diviser 
le résultat par un facteur équivalent à 2^_fractionalBit. Cela ajuste le résultat pour qu'il 
reste dans la bonne échelle de la valeur à virgule fixe.
*/

// Fixed   Fixed::operator/( const Fixed& other ) {
// 	int result = (this->_fixComaNb * 256) / other.getRawBits();
// 	Fixed	newObject(result);
// 	return newObject;
// }

Fixed   Fixed::operator/( const Fixed& other ) {
	Fixed	result;
	result.setRawBits((this->_fixComaNb * 256) / other.getRawBits());
	return result;
}

/*
WHY MULT BY 256 ?

Pour maintenir la precision lors des operations sur des nb a virgule fixe.

1. Division sans ajustement
	Si tu divises directement deux nombres à virgule fixe sans ajuster, tu perds en précision. 
	Par exemple, si tu divises 128 par 64, tu obtiendras 2 en tant que valeur entière, mais 
	comme ce sont des nombres à virgule fixe, le résultat réel devrait être un nombre décimal.

2. Multiplier pour compenser la perte de précision
	Pour éviter cette perte de précision, il est nécessaire de multiplier le numérateur par 2^8
	(dans ton cas, 256), ce qui compense l'effet de la division. Cela revient à dire "je veux 
	effectuer la division en conservant la partie fractionnaire", et l'échelle de la fraction 
	est conservée par cette multiplication.
*/


// ----------------- Operateurs d'incrementation ----------------

// Pré-incrémentation augmente la valeur de l'objet avant de le retourner.
Fixed   &Fixed::operator++()
{
	this->_fixComaNb++;
	return *this;
}

// Post-incrémentation augmente la valeur de l'objet apres avoir retourne l'ancienne valeur.
/*
Par exemple, lorsque tu fais x = a++, x reçoit la valeur de a avant l'incrémentation, tandis 
que a est déjà augmentée de 1. Cela permet aux programmeurs de travailler avec l'ancienne 
valeur tout en mettant à jour l'objet pour des opérations futures.
*/

Fixed   Fixed::operator++(int)
{
	Fixed	temp(*this); // Crée un objet temporaire comme copie de l'objet actuel
	this->_fixComaNb += 1;
	return temp;
}

Fixed   &Fixed::operator--() // Pré-décrémentation
{
	this->_fixComaNb++;
	return *this;
}

Fixed   Fixed::operator--(int) // Post-décrémentation
{
	Fixed	temp(*this);
	this->_fixComaNb -= 1;
	return temp;
}

// Fixed   Fixed::operator--(int) // Post-décrémentation
// {
// 	int	oldValue = this->_fixComaNb;
// 	this->_fixComaNb -= 1;
// 	return Fixed(oldValue);
// }

/*
BONNE VERSION VS BAD VERSION :
Premiere version :
	- Crée une copie exacte de l'objet courant avant de modifier sa valeur.
	- Assure que l'objet retourné est cohérent et fidèle à l'objet avant l'incrémentation.
	
Deuxieme version :
	- Problème avec la gestion de la valeur temporaire car tu utilises la valeur brute (oldValue) 
	pour créer un nouvel objet Fixed. Cela peut mener à des incohérences dans les valeurs de 
	retour.
	- L'objet retourné n'est pas une copie fidèle de l'objet avant l'incrémentation.

*/

// ----------------- Fonctions membres publiques surchargees ----------------

// Return : une ref. a un objet existant de type Fixed.
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

const Fixed  &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

/*
EXPLICATIONS : 

Voici comment ça fonctionne :

1. Surcharge de l'Opérateur : Quand tu écris a < b, cela déclenche l'appel à ta méthode 
operator< définie dans la classe Fixed.

	- Dans cette méthode, tu peux comparer les valeurs des attributs internes des objets a et b.

2. Accès aux Attributs Internes : Par exemple, dans la méthode operator<, tu pourrais avoir 
quelque chose comme :
	return this->_fixComaNb < other.getRawBits();
	
	- Ici, this fait référence à l'instance de Fixed sur laquelle l'opérateur est appelé 
	(disons a), et other est l'instance passée en paramètre (dans ce cas, b).

3. Comparaison des Valeurs : La méthode compare directement les valeurs de _fixComaNb des 
deux instances, ce qui te donne le résultat souhaité.
*/
