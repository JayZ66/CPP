/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:56 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/02 19:16:40 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ClapTrap
{
private:
    std::string _name; // Passed as param. in constructor.
    int _hitPoints; // health of claptrap, need to be init to 10
    int _energyPoints; // init to 10
    int _attackDamage; // init to 0
    
public:
    ClapTrap( void );
    ClapTrap( std::string _pname );
    ~ClapTrap();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap( std::string _pname ) : _name(_pname), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}
