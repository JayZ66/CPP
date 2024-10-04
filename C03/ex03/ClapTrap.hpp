/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:56 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/04 12:38:40 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
protected:
    std::string _name; // Passed as param. in constructor.
    int _hitPoints; // health of claptrap, need to be init to 10
    int _energyPoints; // init to 10
    int _attackDamage; // init to 0
    
public:
    ClapTrap( void );
    ClapTrap( std::string _pname );
    ClapTrap( const ClapTrap& other);
    ClapTrap& operator=( const ClapTrap& other);
    ~ClapTrap();

    std::string getName() const;
    int         getHitPoints() const;
    int         getEnergyPoints() const;
    int         getAttackDammage() const;
    void        getStatus();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

// std::ostream& operator<<(std::ostream& out, ClapTrap& other) 
// => In order to easily print our class !
