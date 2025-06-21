/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:55:40 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/21 15:16:40 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

bool	replace(std::string filename, std::string oldStr, std::string newStr){
	if (oldStr.empty()){
		std::cerr << "Error: <string_1> cannot be empty.";
		std::cerr << std::endl;
		return false;
	}
	
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open()){
		std::cerr << "Error: Could not open file '";
		std::cerr << filename << "'." << std::endl;
		return false;
	}
	
	std::string		outputFileName = filename + ".replace";
	std::ofstream	outputFile(outputFileName.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create output file '";
		std::cerr << outputFileName << "'." << std::endl;
		return false;
	}

	std::string	line;
	size_t		i;
	while (std::getline(inputFile, line)){
		i = 0;
		while ((i = line.find(oldStr, i)) != std::string::npos)
		{
			line.erase(i, oldStr.length());
			line.insert(i, newStr);
			i += newStr.length();
		}
		outputFile << line;
		if (!inputFile.eof()){
			outputFile << std::endl;
		}
		i++;
	}
	inputFile.close();
	outputFile.close();

	return true;
}