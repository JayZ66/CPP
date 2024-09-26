/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:57:19 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 18:52:48 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

// He has a pointer as he can have a weapon or not.

HumanB::HumanB(std::string p_name) : _name(p_name),  _weapon(NULL) {}

// Means that there is no weapon for HumanB at the beginning

HumanB::~HumanB()
{
}

/*
Utiliser une référence pour obtenir la « vraie » valeur d’un objet et ensuite 
assigner son adresse à ton pointeur est la bonne approche.
*/
void    HumanB::setWeapon( Weapon &p_weapon ) // Giving a ref to get the real value and not a copy.
{
    _weapon = &p_weapon; // Giving the add. of the class we want point to.
}

void    HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
/*
Affectation d'un pointeur : 
Si tu souhaites simplement assigner le pointeur,
tu devrais affecter directement _weapon au pointeur passé en paramètre.
Cela signifie que tu veux que _weapon pointe vers le même objet Weapon que p_weapon.


Tu veux que l'attribut privé _weapon de la classe HumanB pointe vers l'instance 
de la classe Weapon que tu souhaites utiliser.

- Détails
Assignation de l'adresse : Dans ta fonction setWeapon, tu devrais simplement assigner 
le pointeur passé en paramètre à _weapon. Cela signifie que _weapon contiendra 
l'adresse de l'objet Weapon que tu passes à la méthode, ce qui te permettra d'accéder 
aux méthodes de cet objet plus tard, comme dans la méthode attack().

- Accès à l'objet Weapon
Accès à l'arme : Quand tu veux accéder aux méthodes ou attributs de l'objet
Weapon pour une instance de HumanB, tu peux utiliser _weapon, qui contient l'adresse de
l'objet Weapon. Par exemple, tu pourrais faire quelque chose comme _weapon->getType() pour
obtenir le type de l'arme.

- Déréférencement
Quand utiliser le déréférencement : Tu utiliserais le déréférencement si tu veux manipuler
l'objet lui-même plutôt que de juste pointer vers lui. Par exemple, si tu veux 
modifier directement les attributs de l'objet Weapon :

_weapon->setType("new type"); // Utilisation du pointeur

ou

(*_weapon).setType("new type"); // Déréférencement pour accéder à l'objet

Dans ce cas, _weapon est un pointeur vers un objet Weapon, et en le déréférençant,
tu accèdes à l'objet Weapon lui-même pour effectuer des opérations directement sur lui.

*/

/*
If we do this : 
void HumanB::setWeapon(Weapon p_weapon)
{
    _weapon = &p_weapon; // Ceci ne fonctionne pas !
}
Quand tu passes un objet (comme Weapon) par valeur, une copie de cet objet est créée. 
Cela signifie que tu obtiens un nouvel objet, distinct de l’original, qui ne partage 
pas la même adresse mémoire.
Quand cette fonction se termine, p_weapon est détruit et sa mémoire est libérée. 
Par conséquent, _weapon pointerait vers une adresse de mémoire qui n'est plus valide, 
ce qui entraînerait un comportement indéfini si tu essayais d'utiliser _weapon après cela.

*/


