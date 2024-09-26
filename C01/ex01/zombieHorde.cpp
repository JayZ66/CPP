/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:16:53 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 15:39:35 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie* zombieHorde( int N, std::string name );

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *ptr = new Zombie[N]; // Creating N Zombie objects
    for (int i = 0; i < N; i++)
        ptr[i].setZombieName(name);
    return ptr;
}

// Set is useful here as we're not sending the Zombie's name to the constructor !