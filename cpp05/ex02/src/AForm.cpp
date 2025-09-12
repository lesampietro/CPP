
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("Unknown"), _isSigned(false), _toSignGrade(-1), _toExecuteGrade(-1) {
	if (this->_toSignGrade > MIN_GRADE || this->_toExecuteGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (this->_toSignGrade < MAX_GRADE || this->_toExecuteGrade > MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm(const std::string name, const int toSignGrade, const int toExecuteGrade) : _name(name), _isSigned(false), _toSignGrade(toSignGrade), _toExecuteGrade(toExecuteGrade) {
	if (this->_toSignGrade > MIN_GRADE || this->_toExecuteGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (this->_toSignGrade < MAX_GRADE || this->_toExecuteGrade < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _toSignGrade(copy._toSignGrade), _toExecuteGrade(copy._toExecuteGrade) {
	std::cout << BLUE << this->_name;
	std::cout << RST << " Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << BLUE << this->_name;
	std::cout << RST << " Copy Assignment called" << std::endl;
	(void)other;
	return *this;
	//_isSigned should be initialized false, and grades cannot be modified.
}

AForm::~AForm() {
	std::cout << BLUE << this->_name;
	std::cout << RST << " ~Destructor called" << std::endl;
}

//Getters
std::string	AForm::getName() const {
	return this->_name;
}

bool	AForm::getIsSigned() const{
	return this->_isSigned;
}

int	AForm::getSignGrade() const {
	return this->_toSignGrade;
}

int	AForm::getExecuteGrade() const {
	return this->_toExecuteGrade;
}

void	AForm::beSigned(const Bureaucrat &bureau) {
	if (bureau.getGrade() > this->_toSignGrade)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_isSigned)
		throw AForm::FormAlreadySignedException();
	this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm: Grade is too high (maximum grade is 1)";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm: Grade is too low (minimum grade is 150)";
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return "Form: Form is already signed";
}

std::ostream&	operator<<(std::ostream &out, const AForm &form){
	if (form.getIsSigned()) {
		out << CYAN << form.getName() << RST;
		out << ", form is " << GREEN << "signed, " << RST;
		out << "requires grade: ";
		out << CYAN << form.getSignGrade() << RST << " to sign && grade: ";
		out << CYAN << form.getExecuteGrade() << RST << " to execute.\n";
	}
	else {
		out << CYAN << form.getName() << RST;
		out << ", form is " << MAGENTA << "not signed, " << RST;
		out << "requires grade: ";
		out << CYAN << form.getSignGrade() << RST << " to sign && grade: ";
		out << CYAN << form.getExecuteGrade() << RST << " to execute.\n";
	}

	return out;
}