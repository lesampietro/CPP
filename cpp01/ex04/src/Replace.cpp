/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:55:40 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/22 15:57:17 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

bool	isValidFile(const std::string &filename, std::ifstream &file)
{
	file.open(filename.c_str()); // Open input file. c_str() converts string to const *char (expected by the open method)
	if (!file.is_open()){ //Checks if open was possible
		std::cerr << MAGENTA << "Error: Could not open file '" << filename;
		std::cout << RST << "'" << std::endl;
		return false;
	}

	// Check for empty file
	std::string line;
	bool hasContent = false;
	while (std::getline(file, line)){ // Loops until end of file
		if (!line.empty() && line != "\n" && line != "\r" && line != "\r\n")
		{
			hasContent = true; // Found a line with content(other than spaces)
			file.close(); // Closes file to go back to the start
			break;
		}
	}
	if (!hasContent){
		std::cerr << MAGENTA << "Error: " << filename << " is empty or contains only blank lines.";
		std::cerr << RST << std::endl;
		return false;
	}

	file.seekg(0, std::ios::beg); // Goes back to file start

	return true;
}

bool	replace(const std::string &filename, const std::string &oldStr, const std::string &newStr)
{
	std::ifstream	inputFile;
	if (!isValidFile(filename, inputFile))
		return false;

	std::string		outputFileName = filename + ".replace"; // Creating name to be used in the outfile creation
	std::ofstream	outputFile(outputFileName.c_str()); // Creating out file
	// Checking if it was possible to create/open out file
	if (!outputFile.is_open())
	{
		std::cerr << MAGENTA << "Error: Could not create output file '";
		std::cerr << RST << outputFileName << "'." << std::endl;
		inputFile.close(); // Closes input file before returning
		return false;
	}

	std::string	line;
	size_t		i;
	while (std::getline(inputFile, line))
	{
		i = 0;
		// find() updates i when finds an occurence of the oldstr on the line. return value is std::string::npos if oldStr is not found
		while ((i = line.find(oldStr, i)) != std::string::npos) // Loops till theres is no more occurences of oldStr on the line
		{
			line.erase(i, oldStr.length());
			line.insert(i, newStr);
			i += newStr.length();
		}
		outputFile << line;
		if (!inputFile.eof()){
			outputFile << std::endl;
		}
	}
	inputFile.close();
	outputFile.close();

	return true;
}