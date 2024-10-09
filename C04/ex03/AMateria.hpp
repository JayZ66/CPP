/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:00 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/09 17:35:10 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AMateria
{
    protected:
    //TO ADD

    public:
    AMateria(std::string const& type);
    ~AMateria();
    AMateria( const AMateria& other );
    AMateria& operator=( const AMateria& other );
    
    // TO ADD

    std::string const& getType() const = 0; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0; // Need to be virtual pure ??
};