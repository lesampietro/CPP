/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:04 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/27 13:56:24 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	this->_brain = new Brain();
	std::cout << GREEN << _type;
	std::cout << RST << " has been created.\n" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain); // Deep copy of the new Brain
	this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		delete this->_brain; // Cleans current brain
		this->_brain = new Brain(*other._brain); // Deep copy of new Brain
		this->_type = other._type;
		AAnimal::operator=(other); // Calls for base-class operator
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "~Destroying " << GREEN;
	std::cout << "Dog" << RST << "." << std::endl;
	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << RST << ": Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}