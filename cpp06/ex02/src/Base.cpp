#include "../includes/Base.hpp"

Base::~Base() {}

Base *Base::generate(void)
{
	static bool initialized = false;
	if (!initialized) {
		srand(static_cast<unsigned int>(time(nullptr))); //Generates an unsigned int "seed" global variable internally, accessed later by rand()
		initialized = true;
	}

	int random = rand() % 3; // Uses the seed variable created by srand() to randomly generate number sequences

	switch (random) {
	case 0:
		std::cout << CYAN << "Generated: A" << RST << std::endl;
		return new A();
	case 1:
		std::cout << CYAN << "Generated: B" << RST << std::endl;
		return new B();
	case 2:
	default:
		std::cout << CYAN << "Generated: C" << RST << std::endl;
		return new C();
	}
}

static void identify(Base *p) {
	return ;
}

static void identify(Base &p) {
	return ;
}