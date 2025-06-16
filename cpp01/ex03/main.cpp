/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 19:29:06 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

void	displayMessage(std::string human){
	std::cout << std::endl;
	std::cout << "-----------------------------------------";
	std::cout << std::endl;
	std::cout << "|" << std::setw(20) << std::right;
	std::cout << YELLOW << "Testing " << human << RST;
	std::cout << std::setw(13) << std::right << "|";
	std::cout << std::endl;
	std::cout << "-----------------------------------------";
	std::cout << std::endl;
}

int main(void)
{
	displayMessage("HumanA");
	{
		Weapon hammer = Weapon("Morning star");
		HumanA bodyguard("Gogo Yubari", hammer);
		bodyguard.attack();
		hammer.setType("other type of Medieval Weapon");
		bodyguard.attack();
	}
	displayMessage("HumanB");
	{
		Weapon katana = Weapon("Hattori Hanzo Katana");
		HumanB beatrix("Black Mamba");
		beatrix.attack();
		beatrix.setWeapon(katana);
		beatrix.attack();
		katana.setType("Flying Dagger");
		beatrix.attack();
	}
	return 0;
}

// int	main(void)
// {
// 	displayMessage("HumanA");
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	displayMessage("HumanB");
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");
// 		jim.attack();
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// 	return 0;
// }