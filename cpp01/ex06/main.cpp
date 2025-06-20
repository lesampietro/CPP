/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:51:16 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/19 21:08:25 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// bool	isValidArg(int argc, char **argv){
	// if (argc != 2){
	// 	std::cout << "Error: enter a command following the example below:";
	// 	std::cout << std::endl;
	// 	std::cout << argv[0];
	// 	std::cout << CYAN << " DEBUG" << RST;
	// 	std::cout << " | " << GREEN << "INFO" << RST;
	// 	std::cout << " | " << YELLOW << "WARNING" << RST;
	// 	std::cout << " | " << MAGENTA << "ERROR" << RST; 
	// 	std::cout << std::endl;
	// 	return false;
	// }
	// std::string cmd = argv[1];
	// if (cmd.compare("DEBUG") != 0 && cmd.compare("INFO") != 0 \
	// 	&& cmd.compare("WARNING") != 0 && cmd.compare("ERROR")!= 0)
	// {
	// 	std::cout << "Error: enter a command following the example below:";
	// 	std::cout << std::endl;
	// 	std::cout << argv[0];
	// 	std::cout << CYAN << " DEBUG" << RST;
	// 	std::cout << " | " << GREEN << "INFO" << RST;
	// 	std::cout << " | " << YELLOW << "WARNING" << RST;
	// 	std::cout << " | " << MAGENTA << "ERROR" << RST;
	// 	std::cout << std::endl;
	// 	return false;
	// }
// 	return true;
// }

int	main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << MAGENTA << "Error: pass an argument";
		return 1;
	}

	Harl	harl;
	std::string command = argv[1];
	
	harl.switchComplain(command);
	
	return 0;
}