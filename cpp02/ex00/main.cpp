/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/12 15:13:58 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

int main(void) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	std::cout << std::endl;
	std::cout << MAGENTA << "a" << YELLOW << "_value is: ";
	std::cout << RST << a.getRawBits() << std::endl;
	std::cout << GREEN << "b" << YELLOW << "_value is: ";
	std::cout << RST << b.getRawBits() << std::endl;
	std::cout << CYAN << "c" << YELLOW << "_value is: ";
	std::cout << RST << c.getRawBits() << std::endl;
	std::cout << std::endl;

	b.setRawBits(42);
	c = b;

	std::cout << MAGENTA << "a" << YELLOW << "_value is: ";
	std::cout << RST << a.getRawBits() << std::endl;
	std::cout << GREEN << "b" << YELLOW << "_value is: ";
	std::cout << RST << b.getRawBits() << std::endl;
	std::cout << CYAN << "c" << YELLOW << "_value is: ";
	std::cout << RST << c.getRawBits() << std::endl;
	std::cout << std::endl;

	return 0;
}
