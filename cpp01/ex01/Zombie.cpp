/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/19 19:41:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(int N){
	int	i = 1;

	while (i <= N)
	{
		std::cout <<"Zombie ";
		std::cout << YELLOW << this->name << " #" << i << RST << ": ";
		std::cout << "Moar BraiiiiiiinnnzzzZ..." << RST << std::endl;
		i++;
	}
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
	this->name = name;
}