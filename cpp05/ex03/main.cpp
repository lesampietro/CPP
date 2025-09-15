
#include "includes/Intern.hpp"
#include "includes/Bureaucrat.hpp"

int main() {
	std::cout << YELLOW << "Testing Intern\n";
	std::cout << RST << std::endl;
	Intern		randomIntern;
	Bureaucrat	pedro("Pedro", 1);
	AForm		*form;

	std::cout << YELLOW << "\n______________________________________________\n";
	form = randomIntern.makeForm("ShrubberyCreationForm", "home");
	std::cout << form << std::endl;
	pedro.signForm(*form);
	pedro.executeForm(*form);
	delete form;

	std::cout << YELLOW << "\n______________________________________________\n";
	form = randomIntern.makeForm("RobotomyRequestForm", "home");
	std::cout << form << std::endl;
	pedro.signForm(*form);
	pedro.executeForm(*form);
	delete form;

	std::cout << YELLOW << "\n______________________________________________\n";
	form = randomIntern.makeForm("PresidentialPardonForm", "home");
	std::cout << form << std::endl;
	pedro.signForm(*form);
	pedro.executeForm(*form);
	delete form;

	return 0;
}