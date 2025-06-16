/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:38 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 17:50:38 by lsampiet         ###   ########.fr       */
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
	std::cout << this->name << " attacks with their ";
	if (this->weapon) {
		std::cout << this->weapon->getType(); //uses ->getType() because the object is pointed to by a pointer
	}
	else {
		std::cout << "Five Point Palm Exploding Heart Technique";
	}
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	this->weapon = &newWeapon; //stores the address
}