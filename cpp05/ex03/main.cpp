
#include "includes/Intern.hpp"
#include "includes/Bureaucrat.hpp"

int main() {
	int testNumber = 0;
	std::cout << YELLOW << "======= TESTING FORM CREATION BY INTERN =======\n";
	std::cout << RST << std::endl;
	Intern		randomIntern;
	Bureaucrat	bureaucrat("Officer 01", 1);
	AForm		*form;
	std::cout << bureaucrat << std::endl;

	std::cout << YELLOW << "////// TEST #0" << ++testNumber << RST << std::endl;
	form = randomIntern.makeForm("ShrubberyCreationForm", "home");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	std::cout << std::endl;
	delete form;

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	form = randomIntern.makeForm("RobotomyRequestForm", "Wall-E");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	form = randomIntern.makeForm("PresidentialPardonForm", "Marvin");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Intern tries to create a form with a name that does not exist...\n" << RST << std::endl;
	try {
		form = randomIntern.makeForm("WrongName", "Target");
		std::cout << *form << std::endl;
	} catch (const Intern::FormException &e) {
		std::cerr << MAGENTA << "Error 04: " << RST << e.what() << std::endl;
	}

	std::cout << YELLOW << "______________________________________________\n\n";
	std::cout << "========== TESTING FORM EXCEPTIONS ===========\n\n";
	std::cout << YELLOW << "////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << RST << "Already signed form...\n" << std::endl;
	bureaucrat.signForm(*form);
	std::cout << std::endl;
	delete form;

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Bureaucrat with not enough grade to sign...\n" << RST << std::endl;
	form = randomIntern.makeForm("PresidentialPardonForm", "Marvin");
	Bureaucrat	bureaucrat2("Officer 02", 150);
	std::cout << bureaucrat2 << std::endl;
	bureaucrat2.signForm(*form);

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Bureaucrat with not enough grade to execute...\n" << RST << std::endl;
	bureaucrat2.executeForm(*form);
	std::cout << YELLOW << "______________________________________________\n\n";
	delete form;

	return 0;
}