#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", target, 25, 5) {
	std::cout << this->getName() << " Constructor called" << std::endl;
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
		throw Bureaucrat::InsufficientGradeException();
	else if (this->getIsSigned())
		throw AForm::FormAlreadySignedException();
	this->setIsSigned(true);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::InsufficientGradeException();
	else if (not this->getIsSigned())
		throw FormNotSignedException();
	else {
		std::cout << "\n======================================================" << std::endl;
		std::cout << "||              * PRESIDENTIAL PARDON *             ||" << std::endl;
		std::cout << "||  " << CYAN << this->getTarget() << RST;
		std::cout << " has been pardoned by Zaphod Beeblebrox." << "  ||" << std::endl;
		std::cout << "======================================================\n" << std::endl;
	}
}