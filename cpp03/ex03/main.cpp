/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/18 14:51:08 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/DiamondTrap.hpp"

//BASIC TESTS
int main(void) 
{
	ClapTrap clap("Bob");
	std::cout << std::endl;
	ScavTrap scav("Pierre");
	FragTrap frag("Bilu");
	DiamondTrap diamond("Diamond");

	std::cout << YELLOW << "--- Testing basic actions ---\n";
	std::cout << RST << std::endl;
	
	diamond.whoAmI();
	diamond.attack("Bilu");
	diamond.takeDamage(5);
	diamond.beRepaired(10);
	frag.takeDamage(5);
	scav.attack("Bilu");
	frag.takeDamage(20);
	frag.beRepaired(5);
	frag.attack("Pierre");
	frag.highFivesGuys();
	return 0;
}
