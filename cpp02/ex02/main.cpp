/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/11 17:41:44 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

int main(void)
{
	Fixed a(1);
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(42.42f);
	Fixed d(b);
	Fixed e(-5.5f);

	std::cout << YELLOW << "\nTesting comparison operators" << std::endl;
	std::cout << MAGENTA << "b" << RST << " = " << b << ", ";
	std::cout << MAGENTA << "c" << RST << " = " << c << ", ";
	std::cout << MAGENTA << "d" << RST << " = " << d << std::endl;
	std::cout << "\nb > c:\t" << (b > c) << std::endl;
	std::cout << "b < c:\t" << (b < c) << std::endl;
	std::cout << "b >= c:\t" << (b >= c) << std::endl;
	std::cout << "b <= c:\t" << (b <= c) << std::endl;
	std::cout << "b == c:\t" << (b == c) << std::endl;
	std::cout << "b != c:\t" << (b != c) << std::endl;
	std::cout << "b == d:\t" << (b == d) << std::endl;

	std::cout << YELLOW << "\nTesting arithmetic operators" << std::endl;
	std::cout << MAGENTA << "a" << RST << " = " << a << ", ";
	std::cout << MAGENTA << "b" << RST << " = " << b << ", ";
	std::cout << MAGENTA << "c" << RST << " = " << c << ", ";
	std::cout << MAGENTA << "d" << RST << " = " << d << std::endl;
	std::cout << "\nb + c = " << CYAN << (b + c) << std::endl;
	std::cout << RST << "b - c = " << CYAN << (b - c) << std::endl;
	std::cout << RST << "b * c = " << CYAN << (b * c) << std::endl;
	std::cout << RST << "b / c = " << CYAN << (b / c) << std::endl;
	std::cout << RST << "a / c = " << CYAN << (a / c) << std::endl;
	std::cout << RST << "b / d = " << CYAN << (b / d) << std::endl;

	std::cout << YELLOW << "\nTesting arithmetic operations with negative numbers" << std::endl;
	std::cout << MAGENTA << "b" << RST << " = " << b;
	std::cout << ", " << MAGENTA << "e" << RST << " = " << e << std::endl;
	std::cout << "\nb + e = " << CYAN << (b + e) << std::endl;
	std::cout << RST << "b - e = " << CYAN << (b - e) << std::endl;
	std::cout << RST << "b * e = " << CYAN << (b * e) << std::endl;
	std::cout << RST << "e / b = " << CYAN << (e / b) << std::endl;

	std::cout << YELLOW << "\nTesting increment/decrement operators";
	std::cout << std::endl;
	std::cout << MAGENTA << "a" << RST << " = " << a << std::endl;
	std::cout << MAGENTA << "\n++a" << RST << " = " << ++a << std::endl;
	std::cout << "a after pre-increment = "; 
	std::cout << CYAN << a << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << MAGENTA << "a++" << RST << " = " << a++ << std::endl;
	std::cout << "a after post-increment = ";
	std::cout << CYAN << a << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << MAGENTA << "--a" << RST << " = " << --a << std::endl;
	std::cout << "a after pre-decrement = ";
	std::cout << CYAN << a << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << MAGENTA << "a--" << RST << " = " << a-- << std::endl;
	std::cout << "a after post-decrement = ";
	std::cout << CYAN << a << std::endl;

	std::cout << YELLOW << "\nTesting min and max functions" << std::endl;
	std::cout << MAGENTA << "b" << RST << " = " << b << ", ";
	std::cout << MAGENTA << "c" << RST << " = " << c << std::endl;
	std::cout << "\nmin(b, c) = " << CYAN << Fixed::min(b, c) << std::endl;
	std::cout << RST << "max(b, c) = " << CYAN << Fixed::max(b, c) << std::endl;
	std::cout << std::endl;
}

//SUBJECT MAIN
// int	main(void) {
// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;
// 	std::cout << Fixed::min(a, b) << std::endl;
// 	return 0;
// }

//ARITHMETIC OPERATION & CONVERSION DEMONSTRATION
// {
// 	std::cout << std::endl;
// 	std::cout << MAGENTA << "b" << YELLOW << " _fixedPointValue is: ";
// 	std::cout << RST << b.getRawBits() << std::endl;
// 	std::cout << MAGENTA << "c" << YELLOW << " _fixedPointValue is: ";
// 	std::cout << RST << c.getRawBits() << std::endl;
// 	Fixed res(b + c);
// 	std::cout << MAGENTA << "b + c" << YELLOW << " _fixedPointValue is: ";
// 	std::cout << RST << res.getRawBits() << std::endl;
// 	std::cout << "(b + c) / 256 = " << res << std::endl;
// 	Fixed res02(b - c);
// 	std::cout << MAGENTA << "b - c" << YELLOW << " _fixedPointValue is: ";
// 	std::cout << RST << res02.getRawBits() << std::endl;
// 	std::cout << "(b - c) / 256 = " << res02 << std::endl;
// 	Fixed res03(b * c);
// 	std::cout << MAGENTA << "b * c" << YELLOW << " _fixedPointValue is: ";
// 	std::cout << RST << res02.getRawBits() << std::endl;
// 	std::cout << "(b * c) / 256 = " << res03 << std::endl;
// 	Fixed res04(b / c);
// 	std::cout << MAGENTA << "b - c" << YELLOW << " _fixedPointValue is: ";
// 	std::cout << RST << res04.getRawBits() << std::endl;
// 	std::cout << "(b / c) / 256 = " << res04 << std::endl;
// }

// In C++, comparison operator overloading allows the standard comparison operators ( ==, !=, <, >, <=, >= ) to be defined for user-defined types (classes or structs). This enables objects of these types to be compared using familiar syntax, making code more intuitive and readable.