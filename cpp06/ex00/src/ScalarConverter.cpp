#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	if (isEmpty(literal)) 
	std::cout << MAGENTA << "Error: " << RST << "string is Empty" << std::endl;
	else if (isChar(literal)) {
		char c = literal[0];
		if (isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
		else
		std::cout << "char: non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
	else if (isInt(literal)) {
		std::cout << std::fixed;
		char *endptr;
		long i = strtol(literal.c_str(), &endptr, 10);
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else
		{
			if (isprint(static_cast<unsigned char>(i)))
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "char: non displayable" << std::endl;
		}
		if (i < std::numeric_limits<int>::min() \
			|| i > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(i) << std::endl;
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(i) << std::endl;
	}
	else if (isFloat(literal)) {
		std::cout << std::fixed;
		char *endptr;
		float f = strtof(literal.c_str(), &endptr);
		if (f < 0 || f > 127)
			std::cout << "char: impossible" << std::endl;
		else
		{
			if (isprint(static_cast<unsigned char>(f)))
				std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
			else
				std::cout << "char: non displayable" << std::endl;
		}
		if (f < static_cast<float>(std::numeric_limits<int>::min()) \
		|| f > static_cast<float>(std::numeric_limits<int>::max()))
			std::cout << "int: impossible" << std::endl;
		else {
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		}
		std::cout << "float: " << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(f) << std::endl;
	}
	else if (isDouble(literal)) {
		std::cout << std::fixed;
		char *endptr;
		double d = strtod(literal.c_str(), &endptr);
		if (d < 0 || d > 127)
			std::cout << "char: impossible" << std::endl;
		else
		{
			if (isprint(static_cast<unsigned char>(d)))
				std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
			else
				std::cout << "char: non displayable" << std::endl;
		}
		if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << d << std::endl;
	}
	else if (isPseudoLiteral(literal)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal == "nanf" || literal == "nan") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (literal == "+inff" || literal == "+inf") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (literal == "-inff" || literal == "-inf") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
	else {
		std::cout << "Not a literal." << std::endl;
		std::cout << "If you're using a special char, please consider using \" \"" << std::endl;
	}
}

bool	isEmpty(const std::string &literal){
	return literal.empty();
}

bool	isChar(const std::string &literal){
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool	isInt(const std::string &literal){
	char	*endptr;
	strtol(literal.c_str(), &endptr, 10); //Converts the literal str converted into char* (C) into a long in decimal base (10). &endptr receives the address of the first NON-converted char or the end of the string (in the case of a valid int). Then, returns True if no non-convertible chars were found
	return (*endptr == '\0');
}

bool	isFloat(const std::string &literal){
	if (literal.find('.') == std::string::npos)
		return (false);
	if ((literal[literal.length() - 1]) != 'f')
		return (false);

	std::string without_f = literal.substr(0, literal.length() - 1);
	char *endptr;
	strtof(without_f.c_str(), &endptr);
	return (*endptr == '\0');
}

bool	isDouble(const std::string &literal){
	char *endptr;
	strtod(literal.c_str(), &endptr);
	return (*endptr == '\0' && literal.find('.') != std::string::npos);
}

bool isPseudoLiteral(const std::string &literal) {
	return (literal == "nanf" || literal == "nan" ||
			literal == "+inff" || literal == "+inf" ||
			literal == "-inff" || literal == "-inf");
}