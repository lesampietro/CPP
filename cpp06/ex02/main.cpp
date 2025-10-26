#include "includes/Base.hpp"

int main(void)
{
	std::cout << YLW << "Generating 10 random Bases... " << RST << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "______________________________" << std::endl;
		std::cout << YLW << "Generating Base: " << i + 1 << RST << std::endl;
		Base *base = generate();

		std::cout << "\nIdentifying " << YLW << i << RST << " by pointer:";
		std::cout << std::endl;
			identify(base);
		std::cout << "\nIdentifying " << YLW << i << RST << " by reference:";
		std::cout << std::endl;
			identify(*base);
		std::cout << std::endl;
		delete base;
	}
	return 0;
}
