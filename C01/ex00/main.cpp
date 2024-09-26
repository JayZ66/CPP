/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:20:18 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 14:14:35 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "There is no zombie here !" << std::endl;
	else if (argc > 2)
		std::cout << "Enter the name of one Zombie !" << std::endl;
	else
	{
		std::string zombie = argv[1];
		Zombie*	ptr;
		ptr = newZombie(zombie);
		ptr->announce();
		delete	ptr;
		randomChump(zombie);
	}
	return 0;
}