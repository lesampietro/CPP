/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/12 19:30:06 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	this->_name = _name;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

bool	ClapTrap::isZero(int _energyPoints) {
	return _energyPoints;
}

void	ClapTrap::attack(const std::string &target) {
	if (!isZero(_energyPoints)) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << MAGENTA << " can't attack anymore." << RST;
		std::cout << std::endl;
	}
	std::cout << "ClapTrap " << this->_name;
	std::cout << " attacks " << target << ", causing";
	std::cout << this->_attackDamage << " points of damage!";
	this->_energyPoints--;
	// this->_energyPoints = _energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name;
	std::cout << " has taken " << amount << " damage points.";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name;
	std::cout << " has been repaired " << amount << " energy points.";
}


// When ClapTrap attacks, it causes its target to lose <attack damage> hit points. When ClapTrap repairs itself, it regains <amount> hit points. Attacking and repairing each cost 1 energy point. Of course, ClapTrap can’t do anything if it has no hit points or energy points left. However, since these exercises serve as an introduction, the ClapTrap instances should not interact directly with one another, and the parameters will not refer to another instance of ClapTrap.

// In all of these member functions, you need to print a message to describe what happens. For example, the attack() function may display something like (of course, without the angle brackets): ClapTrap <name> attacks <target>, causing <damage> points of damage! The constructors and destructor must also display a message, so your peer-evaluators can easily see that they have been called.

// Implement and turn in your own tests to ensure your code works as expected
