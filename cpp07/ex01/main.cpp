#include "iter.hpp"

int main( void ) {

	std::cout << "===== Creating array of int =====" << std::endl;
	int arr[5] = {1, 2, 3, 4, 5};
	std::cout << YLW << "int arr[5] = {1, 2, 3, 4, 5}" << RST << std::endl;

	std::cout << std::endl;
	std::cout << "===== Testing ::iter with array of int =====" << std::endl;
	std::cout << CYN << "Passing function that does not modify parmeters...";
	std::cout << RST << " (CONST)" << std::endl;
	::iter(arr, 5, &printElement);

	std::cout << std::endl;
	std::cout << GRN << "Passing function that modifies the parmeters...";
	std::cout << RST << " (NON CONST)" << std::endl;
	::iter(arr, 5, &printModifiedInt);

	std::cout << "_________________________________________\n" << std::endl;

	std::cout << "===== Creating array of std::strings =====" << std::endl;
	std::string strArr[3] = {"Hello", "World", "!"};
	std::cout << YLW << "std::string strArr[3] = {\"Hello\", \"World\", \"!\"}";
	std::cout << RST << std::endl;

	std::cout << std::endl;
	std::cout << "==== Testing ::iter with array of string ====" << std::endl;
	std::cout << CYN "Passing function that does not modify the parmeters...";
	std::cout << RST << " (CONST)" << std::endl;
	::iter(strArr, 3, &printElement);

	std::cout << std::endl;
	std::cout << GRN << "Passing function that modifies the parmeters...";
	std::cout << RST << " (NON CONST)" << std::endl;
	::iter(strArr, 3, &printModifiedString);
	std::cout << std::endl;

	return 0;
}