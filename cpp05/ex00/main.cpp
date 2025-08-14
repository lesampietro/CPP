/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/08/14 18:57:28 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int	main() {
	std::cout << YELLOW << "======== Creating Bureaucrats ========\n";
	std::cout << RST << "--- Instatiate with highest grade ----\n\n";
	try {
		Bureaucrat bob("Bobby", 1);
	}
	catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n---- Instatiate with lowest grade ----\n\n";
	try {
		Bureaucrat billy("Billy", 150);
	}
	catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << YELLOW << "\n========= Testing Exceptions =========\n" << RST;
	std::cout << "----- Throw GradeTooHighException ----\n\n";
	try {
		Bureaucrat debby("Debby", 1);
		debby.incrementGrade();
	}
	catch (const std::exception &e) {
		std::cout << MAGENTA << "Error: " << RST << e.what() << std::endl;
	}

	std::cout << "\n----- Throw GradeTooLowException -----\n\n";
	try {
		Bureaucrat louie("Louie", 150);
		louie.decrementGrade();
	}
	catch (const std::exception &e) {
		std::cout << MAGENTA << "Error: " << RST << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
