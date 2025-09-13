
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShruberryCreation", 145, 137) {
	// No need to initialize _isSigned here, because it's already set on the base class's constructor as false
	// The required _toSign and _toExecute grades are hardcoded into the constructor and therefore passed to the base class, which will validate and throw if the grades do not match valid range
	std::cout << BLUE << this->getName();
	std::cout << RST << " Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy Assignment called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
	//_isSigned should be initialized false, and grades cannot be modified.
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BLUE << this->getName();
	std::cout << RST << " ~Destructor called" << std::endl;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getIsSigned())
		throw AForm::FormAlreadySignedException();
	this->setIsSigned(true);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else {
		std::cout << GREEN << "               ,@@@@@@@," << std::endl;
		std::cout << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		std::cout << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		std::cout << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		std::cout << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		std::cout << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		std::cout << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		std::cout << "       |o|        | |         | |" << std::endl;
		std::cout << "       |.|        | |         | |" << std::endl;
		std::cout << "     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_";
		std::cout << RST << std::endl;
	}
}