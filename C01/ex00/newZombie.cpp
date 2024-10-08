/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:21:19 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 11:51:48 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

// Zombie*	newZombie( std::string name ); 
// Need to allocate on the heapwith new ! + return this var.
// Zombie* ptr = new Zombie("Foo");

Zombie*	newZombie(std::string name)
{
	Zombie*	ptr_zombie = new Zombie(name);
	return ptr_zombie;
}