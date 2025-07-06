/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/05 19:57:58 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value * (1 << _fractionalBits); // Move 8 bits to the left (multiply by 2^8)
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits)); // Move 8 bits to the left and round it to the nearest integer with roundf()
}

Fixed::Fixed(const Fixed &copy) : _fixedPointValue(copy._fixedPointValue) {
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{ // Check for self-assignment
		this->_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result._fixedPointValue = (this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits;
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result._fixedPointValue = (this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
	return (result);
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedPointValue++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPointValue--;
	return (temp);
}

Fixed &Fixed::min(Fixed &first, Fixed &scnd)
{
	if (first._fixedPointValue < scnd._fixedPointValue)
		return (first);
	else
		return (scnd);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &scnd)
{
	if (first._fixedPointValue < scnd._fixedPointValue)
		return (first);
	else
		return (scnd);
}

Fixed &Fixed::max(Fixed &first, Fixed &scnd)
{
	if (first._fixedPointValue > scnd._fixedPointValue)
		return (first);
	else
		return (scnd);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &scnd)
{
	if (first._fixedPointValue > scnd._fixedPointValue)
		return (first);
	else
		return (scnd);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}