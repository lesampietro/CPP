/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:51:16 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/22 16:24:36 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/harlFilter.hpp"

bool	isValidArg(int argc, char **argv){
	if (argc != 2){
		std::cout << MAGENTA << "Error: needs an argument.";
		std::cout << RST << std::endl;
		std::cout << "example: ";
		std::cout << argv[0];
		std::cout << CYAN << " DEBUG" << RST;
		std::cout << " | " << GREEN << "INFO" << RST;
		std::cout << " | " << YELLOW << "WARNING" << RST;
		std::cout << " | " << MAGENTA << "ERROR" << RST;
		std::cout << " | " << " " << RST;
		std::cout << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char **argv)
{
	if (!isValidArg(argc, argv))
		return 1;

	Harl	harl;
	std::string command = argv[1];
	
	harl.switchComplain(command);
	
	return 0;
}