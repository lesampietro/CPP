/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/19 19:47:24 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool	isValidArg(int argc, char **argv){
	if (argc != 3)
	{
		std::cout << "Usage: ";
		std::cout << argv[0] << " <number_of_zombies> <zombie_name>";
		std::cout << std::endl;
		return false;
	}
	int number = atol(argv[1]);
	if (number <= 0)
	{
		std::cout << MAGENTA << "Error: please enter an integer > 0.";
		std::cout << RST << std::endl;
		std::cout << "Usage: ";
		std::cout << argv[0] << " <number_of_zombies> <zombie_name>";
		std::cout << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char **argv)
{
	if (!isValidArg(argc, argv)){
		return 1;
	}
	
	int	N = atol(argv[1]);
	std::string name = argv[2];

	// Uses zombieHorde to allocate dinamically N zombies with name
	Zombie *horde = zombieHorde(N, name);

	// Uses ->announce because horde is a pointer to an array.
	// Receives N as parameter for the loop
	horde->announce(N);

	delete[] horde;

	return (0);
}