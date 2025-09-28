#include "includes/ScalarConverter.hpp"

int main()
{
	std::string literal;
	int testNumber = 0;
	std::cout << "--- Creating Animals ---\n" << std::endl;
	std::cout << "////// TEST #0" << ++testNumber << RST << std::endl;
	std::cout << "Testing empty string...\n" << RST << std::endl;

	ScalarConverter::convert("");
	// while (42) {
	// 	std::cout << "Type in what you want to convert: " << std::endl;
	// 	std::getline(std::cin, literal);
	// 	if (isEmpty(literal)) {
	// 		std::cout << MAGENTA << "Error: " << RST << "string is Empty" << std::endl;
	// 		break;
	// 	}
	// }
	return 0;
}
