#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class ScalarConverter {
	public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void convert(const std::string &literal);
};

bool isEmpty(const std::string &literal); //edge case
bool isChar(const std::string &literal);
bool isInt(const std::string &literal);
bool isFloat(const std::string &literal);
bool isDouble(const std::string &literal);

#endif