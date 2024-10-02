/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:51:05 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/02 17:08:51 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed {
private:
	int _fixComaNb;
	static const int _fractionalBit;
	
public:
	Fixed( void );
	
	Fixed( const int integer);
	Fixed( const float float_nb);
	
	Fixed( const Fixed& other);
	Fixed& operator=(const Fixed& other);

	~Fixed( void );
	
	int     getRawBits( void ) const;
    void    setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

// Add this function : 
/*
• Une surcharge de l’opérateur d’insertion («) qui insère une représentation en 
virgule flottante du nombre à virgule fixe dans le flux de sortie (objet output stream)
passé en paramètre.
*/
