
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", target, 145, 137) {
	// No need to initialize _isSigned here, because it's already set on the base class's constructor as false
	// The required _toSign and _toExecute grades are hardcoded into the constructor and therefore passed to the base class, which will validate and throw if the grades do not match valid range
	std::cout << this->getName() ;
	std::cout << " Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy Assignment called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
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
		throw Bureaucrat::InsufficientGradeException();
	else if (this->getIsSigned())
		throw AForm::FormAlreadySignedException();
	this->setIsSigned(true);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::InsufficientGradeException();
	else if (not this->getIsSigned())
		throw FormNotSignedException();
	else {
		std::string name = this->getTarget() + "_shrubbery";
		std::ofstream outfile(name.c_str());
		outfile << "               ,@@@@@@@," << std::endl;
		outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		outfile << "       |o|        | |         | |" << std::endl;
		outfile << "       |.|        | |         | |" << std::endl;
		outfile << "     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_";
		outfile << std::endl;
		outfile.close();
	}
}