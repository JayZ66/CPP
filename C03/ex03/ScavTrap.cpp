/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:03:32 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/04 15:17:55 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Calling ClapTrap constructor to init attributes and then overwrite with ScavTrap data.
// We call ClapTrap constructor to init the name.
ScavTrap::ScavTrap( const std::string& _pname) : ClapTrap(_pname)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Default constructor called, ScavTrap name is " << _name << ", it has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage." << std::endl;
}
// Then we can init ClapTrap attributes as they are protected and not private.
// If they were private, we'll need to use public setter ClapTrap functions to access and init it.

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called to destroy ScavTrap " << _name << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (this->getHitPoints() <= 0)
        std::cout << "ScavTrap " << _name << " is already destroyed, cannot attack anymore !" << std::endl;
    else if (this->getEnergyPoints() > 0) {
        this->_energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _name << " cannot attack its target as it has " << _energyPoints << " energy points !" << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode !" << std::endl;
}

void    ScavTrap::getStatus( void ) {
    std::cout << "ScavTrap " << _name << " status :" << std::endl <<  "Energy points: " << this->getEnergyPoints() << std::endl << "Hit Points: " << this->getHitPoints() << std::endl << "Damage: " << this->getAttackDammage() <<  std::endl;

}
