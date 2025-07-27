/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:18:31 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/27 13:56:27 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	this->_brain = new Brain();
	std::cout << GREEN << this->_type;
	std::cout << RST << " has been created.\n" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain); //Deep copy of the new Brain
	this->_type = copy._type;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		delete this->_brain; // Cleans current brain
		this->_brain = new Brain(*other._brain); // Deep copy of new Brain
		this->_type = other._type;
		AAnimal::operator=(other); // Calls for base-class operator
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "~Destroying " << GREEN;
	std::cout << this->_type << RST << "." << std::endl; 
	delete this->_brain;
}

void	Cat::makeSound() const {
	std::cout << RST << ": Meow Meow..." << std::endl;
}

Brain*	Cat::getBrain() const {
	return _brain;
}