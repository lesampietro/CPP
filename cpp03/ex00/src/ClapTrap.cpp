/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/13 20:43:38 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
	std::cout << "Claptrap " << BLUE << _name;
	std::cout << RST << " created.\n" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << CYAN << _name;
	std::cout << RST << " created.\n" << std::endl;
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
	std::cout << "Claptrap " << CYAN << _name;
	std::cout << RST << " has been destroyed." << std::endl;
}

bool	ClapTrap::isZero(int _energyPoints) {
	return (_energyPoints == 0);
}

void	ClapTrap::attack(const std::string &target) {
	if (isZero(_energyPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't attack anymore because ";
		std::cout << MAGENTA << "I'm dead.\n";
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
		std::cout << RST << "(ClapTrap " << CYAN << this->_name;
		std::cout << RST << " has " << MAGENTA << this->_energyPoints;
		std::cout << RST << " _energyPoints left)." << std::endl;
		std::cout << "-------------------------" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name;
	std::cout << MAGENTA << " attacks " << RST << target << ", causing ";
	std::cout << MAGENTA << this->_attackDamage << RST << " points of damage!";
	std::cout << std::endl;
	std::cout << CYAN << this->_name << RST;
	std::cout << ": FIRE! PEW PEW PEW PEW!\n" << CYAN << "\t\t\t(∩`-´)⊃━";
	std::cout << YELLOW << " ☆ﾟ.*･｡ﾟ\n" << RST << std::endl;
	this->_energyPoints--;

	std::cout << "(ClapTrap " << this->_name << " has ";
	if (isZero(_energyPoints))
		std::cout << MAGENTA << this->_energyPoints;
	else
		std::cout << GREEN << this->_energyPoints;
	std::cout << RST << " _energyPoints left).\n";
	std::cout << "-------------------------" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name;
	std::cout << " has taken " << amount << " damage points.";
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (isZero(_energyPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't repair myself anymore because ";
		std::cout << MAGENTA << "I'm dead.\n";
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
		std::cout << "(ClapTrap " << this->_name << " has ";
		std::cout << MAGENTA << this->_energyPoints;
		std::cout << RST << " _energyPoints left).\n";
		std::cout << "-------------------------" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name;
	std::cout << GREEN << " has been repaired";
	std::cout << RST << " by " << GREEN << amount;
	std::cout << RST << " _hitPoints." << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "(ClapTrap " << this->_name << " has ";
	if (isZero(_energyPoints))
		std::cout << MAGENTA << this->_energyPoints;
	else
		std::cout << GREEN << this->_energyPoints;
	std::cout << RST << " _energyPoints left).\n";
	std::cout << "-------------------------" << std::endl;
}

