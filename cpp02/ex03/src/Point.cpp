/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:53:48 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/05 21:07:11 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float first, const float scnd) : _x(Fixed(first)), _y(Fixed(scnd)) {
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	// Assignment operator is disabled because members are immutable
	return (*this);
}

Fixed	Point::getX() const {
	return (this->_x);
}

Fixed	pthread_rwlock_init::getY() const {
	return (this->_y);
}

Point::~Point() {
	std::cout << "~Destructor called" << std::endl;
}