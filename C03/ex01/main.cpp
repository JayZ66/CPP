/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:36 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/08 18:12:50 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	clapTrap("JayZ");
	ScavTrap	scavTrap("Teddix");

	clapTrap.attack("Teddix");
	clapTrap.takeDamage(5);
	clapTrap.getStatus();
	scavTrap.getStatus();
	
	scavTrap.attack("JayZ");
	clapTrap.beRepaired(2);
	scavTrap.guardGate();
	clapTrap.getStatus();
	scavTrap.getStatus();
	
	return 0;
}