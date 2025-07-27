/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/27 13:53:21 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/DiamondTrap.hpp"

//BASIC TESTS
int main(void) 
{
	ClapTrap clap("Clappy");
	std::cout << std::endl;
	ScavTrap scav("Scavy");
	std::cout << std::endl;
	FragTrap frag("Fraggy");
	std::cout << std::endl;
	DiamondTrap diamond("Diamond");

	diamond.whoAmI();
	diamond.attack("Bilu");
	diamond.takeDamage(5);
	diamond.beRepaired(10);
	diamond.guardGate();
	diamond.highFivesGuys();
	return 0;
}
