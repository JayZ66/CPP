/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:36 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/04 15:15:17 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	// ClapTrap	clapTrap("JayZ");
	// ScavTrap	scavTrap("Teddix");
	// FragTrap	fragTrap("Antoine");

	// clapTrap.attack("Teddix");
	// clapTrap.takeDamage(5);
	// clapTrap.getStatus();
	// scavTrap.getStatus();
	// fragTrap.getStatus();
	// scavTrap.attack("JayZ");
	// clapTrap.beRepaired(2);
	// scavTrap.guardGate();
	// fragTrap.highFivesGuys();
	// clapTrap.getStatus();
	// scavTrap.getStatus();
	// fragTrap.getStatus();

	DiamondTrap	diamondTrap("Diamond", 2000, 213, 67);
	diamondTrap.attack("Flo");
	diamondTrap.whoAmI();
	
	
	return 0;
}