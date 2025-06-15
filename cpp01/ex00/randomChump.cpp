/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:19:51 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 18:51:20 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name){
	Zombie zombie;
	zombie.setName(name);
	zombie.announce();
	std::cout << std::endl;
	return ;
}