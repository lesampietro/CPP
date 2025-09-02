
#include "../includes/Form.hpp"

Form::Form() : _name("Unknown"), _isSigned(false), _toSignGrade(-1), _toExecuteGrade(-1) {
	if (this->_toSignGrade > MIN_GRADE || this->_toExecuteGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (this->_toSignGrade < MAX_GRADE || this->_toExecuteGrade > MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const std::string name, const int toSignGrade, const int toExecuteGrade) : _name("Unknown"), _isSigned(false), _toSignGrade(toSignGrade), _toExecuteGrade(toExecuteGrade) {
	if (this->_toSignGrade > MIN_GRADE || this->_toExecuteGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (this->_toSignGrade < MAX_GRADE || this->_toExecuteGrade > MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _toSignGrade(copy._toSignGrade), _toExecuteGrade(copy._toExecuteGrade) {
	std::cout << BLUE << this->_name;
	std::cout << RST << ": Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << BLUE << this->_name;
	std::cout << RST << ": Copy Assignment called" << std::endl;
	(void)other;
	return *this;
	//_isSigned should be initialized false, and grades cannot be modified.
}

Form::~Form() {
	std::cout << BLUE << this->_name;
	std::cout << RST << ": ~Destructor called" << std::endl;
}

//Getters
std::string	Form::getName() const {
	return this->_name;
}

bool	Form::getIsSigned() const{
	return this->_isSigned;
}

int	Form::getSignGrade() const {
	return this->_toSignGrade;
}

int	Form::getExecuteGrade() const {
	return this->_toExecuteGrade;
}

void	Form::beSigned(const Bureaucrat &bureau) {
	if (bureau.getGrade() > this->_toSignGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form: Grade is too high (maximum grade is 1)";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form: Grade is too low (minimum grade is 150)";
}

std::ostream&	operator<<(std::ostream &out, const Form &form){
	if (form.getIsSigned()) {
		out << CYAN << form.getName() << RST;
		out << ", form is " << GREEN << "signed, " << RST;
		out << "requires grade: ";
		out << CYAN << form.getSignGrade() << RST << " to sign && grade: ";
		out << CYAN << form.getExecuteGrade() << RST << " to execute.\n";
	}
	else
		out << CYAN << form.getName() << RST;
		out << ", form is " << MAGENTA << "not signed, " << RST;
		out << "requires grade: ";
		out << CYAN << form.getSignGrade() << RST << " to sign && grade: ";
		out << CYAN << form.getExecuteGrade() << RST << " to execute.\n";

	return out;
}