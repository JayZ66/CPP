/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:21:07 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 11:45:36 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie(std::string p_name) : name(p_name) + str pour la creation.
// ~Zombie( void ); + std::cout << "Zombie detruit: " << _name << std::endl;

Zombie::Zombie(std::string p_name) : _name(p_name) {}

 Zombie::~Zombie( void )
 {
    std::cout << "Destroying zombie: " << _name << std::endl;
 }

 void    Zombie::announce( void )
 {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
 }
