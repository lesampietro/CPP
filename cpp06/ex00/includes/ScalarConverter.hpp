#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream> // std::cout, std::endl
# include <stdlib.h> // strtol(), strtof(), strtod()
# include <limits.h> // INT_MAX, INT_MIN
# include <cctype> // isprint(), isdigit()

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class ScalarConverter {
	private: //non instantiable
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};

bool	isEmpty(const std::string &literal); //edge case
bool	isChar(const std::string &literal);
bool	isInt(const std::string &literal);
bool	isFloat(const std::string &literal);
bool	isDouble(const std::string &literal);
bool	isPseudoLiteral(const std::string &literal);
bool	isImpossibleInt(const int value);


#endif

// Scalar types are fundamental data types in C++ that represent single (non-composite) values, that is, they store only one value at a time. Thay also can be copied bit by bit and have a fixed memmory size

// A static member function in C++ is a function that can be called without creating an object. Only has access to static data members or other static functions. It's Useful when a function’s logic is independent of object state.