#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << this->getName() << " Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << BLUE << this->getName();
	std::cout << RST << " Copy Assignment called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BLUE << this->getName();
	std::cout << RST << " ~Destructor called" << std::endl;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > this->getSignGrade())
		throw Bureaucrat::InsufficientGradeException();
	else if (this->getIsSigned())
		throw AForm::FormAlreadySignedException();
	this->setIsSigned(true);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::InsufficientGradeException();
	else if (not this->getIsSigned())
		throw FormNotSignedException();
	else {
		std::cout << "\n* DRILLING NOISES *\n" << std::endl;
		std::cout << "        _____ .*." << std::endl;
		std::cout << "       /|||||\\´<<<==[ ROBOT-DRILL ]" << std::endl;
		std::cout << "      ( o _ o )`*" << std::endl;
		std::cout << "      |  > <  |\n" << std::endl;
		// Get current time and use seconds for 50% probability
		time_t currentTime = time(0);
		if (currentTime % 2 == 0)
		{
			std::cout << CYAN << this->getTarget() << RST;
			std::cout << " has been robotomized"; 
			std::cout << GREEN << " successfully!" << RST << std::endl;
			std::cout << "--------------------------cd-\n" << std::endl;
		}
		else
		{
			std::cout << "Robotomy " << MAGENTA << "failed" << RST << " on ";
			std::cout << CYAN << this->getTarget() << RST << "!" << std::endl;
			std::cout << "---------------------------\n" << std::endl;
		}
	}
}