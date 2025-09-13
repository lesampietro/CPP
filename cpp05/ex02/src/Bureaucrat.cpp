
#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(1) {
	std::cout << BLUE << this->_name;
	std::cout << RST << " created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else {
		this->_grade = grade;
	std::cout << BLUE << this->_name;
	std::cout << RST << " created." << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	std::cout << std::endl;
	if (this != &other) { // Check for self-assignment
		// this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << BLUE << this->_name;
	std::cout << RST << " ~Destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade <= MAX_GRADE)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade >= MIN_GRADE)
		throw GradeTooLowException();
	this->_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat: Grade is too high (maximum grade is 1)";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat: Grade is too low (minimum grade is 150)";
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << CYAN << this->_name << RST;
		std::cout << " signed " << BLUE << form.getName() << RST << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << MAGENTA << "Error 02: " << RST << this->_name;
		std::cerr << " cannot sign " << form.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		// std::cout << CYAN << this->_name << RST;
		// std::cout << " signed " << BLUE << form.getName() << RST << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << MAGENTA << "Error 02: " << RST << this->_name;
		std::cerr << " cannot sign " << form.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureau){
	out << CYAN << bureau.getName() << RST << ", bureaucrat grade "; 
	out << CYAN << bureau.getGrade() << RST << ".\n";
	return out;
}