/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:36 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/03 16:48:47 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	clapTrapA("JayZ");
	// ClapTrap	clapTrapB("Teddix");

	clapTrapA.attack("Teddix");
	clapTrapA.takeDamage(5);
	clapTrapA.getStatus();
	clapTrapA.beRepaired(2);
	clapTrapA.getStatus();
	// clapTrapB.takeDamage(3);
	// clapTrapB.beRepaired(2);
	
	// clapTrapB.attack("JayZ");
	// clapTrapA.takeDamage(4);
	// clapTrapA.beRepaired(3);

	// clapTrapB.attack("JayZ");
	// clapTrapA.takeDamage(9);
	// clapTrapA.attack(10);
	return 0;
} // What to do with attack damage ??