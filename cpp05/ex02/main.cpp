
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Bureaucrat.hpp"

int main() {
	std::cout << YELLOW << "Testing Shrubbery Form\n";
	std::cout << RST << std::endl;

	ShrubberyCreationForm	shrub1;
	Bureaucrat				betty("Betty", 50);

	std::cout << betty << std::endl;
	try
	{
		std::cout << betty.getName() << " attempts to sign and execute ";
		std::cout << shrub1.getName() << "...\n";
		betty.signForm(shrub1);
		betty.executeForm(shrub1);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const AForm::FormAlreadySignedException &e)
	{
		std::cerr << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}

	return 0;
}