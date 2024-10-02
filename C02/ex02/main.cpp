
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// int main() {
//     Fixed a(0);         // 0
//     Fixed b(1);         // 1
//     Fixed c(10.1016f);  // 10.1016
//     Fixed d(0.00390625f); // 0.00390625

//     std::cout << "a: " << a << std::endl; // 0
//     std::cout << "b: " << b << std::endl; // 1
//     std::cout << "d: " << d << std::endl; // 0.00390625

//     std::cout << "a + d: " << (a + d) << std::endl; // 0.00390625
//     std::cout << "d + d: " << (d + d) << std::endl; // 0.0078125
//     std::cout << "b + d: " << (b + d) << std::endl; // 1.00390625
//     std::cout << "b * d: " << (b * d) << std::endl; // 0.00390625
//     std::cout << "c: " << c << std::endl; // 10.1016
//     std::cout << "c * d: " << (c * d) << std::endl; // Devrait être correct
//     return 0;
// }
