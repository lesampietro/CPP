
#include "includes/Bureaucrat.hpp"

int	main() {
	std::cout << YELLOW << "Instatiate with too low and too high grades\n\n";
	std::cout << RST;
	try {
		Bureaucrat billy("Billy", 151);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "It was not possible to create bureaucrat..." << std::endl;
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "It was not possible to create bureaucrat..." << std::endl;
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}
	std::cout << YELLOW << "\n//////\n" << RST << std::endl;
	try {
		Bureaucrat shoshanna("Shoshanna", 0);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "It was not possible to create bureaucrat..." << std::endl;
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "It was not possible to create bureaucrat..." << std::endl;
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n______________________________________________\n";

	std::cout << YELLOW << "\nInstatiate with ok grades, but increment/decrement after\n";
	try {
		std::cout << std::endl;
		Bureaucrat debby("Debby", 1);
		std::cout << debby << std::endl;
		std::cout << "Incrementing " << CYAN << debby.getName();
		std::cout << RST << " _grade by 1" << std::endl;
		debby.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}
	std::cout << YELLOW << "\n//////\n";
	try {
		std::cout << std::endl;
		Bureaucrat louie("Louie", 150);
		std::cout << louie << std::endl;
		std::cout << "Decrementing " << CYAN << louie.getName();
		std::cout << RST << " _grade by 1" << std::endl;
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
