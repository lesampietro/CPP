/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 18:30:00 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void){
	// this->name.getZombieName();
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(){
	std::cout << "Zombie Constructor called" << std::endl;
	return ;
}

Zombie::~Zombie(){
	std::cout << "Zombie ~Destructor called" << std::endl;
	return ;
}

std::string	Zombie::getZombieName() const{
	return name;
}