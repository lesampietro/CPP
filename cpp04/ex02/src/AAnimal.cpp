/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/27 00:05:20 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << RST << "AAnimal of type " << std::endl;
	std::cout << BLUE << _type;
	std::cout << RST << " created." << std::endl;
}

AAnimal::AAnimal(std::string _type) {
	std::cout << BLUE << _type;
	std::cout << RST << " created." << std::endl;
}


AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal copy assignment operator called.\n" << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << BLUE << "AAnimal" << RST;
	std::cout << " destructor called.\n" << std::endl;
}

std::string	AAnimal::getType() const {
	return this->_type;
}
