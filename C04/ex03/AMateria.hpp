/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:00 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/10 11:04:57 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria(std::string const& type);
    virtual ~AMateria();
    AMateria( const AMateria& other );
    AMateria& operator=( const AMateria& other );

    std::string const& getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0; // Need to be implemented in other classes (dérivées) to return a new material instance. 
    virtual void use(ICharacter& target);
};