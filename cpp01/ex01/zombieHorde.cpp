/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:19:45 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/19 18:37:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
	Zombie *zombie[N] = new Zombie();
	int	i = 0;
	while (i < N){
		zombie[i]->setName(name);
		std::cout << std::endl;
		zombie[i]->announce();
		i++;
	}
	return *zombie[];
}