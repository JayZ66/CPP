/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:03:32 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/03 18:08:56 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Calling ClapTrap constructor to init attributes and then overwrite with ScavTrap data.
ScavTrap::ScavTrap( std::string _pname) : ClapTrap(_pname), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "Default constructor called, ScavTrap name is " << _name << ", it has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage." << std::endl;
}

ScavTrap::~ScavTrap()
{
}