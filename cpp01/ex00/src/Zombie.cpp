/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 12:58:27 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void	Zombie::announce(void){
	std::cout << YELLOW << this->name << ": " << RST;
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(){
	this->name = "Unknown";
	std::cout << this->name;
	std::cout << " Zombie Constructor called";
	std::cout << std::endl;
}

Zombie::~Zombie(){
	std::cout << YELLOW << this->name << RST;
	std::cout << " Zombie ~Destructor called";
	std::cout << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}