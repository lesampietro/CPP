/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 16:25:53 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongDog.hpp"

WrongDog::WrongDog() {
	this->_type = "WrongDog";
	std::cout << MAGENTA << _type;
	std::cout << RST << " created.\n" << std::endl;
}

WrongDog::WrongDog(const WrongDog &copy) {
	std::cout << "WrongDog copy constructor called." << std::endl;
	this->_type = copy._type;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
	std::cout << "WrongDog copy assignment operator called." << std::endl;
	std::cout << std::endl;
	if (this != &other)
	{ // Check for self-assignment
		this->_type = other._type;
	}
	return (*this);
}

WrongDog::~WrongDog() {
	std::cout << MAGENTA << _type;
	std::cout << RST << " has been ~destroyed." << std::endl;
}

void	WrongDog::makeSound() const {
	std::cout << MAGENTA << this->_type;
	std::cout << RST << ": Woof! Woof!" << std::endl;
}
