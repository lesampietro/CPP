/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 13:58:22 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Replace.hpp"

int main(int argc, char **argv)
{	
	if (argc != 4){
		std::cerr << "Usage: " << argv[0];
		std::cerr << " <filename> <string_toBeReplaced> <string_toReplace>";
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
