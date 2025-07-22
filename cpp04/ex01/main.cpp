/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 19:49:38 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int	main() {
	std::cout << YELLOW << "========== BASIC TESTS ==========\n" << RST;
	std::cout << "--- Creating Array of Animals ---\n" << std::endl;
	
	const int	ARRAY_SIZE = 10;
	int			i = 0;
	Animal* animals[ARRAY_SIZE];
	
	while (i < ARRAY_SIZE) {
		if (i < ARRAY_SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat ();
		i++;
	}

	std::cout << "------- Testing Sounds -------\n" << std::endl;
	i = 0;
	while (i < ARRAY_SIZE) {
		std::cout << "Animal #" << i << ": ";
		// std::cout << GREEN << animals[i]->getType() << RST << ": ";
		animals[i]->makeSound();
		i++;
	}

	std::cout << std::endl;
	std::cout << YELLOW << "======= DEEP COPY TESTS =======\n" << RST;
	// testDeepCopy();

	return 0;
}