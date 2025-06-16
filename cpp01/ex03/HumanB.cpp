/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:38 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 16:45:35 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(){}

HumanB::HumanB(std::string name){
	this->name = name;
}

HumanB::~HumanB(){}

void	HumanB::attack(){
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon newWeapon){
	this->weapon = newWeapon;
}