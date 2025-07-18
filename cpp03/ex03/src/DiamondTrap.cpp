/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/18 15:00:32 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	_hitPoints = FragTrap::_hitPoints; //It's compulsory to initialize these on the function body, because they are inherited members
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << "DiamondTrap " << CYAN << _name;
	std::cout << RST << " created.\n" << std::endl;
}

// Custom Constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap custom constructor called" << std::endl;
	std::cout << "DiamondTrap " << CYAN << _name;
	std::cout << RST << " created.\n" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other) { // Check for self-assignment
		ClapTrap::operator=(other);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default ~destructor called" << std::endl;
	std::cout << "DiamondTrap " << CYAN << _name;
	std::cout << RST << " has been destroyed." << std::endl;
}


void	DiamondTrap::whoAmI() {
		std::cout << RST << "This is my ClapTrap name: ";
		std::cout << CYAN << ClapTrap::_name << std::endl;
		std::cout << RST << "This is my DiamondTrap name: ";
		std::cout << CYAN << this->_name << RST <<	 std::endl;
}
