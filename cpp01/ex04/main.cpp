/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 20:27:06 by lsampiet         ###   ########.fr       */
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

// int	main(void)
int main(int argc, char **argv)
{	
	if (argc != 4){
		std::cerr << "Usage: <filename> <string_1> <string_2>";
		std::cerr << std::endl;
		return (1);
	}
	std::string	temp;
	std::string	toBeReplaced = argv[2];
	std::string	toReplace = argv[3];
	if (toBeReplaced.empty() || toReplace.empty()){
		std::cerr << "Error: <string_1> and <string_2> cannot be empty.";
		std::cerr << std::endl;
		return (1);
	}
	std::ifstream	inputFile("file01");
	std::ofstream	outputFile("output");
	while (std::getline(inputFile, temp)){
		if (toBeReplaced.compare(temp) == 0)
			outputFile << toReplace;
	}
	inputFile.close();
	outputFile.close();
	// displayMessage("HumanA");
	return 0;
}
