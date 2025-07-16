/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/16 00:25:59 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"

//BASIC TESTS
int main(void) 
{
	ClapTrap noName;
	ClapTrap bob("Bob");

	std::cout << YELLOW << "--- Testing basic actions ---\n";
	std::cout << RST << std::endl;
	noName.attack("Bob");
	bob.takeDamage(5);
	bob.beRepaired(4);
	bob.attack("Unknown");
	noName.takeDamage(10);
	noName.beRepaired(4);
	noName.attack("Bob");

	// std::cout << YELLOW << "\n--- Testing loosing all energyPoints ---";
	// std::cout << RST << std::endl;
	// bob.attack("Unknown"); // 7
	// bob.attack("Unknown"); // 6
	// bob.attack("Unknown"); // 5
	// bob.attack("Unknown"); // 4
	// bob.attack("Unknown"); // 3
	// bob.attack("Unknown"); // 2
	// bob.attack("Unknown"); // 1
	// bob.beRepaired(4);
	// bob.attack("Unknown"); // 0
	// bob.beRepaired(4);
	// std::cout << std::endl;

	return 0;
}
