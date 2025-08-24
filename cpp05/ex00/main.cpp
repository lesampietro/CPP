/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/08/24 17:16:11 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int	main() {
	std::cout << YELLOW << "Instatiate with too low and too high grades\n\n";
	try {
		Bureaucrat billy("Billy", 151);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}

	try {
		Bureaucrat shoshanna("Shoshanna", 0);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n______________________________________________\n";

	std::cout << YELLOW << "\nInstatiate with ok grades, but increment/decrement after\n";
	try {
		std::cout << std::endl;
		Bureaucrat debby("Debby", 1);
		std::cout << "Incrementing _grade by 1" << std::endl;
		debby.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		Bureaucrat louie("Louie", 150);
		std::cout << "Decrementing _grade by 1" << std::endl;
		louie.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
