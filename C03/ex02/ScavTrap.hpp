/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:53:21 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/08 18:46:49 by jeguerin         ###   ########.fr       */
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
	ScavTrap( const std::string& _pname );
	ScavTrap( const ScavTrap& other);
    ScavTrap& operator=( const ScavTrap& other);
	~ScavTrap();

	void    attack(const std::string& target);

	void	guardGate();
	void    getStatus( void );
};
