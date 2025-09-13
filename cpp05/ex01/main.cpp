
#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

int main() {
	std::cout << YELLOW << "Creating forms with invalid grades\n";
	std::cout << RST << std::endl;

	try {
		std::cout << "Creating form with sign grade too high (0)...\n";
		Form form1("Form1", 0, 50);
	} catch (const Form::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}
	std::cout << YELLOW << "//////" << RST << std::endl;

	try {
		std::cout << "Creating form with sign grade too low (151)...\n";
		Form form2("Form2", 151, 50);
	} catch (const Form::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}
	std::cout << YELLOW << "//////" << RST << std::endl;

	try {
		std::cout << "Creating form with execution grade too high (0)...\n";
		Form form3("Form3", 50, 0);
	} catch (const Form::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}
	std::cout << YELLOW << "//////" << RST << std::endl;

	try {
		std::cout << "Creating form with execution grade too low (151)...\n";
		Form form4("Form4", 50, 151);
	} catch (const Form::GradeTooHighException &e) {
		std::cout << MAGENTA << "Error 00: " << RST << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cout << MAGENTA << "Error 01: " << RST << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n______________________________________________\n";

	std::cout << "Testing Form signing\n" << RST << std::endl;

	Bureaucrat john("John", 50); // Bureaucrat with grade 50
	Bureaucrat alice("Alice", 10); // Bureaucrat with grade 10

	Form form5("Form5", 30, 20); // Form with signing grade 30
	Form form6("Form6", 5, 20);  // Form with signing grade 5

	std::cout << john.getName() << " attempts to sign ";
	std::cout << form5.getName() << "...\n";
	john.signForm(form5); // John does not sufficient grade to sign
	std::cout << john;
	std::cout << form5 << std::endl;
	std::cout << YELLOW << "//////" << RST << std::endl;

	std::cout << john.getName() << " attempts to sign ";
	std::cout << form6.getName() << "...\n";
	john.signForm(form6); // John does not have sufficient grade to sign
	std::cout << john;
	std::cout << form6 << std::endl;
	std::cout << YELLOW << "//////" << RST << std::endl;

	std::cout << alice.getName() << " attempts to sign ";
	std::cout << form5.getName() << "...\n";
	alice.signForm(form5); // Alice has sufficient grade to sign
	std::cout << alice;
	std::cout << form5 << std::endl;
	std::cout << YELLOW << "//////" << RST << std::endl;

	std::cout << alice.getName() << " attempts to sign ";
	std::cout << form5.getName() << "...\n";
	alice.signForm(form5); // Form5 is already signed by John"
	std::cout << std::endl;

	return 0;
}