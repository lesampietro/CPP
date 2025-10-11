
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Bureaucrat.hpp"

int main() {
	int testNumber = 0;
	std::cout << YELLOW << "============== TESTING FORMS ===============\n";
	std::cout << "////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing Shrubbery Form: Bureacrat WITH enough grade to sign and execute...\n";
	std::cout << RST << std::endl;

	ShrubberyCreationForm	shrub1("garden");
	Bureaucrat				betty("Betty", 40);

	std::cout << betty << std::endl;

	std::cout << betty.getName() << " attempts to sign and execute ";
	std::cout << shrub1.getName() << "...\n";
	betty.signForm(shrub1);
	betty.executeForm(shrub1);
	std::cout << shrub1 << std::endl;
	betty.executeForm(shrub1);

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing Shrubbery Form: Bureacrat WITHOUT enough grade to sign and execute...\n";
	Bureaucrat jorginho("Jorginho", 150);
	ShrubberyCreationForm shrub2("forest");
	
	std::cout << jorginho << std::endl;
	
	std::cout << jorginho.getName() << " attempts to sign and execute ";
	std::cout << shrub2.getName() << "...\n";
	jorginho.executeForm(shrub2);
	jorginho.signForm(shrub2);
	std::cout << shrub2 << std::endl;
	jorginho.executeForm(shrub2);

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing Robotomy Form: Bureacrat WITH enough grade to sign and execute...\n";
	RobotomyRequestForm robotomy1("Jorginho");
	std::cout << robotomy1 << std::endl;
	betty.signForm(robotomy1);
	betty.executeForm(robotomy1);
	
	
	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing Presidential Form: Bureacrat WITH enough grade to sign and execute...\n";
	PresidentialPardonForm pardon1("Marvin");
	std::cout << pardon1 << std::endl;
	betty.signForm(pardon1);
	betty.executeForm(pardon1);

	Bureaucrat luna("Luna", 5);
	luna.signForm(pardon1);
	luna.executeForm(pardon1);
	std::cout << YELLOW << "______________________________________________\n";std::cout << std::endl;

	return 0;
}