/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:55:02 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/01 09:55:04 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/*
L'exo consiste à créer un prog. qui prend en entrée des arguments
et les transforme en maj. pour ensuite les afficher.
Si aucun arg. n'est donnée, le prog. doit afficher un message par défaut.
*/

// int main(int argc, char **argv)
// {
// 	if (argc == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 	else if (argc > 1)
// 	{
// 		for (int i = 1; i < argc; i++)
// 		{
// 			for (int j = 0; argv[i][j]; j++)
// 			{
// 				// std::cout << std::toupper((unsigned char)argv[i][j]);
// 				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
// 			}
// 			if (i < argc - 1)
// 				std::cout << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// 	return (0);
// }

/*
Explications cast C++ : 
static_cast est un opérateur de conversion en C++ qui permet de convertir 
explicitement un type en un autre de manière sécurisée. 
Code : 
- static_cast<unsigned char> : Ce cast est fait pour que le caractère soit 
correctement interprété par std::toupper().
- static_cast<char> : Après avoir utilisé std::toupper(), tu dois caster 
son retour (un int) en char pour l'afficher correctement.
*/

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for (unsigned int j = 0; arg[j]; j++)
			{
				std::cout << static_cast<char>(std::toupper(arg[j]));
			}
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	return (0);
}
