/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 20:03:39 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

// IDEIAS:
// begin(): Returns an iterator pointing to the first character of the string
// copy(): Copies characters from the string into a character array
// clear(): Removes all characters, making the string empty
// erase(): Deletes part of the string by position and length
// compare(): Compares the string with another string and returns the result
// length(): Returns the number of characters in the string
// insert(): Inserts characters or a substring at a specified position
// swap(): Exchanges the contents of two strings

// void	displayMessage(std::string human){
// 	std::cout << std::endl;
// 	std::cout << "-----------------------------------------";
// 	std::cout << std::endl;
// 	std::cout << "|" << std::setw(20) << std::right;
// 	std::cout << YELLOW << "Testing " << human << RST;
// 	std::cout << std::setw(13) << std::right << "|";
// 	std::cout << std::endl;
// 	std::cout << "-----------------------------------------";
// 	std::cout << std::endl;
// }

// int main(int argc, char **argv)
int	main(void)
{	
	// if (argc != 4)
	// {
	// 	std::cerr << "Usage: <filename> <string_1> <string_2>" << std::endl;
	// 	return (1);
	// }
	std::string	toBeReplaced;
	std::ifstream	file01("file01");
	while (std::getline(file01, toBeReplaced)){
		std::cout << toBeReplaced;
	}
	file01.close();
	// displayMessage("HumanA");
	return 0;
}
