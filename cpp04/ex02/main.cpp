/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/27 13:55:12 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/AAnimal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int	main() {
	std::cout << YELLOW << "========== BASIC TESTS ==========\n" << RST;
	std::cout << "--- Creating Animals ---\n" << std::endl;
	
	const AAnimal* cat = new Cat();
	const AAnimal *dog = new Dog();
	// const AAnimal *animal = new AAnimal(); //For error demonstration

	std::cout << "--- Testing Animal Sounds ---\n" << std::endl;
	std::cout << GREEN << cat->getType() << RST << " sound is";
	cat->makeSound();
	std::cout << GREEN << dog->getType() << RST << " sound is";
	dog->makeSound();

	std::cout << "\n--- Deleting Animals ---\n" << std::endl;
	delete cat;
	delete dog;

	return 0;
}

