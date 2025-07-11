
#include "includes/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);

	std::cout << MAGENTA << "\na" << YELLOW << " raw _value is: ";
	std::cout << RST << a.getRawBits() << std::endl;
	std::cout << MAGENTA << "b" << YELLOW << " raw _value is: ";
	std::cout << RST << b.getRawBits() << std::endl;
	std::cout << MAGENTA << "c" << YELLOW << " raw _value is: ";
	std::cout << RST << c.getRawBits() << std::endl;
	std::cout << MAGENTA << "d" << YELLOW << " raw _value is: ";
	std::cout << RST << d.getRawBits() << std::endl;

	std::cout << "\na is " << a << "\tas float" << std::endl;
	std::cout << "b is " << b << "\t\tas float" << std::endl;
	std::cout << "c is " << c << "\tas float" << std::endl;
	std::cout << "d is " << d << "\t\tas float" << std::endl;
	
	std::cout << "\na is " << a.toInt() << "\tas integer" << std::endl;
	std::cout << "b is " << b.toInt() << "\t\tas integer" << std::endl;
	std::cout << "c is " << c.toInt() << "\t\tas integer" << std::endl;
	std::cout << "d is " << d.toInt() << "\t\tas integer\n" << std::endl;
	
	return 0;
}


// SUBJECT MAIN
// int main( void ) {
// Fixed a;
// Fixed const b( 10 );
// Fixed const c( 42.42f );
// Fixed const d( b );
// a = Fixed( 1234.4321f );
// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;
// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// return 0;
// }