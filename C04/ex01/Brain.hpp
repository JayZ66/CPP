
#pragma once

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain( void );
        Brain( const Brain& other );
        Brain& operator=( const Brain& other );
        ~Brain();

};
