/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:15:49 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 15:38:16 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// int	main(int argc, char **argv)
// {
// 	if (argc == 1)
// 		std::cout << "There is no zombie here !" << std::endl;
// 	// else if (argc > 2)
// 	// 	std::cout << "Enter the name of one Zombie !" << std::endl;
// 	else
// 	{
// 		std::string	nameZombie = argv[1];
// 		Zombie	*Horde;
// 		Horde = zombieHorde(argc - 1, nameZombie);
// 		for (int i = 0; i < argc - 1; i++)
// 			Horde[i].announce();
// 		delete[] Horde;
// 	}
// }

int	main()
{
	int	n = 10;
	std::string	nameZombie = "Teddix";
	Zombie	*Horde;
	Horde = zombieHorde(n, nameZombie);
	for (int i = 0; i < n; i++)
		Horde[i].announce();
	delete[] Horde;
}
