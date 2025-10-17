#include "includes/Base.hpp"

int main(void)
{
	int test = 0;
	std::cout << GREEN << "////// TEST #" << ++test << RST << std::endl;
	std::cout << "Generating random Class...\n" << std::endl;
	Base *base = Base::generate();

	std::cout << CYAN << "Class* generated: " << identify(*base);
	std::cout << CYAN << "&Class generated: " << identify(&base);
	return 0;
}
