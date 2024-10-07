/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:48:47 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/04 15:52:39 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Antoine", 100, 100, 30) {}

FragTrap::FragTrap( const std::string& _pname, int _pHitPoints, int _pEnergyPoints, int _pAttackDamage) : ClapTrap(_pname, _pHitPoints, _pEnergyPoints, _pAttackDamage)
{
    // _hitPoints = 100;
    // _energyPoints = 100;
    // _attackDamage = 30;
    std::cout << "Default constructor called, FragTrap name is " << _name << ", it has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called to destroy FragTrap " << _name << std::endl;
}

void    FragTrap::getStatus( void )
{
    std::cout << "FragTrap " << _name << " status :" << std::endl <<  "Energy points: " << this->getEnergyPoints() << std::endl << "Hit Points: " << this->getHitPoints() << std::endl << "Damage: " << this->getAttackDammage() <<  std::endl;
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << _name << " asks for a positive high five !" << std::endl;
}