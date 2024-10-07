/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:53:21 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/04 15:16:38 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ClapTrap;

class ScavTrap : virtual public ClapTrap
{
private:
	static int savedEnergy;

public:
	ScavTrap( void );
	ScavTrap( const std::string& _pname, int _pHitPoints, int _pEnergyPoints, int _pAttackDamage );
	~ScavTrap();

	void    attack(const std::string& target);

	void	guardGate();
	void    getStatus( void );
	static int		getEnergypoints( void );
};
