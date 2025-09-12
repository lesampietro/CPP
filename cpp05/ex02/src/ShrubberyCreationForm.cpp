
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShruberryCreation", 145, 137) {
	// No need to initialize _isSigned here, because it's already set on the base class's constructor as false
	// The required _toSign and _toExecute grades are hardcoded into the constructor and therefore passed to the base class, which will validate and throw if needed (if the grades do not match valid grade spectrum)
	std::cout << BLUE << this->getName();
	std::cout << RST << " Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy Assignment called" << std::endl;
	(void)other;
	return *this;
	//_isSigned should be initialized false, and grades cannot be modified.
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BLUE << this->getName();
	std::cout << RST << " ~Destructor called" << std::endl;
}

