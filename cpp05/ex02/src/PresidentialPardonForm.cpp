#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", target, 145, 137) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy Assignment called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
	//_isSigned should be initialized false, and grades cannot be modified.
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BLUE << this->getName();
	std::cout << RST << " ~Destructor called" << std::endl;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &bureau) {
	if (bureau.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getIsSigned())
		throw AForm::FormAlreadySignedException();
	this->setIsSigned(true);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else if (not this->getIsSigned())
		throw FormNotSignedException();
	else {
	
	}
}