/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:30:49 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 16:44:09 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string weaponType){
	this->type = weaponType;
}

Weapon::~Weapon(){}

const std::string	&Weapon::getType(){
	return this->type;
}

void	Weapon::setType(std::string newWeaponType){
	this->type = newWeaponType;
}