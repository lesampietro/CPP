/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:18:31 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/25 14:40:50 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << GREEN << _type;
	std::cout << RST << " created.\n" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy._type;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_type = other._type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "~Destroying " << GREEN;
	std::cout << _type << RST << "." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << GREEN << this->_type;
	std::cout << RST << ": Meow Meow..." << std::endl;
}