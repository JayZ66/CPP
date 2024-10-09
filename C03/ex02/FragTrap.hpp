/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:48:31 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/08 19:12:45 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
private:

public:
    FragTrap( void );
    FragTrap( const std::string& _pname );
    FragTrap( const FragTrap& other);
    FragTrap& operator=( const FragTrap& other);
    ~FragTrap();

    void    highFivesGuys( void );
    void    getStatus( void );
};