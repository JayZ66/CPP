/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:16:09 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 15:19:37 by jeguerin         ###   ########.fr       */
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
	Zombie(std::string p_name);
	~Zombie( void );

	void	setZombieName(std::string p_name); // Necessary because we don't get the name with the tab.
	void    announce( void );
	Zombie( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif