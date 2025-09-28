#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

// ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
// }

// ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
// {
// }

// ~ScalarConverter::ScalarConverter() {

// }

void ScalarConverter::convert(const std::string &literal)
{
	if (isEmpty(literal)) 
		std::cout << MAGENTA << "Error: " << RST << "string is Empty" << std::endl;
	else if (isChar(literal))
		std::cout << "Literal is a " << GREEN << "*char*" << RST << std::endl;
	else if (isInt(literal))
		std::cout << "Literal is an " << GREEN << "*int*" << RST << std::endl;
	else if (isFloat(literal))
		std::cout << "Literal is a " << GREEN << "*float*" << RST << std::endl;
	else if (isDouble(literal))
		std::cout << "Literal is a " << GREEN << "*double*" << RST << std::endl;
	// c = char(lit)
	// int
	// float
	// double
}

bool isEmpty(const std::string &literal){
	return literal.empty();
}

bool isChar(const std::string &literal){
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool isInt(const std::string &literal){
	char	*endptr;
	strtol(literal.c_str(), &endptr, 10); //Converts the literal str converted into char* (C) into a long in decimal base (10). &endptr receives the address of the first NON-converted char or the end of the string (in the case of a valid int). Then, returns True if no non-convertible chars were found
	return (*endptr == '\0');
}

bool isFloat(const std::string &literal){
	return (literal.find('f') != std::string::npos &&
			literal.find('.') != std::string::npos); //Returns true if finds "." or "f" on the string
}

bool isDouble(const std::string &literal){
	char *endptr;
	strtod(literal.c_str(), &endptr);
	return (*endptr == '\0' && literal.find('.') != std::string::npos);
}

