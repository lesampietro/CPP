/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/17 19:13:12 by lsampiet         ###   ########.fr       */
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

	std::cout << YELLOW << "--- Testing basic actions ---\n";
	std::cout << RST << std::endl;
	clap.attack("Bilu");
	frag.takeDamage(5);
	scav.attack("Bilu");
	frag.takeDamage(20);
	frag.beRepaired(5);
	frag.attack("Pierre");
	frag.highFivesGuys();
	return 0;
}
