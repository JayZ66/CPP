/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:53:21 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/03 18:04:30 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ClapTrap;

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap( void );
	ScavTrap( std::string _pname );
	~ScavTrap();
	ScavTrap( const ClapTrap& other);
	ScavTrap& operator=( const ScavTrap& other);
};
