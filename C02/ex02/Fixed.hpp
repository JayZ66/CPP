
#pragma once

#include <iostream>
#include <cmath>

class   Fixed {
    private:
        int _fixComaNb;
        static const int _fractionalBit;

    public:
        Fixed( void );
        ~Fixed( void );

        Fixed( const int integer);
	    Fixed( const float float_nb);

        Fixed( const Fixed& other );
        Fixed &operator=( const Fixed& other );

        int    getRawBits( void ) const;
        void     setRawBits( int const raw );

        float toFloat( void ) const;
	    int toInt( void ) const;

        bool    operator>( const Fixed& other ) const; 
        bool    operator<( const Fixed& other ) const;
        bool    operator>=( const Fixed& other ) const;
        bool    operator<=( const Fixed& other ) const;
        bool    operator==( const Fixed& other ) const;
        bool    operator!=( const Fixed& other ) const;

        Fixed   operator+( const Fixed& other ); // const ??
        Fixed   operator-( const Fixed& other );
        Fixed   operator*( const Fixed& other );
        Fixed   operator/( const Fixed& other );

        Fixed   &operator++(); // Pré-incrémentation (++i > + efficace en memoire)
        Fixed   operator++(int); // Post-incrémentation (i++)
        Fixed   &operator--(); // Pré-décrémentation
        Fixed   operator--(int); // Post-décrémentation

        static  Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static  Fixed& max(Fixed &a, Fixed &b);
        static const Fixed  &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& nb, const Fixed& other);
