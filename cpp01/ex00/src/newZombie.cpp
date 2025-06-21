/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:19:45 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 12:58:40 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie *newZombie(std::string name){
	Zombie *zombie = new Zombie();
	zombie->setName(name);
	zombie->announce();
	std::cout << std::endl;
	return zombie;
}