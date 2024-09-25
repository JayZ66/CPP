/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:21:03 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/25 17:53:23 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>

class   Zombie {
private:
	std::string _name;

public:
	// Zombie(std::string p_name) : name(p_name) + str pour la creation.
	// ~Zombie( void ); + std::cout << "Zombie detruit: " << _name << std::endl;

	// Contact() : _lastname(""), _firstname(""), _nickname(""), _phonenumber(""), _darkestsecret("") {}
	// Contact(std::string p_lastname, std::string p_firstname, std::string p_nickname, std::string p_phonenumber, std::string p_darkestsecret);
	// ~Contact(void);

	// std::string getLastname() const;

	// void    setLastname(std::string p_lastname);
	void    announce( void );
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif