#include "../includes/Base.hpp"

Base::~Base() {}

Base *Base::generate(void) {
	switch (random)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			break;
	}
}