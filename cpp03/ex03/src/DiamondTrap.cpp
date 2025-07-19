/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/19 19:01:00 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap()
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << "DiamondTrap " << CYAN << _name;
	std::cout << RST << " created.\n" << std::endl;
}

// Custom Constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = 30;
	std::cout << "DiamondTrap custom constructor called" << std::endl;
	std::cout << "DiamondTrap " << CYAN << _name;
	std::cout << RST << " created.\n" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
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
	std::cout << CYAN << this->_name << RST << std::endl;
	std::cout << RST << "I have " << YELLOW << this->_energyPoints;
	std::cout << RST << " _energyPoints" << std::endl;
	std::cout << RST << "And I also have " << YELLOW << this->_hitPoints;
	std::cout << RST << " _hitPoints" << std::endl;
	std::cout << RST << "And I also have " << YELLOW << this->_attackDamage;
	std::cout << RST << " _attackDamage power" << std::endl;
	std::cout << std::endl;
}
