/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:57:07 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 17:43:49 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

// He has a ref as it's the first one and get a weapon.
// As we want to modify the weapon outside HumanA instance, we should take a ref.

HumanA::HumanA(std::string p_name, Weapon& p_weapon) : _name(p_name), _weapon(p_weapon) {}


HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

/*
Dans le constructeur de HumanA, tu dois passer une référence à l'objet Weapon.
Le type de la variable que tu dois envoyer est une référence à l'objet Weapon,
c'est-à-dire un Weapon&.

Cela te permet de lier l'arme de HumanA à une instance existante de Weapon en
dehors de la classe. Ainsi, toute modification de l'arme sera immédiatement
reflétée dans HumanA puisqu'il n'a pas sa propre copie de l'arme, mais bien
une référence à l'arme externe.

Explications : 
Initialisation des attributs :

Tu utilises une liste d'initialisation pour assigner p_name à _name et p_weapon à weapon.
C’est la bonne approche pour initialiser des attributs.
Passage par référence :

En passant Weapon& p_weapon, tu t'assures que HumanA utilise la même instance de Weapon
que celle passée en argument, ce qui est exactement ce que tu veux.
*/
