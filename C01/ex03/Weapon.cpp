/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:56:38 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 18:30:28 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string p_type ) : _type(p_type) {}
Weapon::~Weapon( void ) {}

void	Weapon::setType(std::string p_type)
{
	_type = p_type;
}

const std::string& Weapon::getType()
{
    return (_type); // ne pas mettre this ?
}

/*
RESUME POINTEUR VERS AUTRE CLASSE :
Voici un résumé :

1.Accéder aux méthodes : 
Pour appeler des méthodes sur l'objet pointé par le pointeur,
tu utilises l'opérateur ->. Par exemple, si tu as un pointeur p_weapon qui pointe vers
un objet de la classe Weapon, tu peux appeler une méthode de cet objet comme ceci :

p_weapon->setType("new type");

2.Accéder aux attributs : 
Si tu veux accéder directement à un attribut de l'objet pointé, tu peux également 
utiliser ->. 
Par exemple :

std::cout << p_weapon->getType() << std::endl;

3.Utiliser des setters/getters : 
Tu peux passer le pointeur dans des méthodes de la classe concernée pour changer ou 
obtenir des valeurs, mais généralement, tu n'as pas besoin de déréférencer si tu utilises 
l'opérateur ->.

4.Déréférencement : 
Comme tu l'as dit, le déréférencement (*p_weapon) est utile si tu veux modifier directement 
l'objet pointé, mais dans la plupart des cas où tu accèdes simplement à des méthodes ou des 
attributs, l'utilisation de -> est plus courante et claire.

*/