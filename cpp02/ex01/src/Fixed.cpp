/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/01 19:51:12 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = roundf(_value * 256);
}

Fixed::Fixed(const float _value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(_value * 256);
}

Fixed::Fixed(const Fixed &copy) : _fixedPointValue(copy._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

// Fixed &Fixed::operator<<(int _fixedPointValue)
// {
// 	std::cout << _fixedPointValue << std::endl;
// 	return ;
// }

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// int toInt(void) const;
// float toFloat(void) const;

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}