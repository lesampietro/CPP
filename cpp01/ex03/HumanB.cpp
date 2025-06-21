/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:38 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 12:44:29 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(){}

HumanB::HumanB(std::string name){
	this->name = name;
	this->weapon = NULL; // C++98 style - on later versions it'd be "nullptr"
}

HumanB::~HumanB(){}

void	HumanB::attack(){
	if (this->weapon) {
		std::cout << BOLD << this->name << RST;
		std::cout << " attacks with their ";
		std::cout << GREEN << this->weapon->getType() << "."; //uses ->getType() because the object is pointed to by a pointer
	}
	else {
		std::cout << BOLD << this->name;
		std::cout << MAGENTA << " has no weapon." << RST;
		std::cout << std::endl;
		std::cout << this->name << " uses their ";
		std::cout << GREEN << "Five Point Palm Exploding Heart Technique.";
	}
	std::cout << RST << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	std::cout << "Creating a weapon for ";
	std::cout << BOLD << this->name << "." << RST;
	std::cout << std::endl;
	this->weapon = &newWeapon; // stores the address
}