/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:04 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/25 14:40:43 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << GREEN << _type;
	std::cout << RST << " created.\n" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other)
	{ // Check for self-assignment
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "~Destroying " << GREEN;
	std::cout << _type << RST << "." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << GREEN << this->_type;
	std::cout << RST << ": Woof! Woof!" << std::endl;
}