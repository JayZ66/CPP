/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:30:10 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/04 15:18:02 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

 ClapTrap::ClapTrap( void ) {}

ClapTrap::ClapTrap( std::string _pname, int _pHitPoints, int _pEnergyPoints, int _pAttackDamage)
{
    _name = _pname;
    _hitPoints = _pHitPoints;
    _energyPoints = _pEnergyPoints;
    _attackDamage = _pAttackDamage;
    std::cout << "Default constructor called, ClapTrap name is " << _name << ", it has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called to destroy ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) {
    std::cout << "Actual ClapTrap object copied into a new ClapTrap object !" << std::endl;
    *this = other;
}


ClapTrap& ClapTrap::operator=( const ClapTrap& other) {
    std::cout << "All values into actual ClapTrap object has been copied to the new ClapTrap object !" << std::endl;
    if (this != &other) {
        this->_name = other.getName();
        this->_attackDamage = other.getAttackDammage();
        this->_energyPoints = other.getEnergyPoints();
        this->_hitPoints = other.getHitPoints();
    }
    return *this;
}

std::string ClapTrap::getName() const {
    return _name;
}

int         ClapTrap::getHitPoints() const {
    return _hitPoints;
}

int         ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

int         ClapTrap::getAttackDammage() const {
    return _attackDamage;
}


void    ClapTrap::attack(const std::string& target) {
    if (this->getHitPoints() <= 0)
         std::cout << "ClapTrap " << _name << " is already destroyed, cannot attack anymore !" << std::endl;
    else if (this->getEnergyPoints() > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " has " << _energyPoints << " energy points after this attack." << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot attack its target as it has " << _energyPoints << " energy points !" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is already destroyed, cannot take more damage !" << std::endl;
    else {
        std::cout << "ClapTrap " << _name << " took "<< amount << " points of damage !" << std::endl;
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points after taking damage." << std::endl;
    }
}

/*
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
*/
void    ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is already destroyed, cannot be repaired !" << std::endl;
    else if (_energyPoints > 0) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repairing itself, and have now " << _hitPoints << " hit points and " << _energyPoints << " energy points !" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot repairing itself as it has " << _energyPoints << " energy points !" << std::endl;
}

void    ClapTrap::getStatus( void ) {
    std::cout << "ClapTrap " << _name << " status :" << std::endl <<  "Energy points: " << this->getEnergyPoints() << std::endl << "Hit Points: " << this->getHitPoints() << std::endl << "Damage: " << this->getAttackDammage() <<  std::endl;
   

}
