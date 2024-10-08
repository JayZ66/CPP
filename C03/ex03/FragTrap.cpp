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

FragTrap::FragTrap( void ) : ClapTrap() {}

FragTrap::FragTrap( const FragTrap& other) {
    *this = other;
}

FragTrap& FragTrap::operator=( const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::FragTrap( const std::string& _pname ) : ClapTrap(_pname)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
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