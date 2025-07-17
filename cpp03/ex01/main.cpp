/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/17 19:10:04 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScavTrap.hpp"

//BASIC TESTS
int main(void) 
{
	ClapTrap bob("Bob");
	ScavTrap scav("Pierre");

	std::cout << YELLOW << "--- Testing basic actions ---\n";
	std::cout << RST << std::endl;
	scav.attack("Bob");
	bob.takeDamage(5);
	bob.beRepaired(4);
	scav.guardGate();
	bob.attack("Pierre");
	scav.beRepaired(4);
	scav.takeDamage(200);
	scav.attack("Bob");

	return 0;
}
