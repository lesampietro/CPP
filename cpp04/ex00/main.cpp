/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/25 14:49:45 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"
#include "includes/WrongDog.hpp"

int	main() {
	std::cout << YELLOW << "======= BASIC ANIMALS TESTS =======\n" << RST;
	std::cout << "-------- Creating Animals ---------" << RST << std::endl;
	const Animal* animal = new Animal();
	std::cout << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "------ Checking Animal Types ------" << RST << std::endl;
	std::cout << "Cat type: " << cat->getType() << "." << std::endl;
	std::cout << "Dog Type: " << dog->getType() << ".\n" << std::endl;

	std::cout << "----- Checking Animal Sounds ------" << RST << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();
	std::cout << std::endl;

	std::cout << "-------- Deleting Animals ---------" << RST << std::endl;
	delete animal;
	delete cat;
	delete dog;

	std::cout << YELLOW << "======= WRONG ANIMALS TESTS =======\n" << RST;
	std::cout << "------ Creating Wrong Animals -----" << RST << std::endl;
	const WrongAnimal* animal2 = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* dog2 = new WrongDog();
	const WrongAnimal* cat2 = new WrongCat();

	std::cout << "--- Checking Wrong Animal Types ---" << RST << std::endl;
	std::cout << "Cat2 type: " << cat2->getType() << "." << std::endl;
	std::cout << "Dog2 Type: " << dog2->getType() << ".\n" << std::endl;

	std::cout << "--- Checking Wrong Animal Sounds --\n" << RST;
	cat2->makeSound(); // will output the cat sound!
	dog2->makeSound();
	animal2->makeSound();
	std::cout << std::endl;

	std::cout << "----- Deleting Wrong Animals ------" << RST << std::endl;
	delete cat2;
	delete dog2;
	delete animal2;

	return 0;
}
