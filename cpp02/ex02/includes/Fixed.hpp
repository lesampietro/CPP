/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/04 19:38:08 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	Fixed	&operator++(int _fixedPointValue) const;
	Fixed	&operator--(int _fixedPointValue) const;
	// Fixed	&operator(const Fixed &other) const;
	// Fixed	&operator(const Fixed &other) const;
};

	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

	// The 4 arithmetic operators: +, -, *, and /
	
	// The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
	
	// A static member function min that takes two references to fixed - point numbers as parameters, and returns a reference to the smallest one.
	// A static member function min that takes two references to constant fixed - point numbers as parameters, and returns a reference to the smallest one.
	// A static member function max that takes two references to fixed - point numbers as parameters, and returns a reference to the greatest one.
	// A static member function max that takes two references to constant fixed - point numbers as parameters, and returns a reference to the greatest one.