#include "../includes/Intern.hpp"

Intern::Intern() {
	std::cout << BLUE << "Intern";
	std::cout << RST << " created." << std::endl;
}

Intern::Intern(const Intern &copy) {
	std::cout << "Intern copy constructor called." << std::endl;
	(void)copy;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called." << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern() {
	std::cout << BLUE << "Intern";
	std::cout << RST << " ~Destructor called" << std::endl;
}

const char *Intern::FormException::what() const throw() {
	return "Form: doesn't exist";
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string levels[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"};

	int i = 0;
	
	while (i <= 2)
	{
		if (not formName.compare(levels[i])) {
			break;
		}
		i++;
	}

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << CYAN << formName << RST << std::endl; 
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << CYAN << formName << RST << std::endl; 
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << CYAN << formName << RST << std::endl; 
			return new PresidentialPardonForm(target);
		default:
			throw FormException();
	}

}