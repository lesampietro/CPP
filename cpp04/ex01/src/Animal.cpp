/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/26 19:45:07 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << BLUE << _type;
	std::cout << RST << " created." << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << BLUE << _type;
	std::cout << RST << " created." << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type) {
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << BLUE << _type << RST;
}

void	Animal::makeSound() const {
	std::cout << BLUE << this->_type;
	std::cout << RST << ": GrRrRrrr..." << std::endl;
}

std::string	Animal::getType() const {
	return this->_type;
}
