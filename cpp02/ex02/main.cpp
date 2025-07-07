/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/06 21:52:29 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);
	Fixed e(-5.5f);

	std::cout << YELLOW << "\nTesting comparison operators" << std::endl;
	std::cout << RST << "b = " << b << ", c = " << c;
	std::cout << ", d = " << d << std::endl;
	std::cout << "\nb > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= c: " << (b >= c) << std::endl;
	std::cout << "b <= c: " << (b <= c) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;

	std::cout << YELLOW << "\nTesting arithmetic operators" << std::endl;
	std::cout << RST << "a = " << a << ", b = " << b;
	std::cout << ", c = " << c << ", d = " << d << std::endl;
	std::cout << "\nb + c = " << (b + c) << std::endl;
	std::cout << "b - c = " << (b - c) << std::endl;
	std::cout << "b * c = " << (b * c) << std::endl;
	std::cout << "a / c = " << (a / c) << std::endl;
	std::cout << "b / d = " << (b / d) << std::endl;

	std::cout << YELLOW << "\nTesting arithmetic operations with negative numbers" << std::endl;
	std::cout << RST << "b = " << b << ", e = " << e << std::endl;
	std::cout << "\nb + e = " << (b + e) << std::endl;
	std::cout << "b - e = " << (b - e) << std::endl;
	std::cout << "b * e = " << (b * e) << std::endl;
	std::cout << "e / b = " << (e / b) << std::endl;

	std::cout << YELLOW << "\nTesting increment/decrement operators";
	std::cout << RST << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "\n++a = " << ++a << std::endl;
	std::cout << "a after pre-increment = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a after post-increment = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a after pre-decrement = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a after post-decrement = " << a << std::endl;

	std::cout << YELLOW << "\nTesting min and max functions" << std::endl;
	std::cout << RST << "b = " << b << ", c = " << c << std::endl;
	std::cout << "\nmin(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
	std::cout << std::endl;
}

//SUBJECT TESTS
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

// In C++, comparison operator overloading allows the standard comparison operators ( ==, !=, <, >, <=, >= ) to be defined for user-defined types (classes or structs). This enables objects of these types to be compared using familiar syntax, making code more intuitive and readable.