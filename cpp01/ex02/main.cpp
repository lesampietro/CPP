/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:17:15 by lsampiet          #+#    #+#             */
/*   Updated: 2025/06/16 12:19:41 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define YELLOW "\033[0;33m"
#define RST "\033[0m"

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str; //Pointer to the string
	std::string &strREF = str; //Reference to the string

	std::cout << YELLOW << "\nAddress of str: " << RST << &str << std::endl;
	std::cout << YELLOW << "Address of strPTR: " << RST << strPTR << std::endl;
	std::cout << YELLOW << "Address of strREF: " << RST << &strREF << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW << "Value of str: " << RST << str << std::endl;
	std::cout << YELLOW << "Value of strPTR: " << RST << *strPTR << std::endl;
	std::cout << YELLOW << "Value of strREF: " << RST << strREF << std::endl;
	std::cout << std::endl;

	return (0);
}