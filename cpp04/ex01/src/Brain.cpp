/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:59:43 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 19:44:31 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << BLUE << "Brain" << RST << " created." << std::endl;
	int i = 0;

	while (i < 100) {
		this->_ideas[i] = "Random thought";
		i++;
	}
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	int i = 0;

	while (i < 100) {
		this->_ideas[i] = copy._ideas[i];
		i++;
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		int i = 0;
		while (i < 100) {
			this->_ideas[i] = other._ideas[i];
			i++;
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "~Destroying " << BLUE;
	std::cout << "Brain" << RST << "." << std::endl;
}

void	Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		this->_ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return this->_ideas[index];
	}
	return "Invalid index";
}