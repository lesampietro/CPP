/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:30:49 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 13:51:49 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string weaponType){
	this->type = weaponType;
}

Weapon::~Weapon(){}

const std::string	&Weapon::getType(){
	return this->type;
}

void	Weapon::setType(std::string newWeaponType){
	std::cout << "Setting new type of weapon." << std::endl;
	this->type = newWeaponType;
}