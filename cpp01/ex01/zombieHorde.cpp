/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:19:45 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 12:33:45 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	std::cout << "\nCreating an array of " << N << " zombies called: ";
	std::cout << name << ".\n";
	std::cout << std::endl;

	// Allocates all objects on one memory block - new[] for object array
	Zombie *horde = new Zombie[N];
	int	i = 0;
	
	while (i < N){
		horde[i].setName(name);
		i++;
	}
	
	return horde;
}