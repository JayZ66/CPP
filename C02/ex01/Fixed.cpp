/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:52:09 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/01 17:55:59 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8; // Mettre Fixed:: devant ??

// Can use roundf function from cmath lib.
/*
Explanation : 
Arrondit une valeur a virgule flottante a la valeur entiere la plus proche.
Parametres (x): Valeur a virgule flottante a arrondir
Return value : Valeur a virgule flottante qui represente l'entier le + proche de x (param.)
*/

Fixed::Fixed( void ) : _fixComaNb(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int integer ) {
    std::cout << "Int constructor called" << std::endl;
   this->_fixComaNb = integer << _fractionalBit; // Décalage à gauche pour créer la partie fractionnaire (partie décimale).
}

/*
EXPLICATIONS : 
Décalage vers la gauche : L'instruction integer << _fractionalBit décale les bits de 
l'entier integer vers la gauche de _fractionalBit positions (dans ton cas, probablement 8).
Cela multiplie l'entier par 2^_fractionnalBit;, ce qui permet de "convertir" ton entier en une 
valeur à virgule fixe.

Par exemple, si integer = 5 et _fractionalBit = 8 :

Le résultat de 5 << 8 sera 1280 (équivalent à 5 * 256), qui est la représentation en 
virgule fixe avec 8 bits pour la partie fractionnaire.
Affectation : Ensuite, tu assignes directement ce résultat à _fixComaNb, ce qui fait que ta 
variable privée _fixComaNb stocke la valeur décalée.
*/

Fixed::Fixed( const float float_nb ) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixComaNb = (int)roundf(float_nb * 256); //1 << _fractionalBit
}

/*
EXPLICATIONS : to modify a float to a fix coma value (int)

Voici ce que tu devrais faire étape par étape, sans te donner le code directement :

1. Multiplie la valeur float_nb par 2^fractionalBit 
(ce qui peut se faire avec 1 << _fractionalBit en decalage de bit).
2. Arrondis le résultat avec roundf().
3. Convertis le résultat arrondi en entier et assignes-le à _fixComaNb.
*/

Fixed::Fixed( const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixComaNb = other.getRawBits();
    return *this;
}

int     Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixComaNb;
}

void    Fixed::setRawBits( int const raw ) {
    _fixComaNb = raw;
}


Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>(_fixComaNb) / 256;
}
// Use static_cast as it's more secured !

/*
Comprendre la Conversion
Objectif de toFloat() :

    1. La méthode toFloat() doit retourner la valeur stockée dans _fixComaNb sous forme de 
    nombre à virgule flottante.

    2. Utilisation de _fractionalBits :

        - Rappelle-toi que _fixComaNb est en virgule fixe. Pour obtenir la valeur en flottant, 
        tu dois diviser cette valeur par 2^fractionalBits.
        - Pour ton cas, comme tu as défini _fractionalBits à 8, cela signifie que tu devras 
        diviser par 2^8 (donc 256).

Pourquoi faire un Cast ?
1. Prévenir la Division Entière :

    - En C++, lorsque tu effectues une division entre deux entiers, le résultat est aussi un 
    entier. Par exemple, si _fixComaNb est 5, alors 5 / 256 donnerait 0 (car en division entière,
    les décimales sont tronquées).
    - En faisant le cast de _fixComaNb en float, tu te assures que la division se fait entre un 
    float et un int. Cela signifie que le calcul est effectué dans le domaine flottant, 
    permettant de conserver les valeurs décimales.

2. Maintien de la Précision :

    - En utilisant (float)_fixComaNb, tu évites toute perte de précision qui pourrait survenir 
    si tu laissais les deux opérandes comme des entiers. Cela garantit que tu obtiens le 
    résultat flottant attendu.
*/

int Fixed::toInt( void ) const {
    return _fixComaNb >> _fractionalBit; // Décalage à droite pour récupérer la partie entière.
}

/*
EXPLICATIONS : 
1. Comprendre l'objectif de toInt() :

    - Cette méthode doit convertir la valeur de _fixComaNb, qui est stockée en virgule fixe, 
    en un entier.
2. Considérer le Type de Donnée :

    - _fixComaNb est de type int. Pour obtenir un entier à partir de cette valeur, il te suffit 
    de faire un cast explicite vers int.
    - Cela signifie que tu dois simplement retourner la valeur de _fixComaNb sous forme d'entier. 
    Le cast vers int va tronquer la partie décimale (ce qui est approprié dans ce cas).
*/

std::ostream& operator<<(std::ostream& nb, const Fixed& other) {
   nb << other.toFloat(); // Insère la valeur flottante dans le flux (nb)
   return nb; // Retourne le flux pour permettre le chaînage
}
/*
insère une représentation en virgule flottante du nombre à virgule fixe dans le 
flux de sortie (objet output stream) passé en paramètre.
*/


/*
EXPLICATIONS FLOAT CONSTRUCTOR :

Décomposition de la Fonction
1. Signature de la Fonction :

- Fixed::Fixed(const float float_nb): Il s'agit du constructeur de la classe Fixed qui prend 
un paramètre de type flottant float_nb. Ce paramètre représente la valeur flottante que nous 
voulons convertir en virgule fixe.

2. Affichage d'un Message

3. Conversion de la Valeur Flottante en Virgule Fixe :

La ligne suivante est celle qui fait le travail principal :

this->_fixComaNb = (int)roundf(float_nb * (1 << _fractionalBit));

- Explication de cette ligne : float_nb * (1 << _fractionalBit):
    > (1 << _fractionalBit) effectue un décalage de bits à gauche de 1 par _fractionalBit positions. 
    Par exemple, si _fractionalBit est 8, alors 1 << 8 devient 256, ce qui correspond à 2^8.

    > En multipliant float_nb par ce résultat, nous convertissons la valeur flottante en une 
    valeur qui correspond à la représentation en virgule fixe. Cela signifie que nous déplaçons 
    la virgule (ou le point) vers la droite pour obtenir la valeur entière qui sera stockée dans 
    _fixComaNb.
- roundf(...): 
    > La fonction roundf arrondit la valeur résultante à l'entier le plus proche. Cela est 
    important pour éviter toute perte d'information due à la conversion de flottant à entier.
- (int): 
    > Enfin, nous castons le résultat de roundf à un entier (int). C'est ce qui est réellement 
    stocké dans _fixComaNb, car la représentation en virgule fixe doit être un entier.

Pourquoi ces Étapes ?
- Décalage de Bits : En utilisant le décalage de bits, nous obtenons la puissance de 2 qui 
détermine la précision de notre valeur en virgule fixe. Plus le nombre de bits fractionnaires 
est grand, plus la précision est élevée.

- Arrondi : La conversion de flottant à entier peut entraîner une perte d'information. 
En arrondissant d'abord la valeur flottante avant de la convertir, nous garantissons que le 
résultat soit le plus précis possible.

- Stockage dans _fixComaNb : _fixComaNb est l'attribut privé qui stocke la valeur en virgule 
fixe de l'objet. C'est là que nous devons mettre la valeur convertie.

Résumé
Dans l'ensemble, ce constructeur effectue la conversion d'un nombre flottant en une valeur en 
virgule fixe de manière précise et efficace. Il utilise un décalage de bits pour ajuster la 
valeur et un arrondi pour s'assurer que la conversion ne cause pas de pertes significatives 
d'information. Grâce à ce mécanisme, la classe Fixed peut maintenant représenter des valeurs 
en virgule fixe à partir de nombres flottants.
*/