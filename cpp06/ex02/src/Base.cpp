#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base() {}

Base *generate(void)
{
	static bool initialized = false;
	if (!initialized) {
		std::srand(std::time(0)); // srand() = "seed rand". Generates an unsigned int "seed" global variable internally, accessed later by rand()
		initialized = true;
	}

	int random = std::rand() % 3; // Uses the seed variable created by srand() to randomly generate number sequences

	switch (random) {
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
	default:
		return new C();
	}
}

void	identify(Base *p) {

	if (dynamic_cast<A*>(p))
		std::cout << "Type: " << CYN << "A" << RST << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: " << GRN << "B" << RST << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: " << BLU << "C" << RST << std::endl;
	return ;
}

void	identify(Base &p) {
	// Use try<->catch to avoid forbidden memory access (& can never be null)
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: " << CYN << "A" << RST << std::endl;
	} catch (std::exception &e) {
		std::cout << MGNT << "Error: " << RST << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: " << GRN << "B" << RST << std::endl;
	} catch (std::exception &e) {
		std::cout << MGNT << "Error: " << RST << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: " << BLU << "C" << RST << std::endl;
	} catch (std::exception &e) {
		std::cout << MGNT << "Error: " << RST << e.what() << std::endl;
	}

	return ;
}