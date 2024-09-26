/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:16:02 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 15:28:56 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string p_name) : _name(p_name) {}


Zombie::~Zombie( void )
{
    std::cout << "Destroying zombie: " << _name << std::endl;
}

void	Zombie::setZombieName(std::string p_name)
{
    _name = p_name;
}

 void    Zombie::announce( void )
 {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
 }

 Zombie::Zombie( void ) {}
 