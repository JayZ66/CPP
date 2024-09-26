/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:56:31 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 18:01:33 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class   Weapon {
private:
	std::string _type;

public:
	Weapon( std::string p_type );
	~Weapon( void );

	const std::string&  getType( void ); // Necessary because we don't get the name with the tab.
    void    setType(std::string p_type); // Let's see if we can use aref with the main ? (ask gpt)
};
