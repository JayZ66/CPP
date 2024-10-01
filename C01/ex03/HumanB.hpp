/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:02:03 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 18:46:44 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class   Weapon;

class HumanB
{
private:
    std::string _name;
    Weapon  *_weapon;
public:
    HumanB(std::string p_name); // Check if necessary to create a private attribut when in constructor.
    ~HumanB();
    void    attack();
    void    setWeapon( Weapon &p_weapon );
};

