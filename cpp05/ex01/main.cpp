
#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

int main() {
	    std::cout << "=== Testing Form creation with invalid grades ===" << std::endl;

    try {
        Form form1("Form1", 0, 50); // Grade too high
    } catch (const Form::GradeTooHighException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Form form2("Form2", 151, 50); // Grade too low
    } catch (const Form::GradeTooLowException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Form form3("Form3", 50, 0); // Execution grade too high
    } catch (const Form::GradeTooHighException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Form form4("Form4", 50, 151); // Execution grade too low
    } catch (const Form::GradeTooLowException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Form signing ===" << std::endl;

    Bureaucrat john("John", 50); // Bureaucrat with grade 50
    Bureaucrat alice("Alice", 10); // Bureaucrat with grade 10

    Form form5("Form5", 30, 20); // Form with signing grade 30
    Form form6("Form6", 5, 20);  // Form with signing grade 5

    std::cout << "\n--- Attempting to have John sign Form5 ---" << std::endl;
    try {
        john.signForm(form5); // John has sufficient grade to sign
    } catch (const Form::GradeTooLowException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (const Form::AlreadySignedException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Attempting to have John sign Form6 ---" << std::endl;
    try {
        john.signForm(form6); // John does not have sufficient grade to sign
    } catch (const Form::GradeTooLowException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (const Form::AlreadySignedException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Attempting to have Alice sign Form6 ---" << std::endl;
    try {
        alice.signForm(form6); // Alice has sufficient grade to sign
    } catch (const Form::GradeTooLowException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (const Form::AlreadySignedException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Attempting to have Alice sign Form5 already signed ---" << std::endl;
    try {
        alice.signForm(form5); // Form5 is already signed by John
    } catch (const Form::GradeTooLowException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (const Form::AlreadySignedException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}