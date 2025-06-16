/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:38 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 17:12:30 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// The weapon object MUST be initialized on the Constructor's initialization list, it's a C++ rule
HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon){ 
	this->name = name;
	// this->weapon = &weapon; - it is FORBIDDEN to assign a reference after initialization
}

HumanA::~HumanA(){}

void	HumanA::attack(){
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType(); // uses .getType() because it's a reference
	std::cout << std::endl;
}