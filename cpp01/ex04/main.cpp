/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 16:40:24 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Replace.hpp"

bool	isValidArg(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Usage: " << argv[0];
		std::cerr << " <filename> <string_toBeReplaced> <string_toReplace>";
		std::cerr << std::endl;
		return false;
	}
	std::string toBeReplaced = argv[2];
	if (toBeReplaced.empty())
	{
		std::cerr << MAGENTA << "Error: <string_toBeReplaced> cannot be empty.";
		std::cerr << RST << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{	
	if (!isValidArg(argc, argv))
		return 1;

	std::string	filename = argv[1];
	std::string	toBeReplaced = argv[2];
	std::string	toReplace = argv[3];

	if (!replace(filename, toBeReplaced, toReplace))
		return 1;
	
	return 0;
}
