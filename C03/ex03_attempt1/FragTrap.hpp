/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:48:31 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/04 15:54:12 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap
{
private:
    /* data */
public:
    FragTrap( void );
    FragTrap( const std::string& _pname, int _pHitPoints, int _pEnergyPoints, int _pAttackDamage );
    ~FragTrap();

    void    highFivesGuys( void );
    void    getStatus( void );
};