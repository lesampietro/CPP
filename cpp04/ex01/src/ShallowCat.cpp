/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShallowCat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:18:31 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/25 16:58:09 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShallowCat.hpp"

ShallowCat::ShallowCat() {
	this->_brain = new Brain();
	std::cout << RST << "Created ";
}

ShallowCat::ShallowCat(const ShallowCat &copy){
	std::cout << "ShallowCat copy constructor called" << std::endl;
	this->_brain = copy._brain; // Shallow copy of the Brain

}

ShallowCat &ShallowCat::operator=(const ShallowCat &other) {
	std::cout << "ShallowCat copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_brain = other._brain; // Shallow copy of the Brain
	}
	return (*this);
}

ShallowCat::~ShallowCat() {
	std::cout << "~Destroying " << GREEN;
	delete _brain;
}

Brain*	ShallowCat::getBrain() const {
	return _brain;
}