
#include "../includes/Form.hpp"

Form::Form() : _name("Unknown"), _isSigned(false), _toSignGrade(-1), _toExecuteGrade(-1) {
	if (this->_toSignGrade > MIN_GRADE || this->_toExecuteGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (this->_toSignGrade < MAX_GRADE || this->_toExecuteGrade > MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const std::string name, bool isSigned, const int toSignGrade, const int toExecuteGrade) : _name("Unknown"), _isSigned(false) {
	if (this->_toSignGrade > MIN_GRADE || this->_toExecuteGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (this->_toSignGrade < MAX_GRADE || this->_toExecuteGrade > MAX_GRADE)
		throw GradeTooHighException();
}

Form::~Form() {

}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high (maximum grade is 1)";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low (minimum grade is 150)";
}


std::ostream&	operator<<(std::ostream &out, const Form &form){
	out << CYAN << form.getName() << RST << ", with _toSignGrade: ";
	out << CYAN << form.getSignGrade() << RST << ", _toExecuteGrade: ";
	out << CYAN << form.getExecuteGrade() << RST << " and _isSigned status: ";
	out << CYAN << form.getIsSigned() << RST << ".\n";

	return out;
}