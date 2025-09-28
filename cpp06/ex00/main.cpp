#include "includes/ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << MAGENTA << "Error: " << RST;
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		std::cout << "Example: " << argv[0] << " 42.0f" << std::endl;
		return 1;
	}
	else
		ScalarConverter::convert(argv[1]);

	return 0;
}
