#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("ShruberryCreation", 145, 137) {
	// No need to initialize _isSigned here, because it's already set on the base class's constructor as false
	// The required _toSign and _toExecute grades are hardcoded into the constructor and therefore passed to the base class, which will validate and throw if the grades do not match valid range
	std::cout << BLUE << this->getName();
	std::cout << RST << " Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy Assignment called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
	//_isSigned should be initialized false, and grades cannot be modified.
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BLUE << this->getName();
	std::cout << RST << " ~Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	
}