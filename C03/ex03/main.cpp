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
	DiamondTrap	diamondTrap("Diamond");
	diamondTrap.attack("Flo");
	diamondTrap.whoAmI();
	
	
	return 0;
}