#include "includes/ScalarConverter.hpp"

int main()
{
	// std::string literal;
	int testNumber = 0;
	std::cout << YELLOW << "////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing empty string...\n" << std::endl;
	// std::getline(std::cin, literal);
	ScalarConverter::convert("");

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing 'char'...\n" << std::endl;
	ScalarConverter::convert("a");

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing 'int'...\n" << std::endl;
	ScalarConverter::convert("123");

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing 'float'...\n" << std::endl;
	ScalarConverter::convert("42.0f");

	std::cout << YELLOW << "\n////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing 'double'...\n" << std::endl;
	ScalarConverter::convert("123.456");
	// while (42) {
	// 	std::cout << "Type in what you want to convert: " << std::endl;
	// 	if (isEmpty(literal)) {
	// 		std::cout << MAGENTA << "Error: " << RST << "string is Empty" << std::endl;
	// 		break;
	// 	}
	// }
	return 0;
}
