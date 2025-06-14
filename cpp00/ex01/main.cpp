/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:07:34 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/13 18:21:38 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	displayMessage(void)
{
	std::cout << YELLOW << "---------------------------------------------";
	std::cout << std::endl;
	std::cout << "|" << std::setw(44) << std::right << "|" << std::endl;
	std::cout << "|" << "         ✿ MY CRAPPY PHONEBOOK ✿           |";
	std::cout << std::endl;
	std::cout << "|" << std::setw(31) << std::right << "---------------------";
	std::cout << std::setw(13) << std::right << "|" << std::endl;
	std::cout << "|" << std::setw(44) << std::right << "|" << std::endl;
	std::cout << "|" << std::setw(30) << std::right << "Enter your command:";
	std::cout << std::setw(14) << std::right << "|" << std::endl;
	std::cout << "|" << std::setw(31) << std::right << "[ADD] [SEARCH] [EXIT]";
	std::cout << std::setw(13) << std::right << "|" << std::endl;
	std::cout << "|" << std::setw(44) << std::right << "|" << std::endl;
	std::cout << "---------------------------------------------" << RST;
	std::cout << std::endl;
}

int	main(void)
{
	std::string cmd;
	PhoneBook nome;

	while (1)
	{
		// std::cout << "Type your command [ADD], [SEARCH], [EXIT]: ";
		displayMessage();
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0){
			nome.addContact();
		}
		else if (cmd.compare("EXIT") == 0){
			std::cout << GREEN << "BYE BYE :)" << RST << std::endl;
			return (0);
		}
		else if (cmd.compare("SEARCH") == 0){
			nome.searchContact();
		}
		else if (std::cin.eof())
		{
			std::cout << "\n";
			std::cout << MAGENTA << "Ctrl+D - Program exited" << RST << std::endl;
			return (1);
		}
		else {
			std::cout << MAGENTA << "Command does not exist." << RST << std::endl;
		}
	}
	return (0);
}