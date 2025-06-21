/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 12:31:48 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(int i){
	std::cout <<"Zombie ";
	std::cout << YELLOW << this->name << " #" << i << RST << ": ";
	std::cout << "Moar BraiiiiiiinnnzzzZ..." << RST << std::endl;
}

Zombie::Zombie(){
	this->name = "Unknown";
	// std::cout << this->name;
	// std::cout << " Zombie Constructor called";
	// std::cout << std::endl;
}

Zombie::~Zombie(){
	// std::cout << this->name;
	// std::cout << " Zombie ~Destructor called";
	// std::cout << std::endl;
}

void Zombie::setName(std::string name){
	if (name.empty())
		return ;
	else
		this->name = name;
}