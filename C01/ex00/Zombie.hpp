/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:21:03 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 14:44:17 by jeguerin         ###   ########.fr       */
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
	
	void    announce( void );
	// Zombie( void );
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif