/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/19 18:58:04 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Claptrap default constructor called" << std::endl;
	std::cout << "Claptrap " << CYAN << _name;
	std::cout << RST << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap custom constructor called" << std::endl;
	std::cout << "Claptrap " << CYAN << _name;
	std::cout << RST << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
	std::cout << "Claptrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Claptrap copy assignment operator called" << std::endl;
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
	std::cout << "Claptrap default ~destructor called" << std::endl;
	std::cout << "Claptrap " << CYAN << _name;
	std::cout << RST << " has been destroyed.\n" << std::endl;
}

bool	ClapTrap::isZero(int points) {
	return (points == 0);
}

void	ClapTrap::attack(const std::string &target) {
	if (isZero(_energyPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't attack anymore because ";
		std::cout << MAGENTA << "I'm too tired." << std::endl;
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
	}
	else if (isZero(_hitPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't attack anymore because ";
		std::cout << MAGENTA << "I'm dead." << std::endl;
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
	}
	else {	
		std::cout << "ClapTrap " << this->_name;
		std::cout << MAGENTA << " attacks " << RST << target << ", causing ";
		std::cout << MAGENTA << this->_attackDamage;
		std::cout << RST << " points of damage!" << std::endl;
		std::cout << CYAN << this->_name << RST;
		std::cout << ": FIRE! PEW PEW PEW PEW!\n" << CYAN << "\t\t\t(∩`-´)⊃━";
		std::cout << BLUE << " ☆ﾟ.*･｡ﾟ\n" << RST << std::endl;
		this->_energyPoints--;
	}
	std::cout << "(ClapTrap " << this->_name << " has ";
	std::cout << YELLOW << this->_energyPoints << RST << " _energyPoints and ";
	std::cout << YELLOW << this->_hitPoints << RST << " _hitPoints left).";
	std::cout << std::endl;
	std::cout << "-------------------------\n" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (isZero(_energyPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't take damage anymore because ";
		std::cout << MAGENTA << "I'm too tired." << std::endl;
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
	}
	else if (isZero(_hitPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't take damage anymore because ";
		std::cout << MAGENTA << "I'm dead." << std::endl;
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " takes " << MAGENTA << amount; 
		std::cout << RST << " damage points." << std::endl;
		std::cout << CYAN << this->_name;
		std::cout << RST << ": OUCH!!! That hurts!" << std::endl;
		std::cout << CYAN << "\t\t\t(╥﹏╥)\n" << RST << std::endl;
		this->_hitPoints -= amount;		
	}
	std::cout << "(ClapTrap " << this->_name << " has ";
	std::cout << YELLOW << this->_energyPoints << RST << " _energyPoints and ";
	std::cout << YELLOW << this->_hitPoints << RST << " _hitPoints left).";
	std::cout << std::endl;
	std::cout << "-------------------------\n" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (isZero(_energyPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't repair myself anymore because ";
		std::cout << MAGENTA << "I'm too tired." << std::endl;
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
	}
	else if (isZero(_hitPoints)) {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": I can't repair myself anymore because ";
		std::cout << MAGENTA << "I'm dead." << std::endl;
		std::cout << CYAN << "\t\t\t( x_x)\n" << RST << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name;
		std::cout << GREEN << " repairs itself";
		std::cout << RST << " by " << GREEN << amount;
		std::cout << RST << " _hitPoints." << std::endl;
		std::cout << CYAN << "\t\t\t\\('ヮ')/\n" << RST << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	std::cout << "(ClapTrap " << this->_name << " has ";
	std::cout << YELLOW << this->_energyPoints << RST << " _energyPoints and ";
	std::cout << YELLOW << this->_hitPoints << RST << " _hitPoints left).";
	std::cout << std::endl;
	std::cout << "-------------------------\n" << std::endl;
}
