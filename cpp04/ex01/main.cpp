/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/26 20:21:41 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cat.hpp"
#include "includes/Dog.hpp"


void	testDeepCopy() {
	std::cout << YELLOW << "======= TESTING DEEP COPY =======\n" << RST;
	std::cout << "------- Creating Dogs -------\n" << std::endl;
	Dog* dog1 = new Dog();
	std::cout << " #1 (To Be Copied).\n" << std::endl;	
	Dog* dog2 = new Dog(*dog1); // Deep copy
	std::cout << GREEN << "Dog " << RST << "#2 (Deep Copy) created.\n";
	std::cout << std::endl;
	
	std::cout << "------- Checking Brain Allocation -------\n" << std::endl;
	std::cout << GREEN << "Dog " << RST;	
	std::cout << "#1 Brain Address: " << dog1->getBrain() << std::endl;
	std::cout << GREEN << "Dog " << RST;
	std::cout << "#2 Brain Address: " << dog2->getBrain() << std::endl;
	std::cout << std::endl;

	std::cout << "------- Testing Deep Copy -------\n" << std::endl;
	std::cout << GREEN << "Dog #1 " << RST;
	std::cout << "Brain First Idea: " << dog1->getBrain()->getIdea(0);
	std::cout << GREEN << "\nDog #2 " << RST;
	std::cout << "Brain First Idea: " << dog2->getBrain()->getIdea(0);
	std::cout << "\n\nChanging Dog #2 ideas..." << std::endl;
	dog2->getBrain()->setIdea(0, "I want to play fetch!");
	std::cout << GREEN << "Dog #1 " << RST;
	std::cout << "Brain First Idea: " << dog1->getBrain()->getIdea(0);
	std::cout << GREEN << "\nDog #2 " << RST;
	std::cout << "Brain First Idea: " << dog2->getBrain()->getIdea(0);
	std::cout << "\n. . ." << std::endl;
	std::cout << "\nChanging Dog #1 ideas..." << std::endl;
	dog1->getBrain()->setIdea(0, "Squirrel!? SQUIRREL!!!");
	std::cout << GREEN << "Dog #1 " << RST;
	std::cout << "Brain First Idea: " << dog1->getBrain()->getIdea(0);
	std::cout << GREEN << "\nDog #2 " << RST;
	std::cout << "Brain First Idea: " << dog2->getBrain()->getIdea(0);
	std::cout << "\n. . .\n" << std::endl;

	std::cout << "------- Deleting Dogs -------\n" << std::endl;
	delete dog1;
	std::cout << " #1 has been ~destroyed.\n" << std::endl;
	delete dog2;
	std::cout << " #2 has been ~destroyed.\n" << std::endl;

	std::cout << YELLOW << "======= TESTING SHALLOW COPY =======\n" << RST;
	std::cout << "------- Creating Cats -------\n" << std::endl;
	Cat* cat1 = new Cat();
	std::cout << " #1 (To Be Copied).\n" << std::endl;	
	Cat* shallow = cat1; // Shallow copy
	std::cout << GREEN << "Cat " << RST << "#2 (Shallow Copy) created.\n";
	std::cout << std::endl;
	
	std::cout << "------- Checking Brain Allocation -------\n" << std::endl;
	std::cout << GREEN << "Cat " << RST;	
	std::cout << "#1 Brain Address: " << cat1->getBrain() << std::endl;
	std::cout << GREEN << "Cat " << RST;
	std::cout << "#2 Brain Address: " << shallow->getBrain() << std::endl;
	std::cout << std::endl;
	
	std::cout << "------- Testing Shallow Copy -------\n" << std::endl;
	std::cout << GREEN << "Cat #1 " << RST;
	std::cout << "Brain First Idea: " << cat1->getBrain()->getIdea(0);
	std::cout << GREEN << "\nCat #2 " << RST;
	std::cout << "Brain First Idea: " << shallow->getBrain()->getIdea(0);
	std::cout << "\n\nChanging Cat #2 ideas..." << std::endl;
	shallow->getBrain()->setIdea(0, "I'm a cat");
	std::cout << GREEN << "Cat #1 " << RST;
	std::cout << "Brain First Idea: " << cat1->getBrain()->getIdea(0);
	std::cout << GREEN << "\nCat #2 " << RST;
	std::cout << "Brain First Idea: " << shallow->getBrain()->getIdea(0);
	std::cout << "\n. . ." << std::endl;
	std::cout << "\nChanging Cat #1 ideas..." << std::endl;
	cat1->getBrain()->setIdea(0, "I want to take a nap");
	std::cout << GREEN << "Cat #1 " << RST;
	std::cout << "Brain First Idea: " << cat1->getBrain()->getIdea(0);
	std::cout << GREEN << "\nCat #2 " << RST;
	std::cout << "Brain First Idea: " << shallow->getBrain()->getIdea(0);
	std::cout << "\n. . .\n" << std::endl;

	std::cout << "------- Deleting Dogs -------\n" << std::endl;
	delete cat1;
	std::cout << " #1 has been ~destroyed.\n" << std::endl;
	// delete shallow;
	// std::cout << " #2 has been ~destroyed.\n" << std::endl;
}

int	main() {
	std::cout << YELLOW << "========== BASIC TESTS ==========\n" << RST;
	std::cout << "--- Creating Array of Animals ---\n" << std::endl;
	int	i = 0;
	int	size = 4;
	Animal* animals[size];
	
	while (i < size) {
		if (i < size / 2){
			animals[i] = new Dog();
			std::cout << " #" << i + 1 << ".\n" << std::endl;	
		}
		else {
			animals[i] = new Cat();
			std::cout << " #" << (i + 1) - (size / 2);
			std::cout << ".\n" << std::endl;		
		}
		i++;
	}

	std::cout << "------- Testing Sounds -------\n" << std::endl;
	i = 0;
	while (i < size) {
		std::cout << "Animal #" << i + 1 << ": ";
		animals[i]->makeSound();
		i++;
	}

	std::cout << "\n------- Deleting Animals -------\n" << std::endl;
	i = 0;
	while (i < size) {
		if (i < size / 2){	
			delete animals[i];
			std::cout << " #" << i + 1;
			std::cout << " has been ~destroyed.\n" << std::endl;
		}
		else {
			delete animals[i];
			std::cout << " #" << (i + 1) - (size / 2);
			std::cout << " has been ~destroyed.\n" << std::endl;
		}
		i++;
	}

	testDeepCopy();

	return 0;
}


//Deep Copy: a kind of copy that holds every data from the original object, including data that has been dinamically allocated. That means the copy will have its own copied data: it does not share resources with the original and changes made to the copy will not affect the original.

//Shallow Copy: only the pointers or references are copied, which means the data will be shared between the original and the copy. If one of them changes the data, the other will also see the change, which can lead to unexpected behavior or memory leaks if not handled properly. **dangling pointers == point to a memory location that has been freed or deallocated.**