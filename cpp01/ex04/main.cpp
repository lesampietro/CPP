/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 21:16:29 by lsampiet         ###   ########.fr       */
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
		std::cerr << "Usage: " << argv[0];
		std::cerr << " <filename> <string_1> <string_2>";
		std::cerr << std::endl;
		return 1;
	}

	std::string	filename = argv[1];
	std::string	toBeReplaced = argv[2];
	std::string	toReplace = argv[3];

	if (toBeReplaced.empty()){
		std::cerr << "Error: <string_1> cannot be empty.";
		std::cerr << std::endl;
		return 1;
	}
	
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open()){
		std::cerr << "Error: Could not open file '";
		std::cerr << filename << "'." << std::endl;
		return 1;
	}
	
	std::string		outputFileName = filename + ".replace";
	std::ofstream	outputFile(outputFileName.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create output file '";
		std::cerr << outputFileName << "'." << std::endl;
		return 1;
	}

	std::string	line;
	size_t		i;
	while (std::getline(inputFile, line)){
		i = 0;
		while ((i = line.find(toBeReplaced, i)) != std::string::npos)
		{
			line.erase(i, toBeReplaced.length());
			line.insert(i, toReplace);
			i += toReplace.length();
		}
		outputFile << line;
		if (!inputFile.eof()){
			outputFile << std::endl;
		}
		i++;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
