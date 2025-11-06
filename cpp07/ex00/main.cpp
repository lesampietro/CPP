#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	std::cout << "======== Testing with integers ========" << std::endl;
	std::cout << CYN << "a = " << RST << a;
	std::cout << ", " << CYN << "b = " << RST << b << std::endl;
	
	::swap(a, b);
	std::cout << "\nafter swap => "<< CYN << "a = " << RST << a;
	std::cout << ", " << CYN << "b = " << RST << b << std::endl;
	std::cout << CYN << "min( a, b ) = " << RST << ::min( a, b ) << std::endl;
	std::cout << CYN << "max( a, b ) = " << RST << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << "\n======== Testing with strings ========" << std::endl;
	std::cout << CYN << "c = " << RST << c;
	std::cout << ", " << CYN << "d = " << RST << d << std::endl;
	
	::swap(c, d);
	std::cout << "\nafter swap => "<< CYN << "c = " << RST << c;
	std::cout << ", " << CYN << "d = " << RST << d << std::endl;
	std::cout << CYN << "min( c, d ) = " << RST << ::min( c, d ) << std::endl;
	std::cout << CYN << "max( c, d ) = " << RST << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	return 0;
}