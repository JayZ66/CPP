/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:56:53 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 18:32:25 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class   Weapon;

class HumanA
{
private:
    std::string _name;
    Weapon&     _weapon;
    
public:
    HumanA(std::string p_name, Weapon& p_weapon);
    ~HumanA();
    void    attack();
};

/*
Dans ton cas, comme tu veux que HumanA garde en mémoire le nom et l'arme 
pour la méthode attack(), tu dois les enregistrer comme des attributs privés de la classe.

Voici un résumé de ce que tu as fait :

Attributs privés :

_name pour stocker le nom de l'humain.
weapon pour garder une référence à l'objet Weapon qui est passé au constructeur.
Constructeur :

Prend en paramètres un nom (de type std::string) et une référence à un objet Weapon.
Destructeur :

Bien que tu ne l'aies pas encore défini, tu n'auras pas besoin d'y mettre quoi 
que ce soit de spécial, à moins que tu ne fasses des opérations spécifiques à la destruction.

Méthode attack() :

C'est là que tu vas utiliser _name et weapon pour afficher le message d'attaque.

*/

