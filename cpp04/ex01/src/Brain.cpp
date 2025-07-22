/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:59:43 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 17:01:37 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_ideas = other._ideas;
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "~Destroying " << GREEN;
	std::cout << _type << RST << "." << std::endl;
}

void	Brain::makeSound() const {
	std::cout << GREEN << this->_type;
	std::cout << RST << ": Meow Meow..." << std::endl;
}