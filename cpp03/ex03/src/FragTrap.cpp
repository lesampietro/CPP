/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:29 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/19 18:57:55 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
	std::cout << "FragTrap " << CYAN << _name;
	std::cout << RST << " created." << std::endl;
}

// Custom Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap custom constructor called" << std::endl;
	std::cout << "FragTrap " << CYAN << _name;
	std::cout << RST << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) { // Check for self-assignment
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default ~destructor called" << std::endl;
	std::cout << "FragTrap " << CYAN << _name;
	std::cout << RST << " has been destroyed." << std::endl;
}

void	FragTrap::highFivesGuys() {
		std::cout << CYAN << this->_name;
		std::cout << RST << ": Hey guys! Let's high five!\n";
		std::cout << CYAN << "\t\t\tヘ( ^o^)ノ＼(^_^ )\n" << RST << std::endl;
		std::cout << "-------------------------\n" << std::endl;
}
