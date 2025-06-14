/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/14 18:31:13 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// int	main(int argc, char **argv)
int	main(void)
{
	Zombie zombie;

	zombie.announce();

	zombie.randomChump("Jorge");
	zombie.announce();

	return (0);
}