/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 15:03:03 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
	this->_type = "WrongCat";
	std::cout << MAGENTA << _type;
	std::cout << RST << " created.\n" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	this->_type = copy._type;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << MAGENTA << _type;
	std::cout << RST << " has been ~destroyed." << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << MAGENTA << this->_type;
	std::cout << RST << ": Meow Meow..." << std::endl;
}
