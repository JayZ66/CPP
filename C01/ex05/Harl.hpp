/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:07:11 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/02 18:07:15 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Harl {
    private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

    public:
    void    complain( std::string level );
};