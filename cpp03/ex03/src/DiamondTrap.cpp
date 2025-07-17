/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/17 19:13:58 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100; //It's compulsory to initialize these on the function body, because they are inherited members
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
	std::cout << "ScavTrap " << CYAN << _name;
	std::cout << RST << " created.\n" << std::endl;
}

// Custom Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap custom constructor called" << std::endl;
	std::cout << "ScavTrap " << CYAN << _name;
	std::cout << RST << " created.\n" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) { // Check for self-assignment
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default ~destructor called" << std::endl;
	std::cout << "ScavTrap " << CYAN << _name;
	std::cout << RST << " has been destroyed." << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (isZero(_energyPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I'm waaaay too " << MAGENTA << "tired ";
		std::cout <<RST << "for this." << std::endl;
		std::cout << CYAN << "\t\t\t( -_-)\n" << RST << std::endl;
	}
	else if (isZero(_hitPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": Actually...";
		std::cout << MAGENTA << "I'm dead." << std::endl;
		std::cout << CYAN << "\t\t\t( ｡×_×)〵\n"
				  << RST << std::endl;
	}
	else {	
		std::cout << "ScavTrap " << this->_name;
		std::cout << MAGENTA << " attacks " << RST << target << ", causing ";
		std::cout << MAGENTA << this->_attackDamage;
		std::cout << RST << " points of damage!" << std::endl;
		std::cout << CYAN << this->_name << RST;
		std::cout << ": TOUCHÉ!\n" << CYAN << "\t\t\t(∩⇀_⇀)⊃";
		std::cout << BLUE << "¤]═────\n" << RST << std::endl;
		this->_energyPoints--;
	}
	std::cout << "(ScavTrap " << this->_name << " has ";
	std::cout << YELLOW << this->_energyPoints << RST << " _energyPoints and ";
	std::cout << YELLOW << this->_hitPoints << RST << " _hitPoints left).";
	std::cout << std::endl;
	std::cout << "-------------------------\n" << std::endl;
}


void	ScavTrap::guardGate() {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": Do not talk to me. I am in Gate Keeper mode!";
		std::cout << CYAN << "\t\t\tᕙ(`ᴖ´)ᕗ\n" << RST << std::endl;
		std::cout << "-------------------------\n" << std::endl;
}
