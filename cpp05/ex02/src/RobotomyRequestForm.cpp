#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("ShruberryCreation", 145, 137) {
	// No need to initialize _isSigned here, because it's already set on the base class's constructor as false
	// The required _toSign and _toExecute grades are hardcoded into the constructor and therefore passed to the base class, which will validate and throw if the grades do not match valid range
	std::cout << BLUE << this->getName();
	std::cout << RST << " Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy Assignment called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
	//_isSigned should be initialized false, and grades cannot be modified.
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BLUE << this->getName();
	std::cout << RST << " ~Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	
}