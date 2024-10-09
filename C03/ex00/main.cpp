/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:29:36 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/08 18:10:15 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	clapTrapA("JayZ");

	clapTrapA.attack("Teddix");
	clapTrapA.takeDamage(5);
	clapTrapA.getStatus();
	clapTrapA.beRepaired(2);
	clapTrapA.getStatus();

	return 0;
}
