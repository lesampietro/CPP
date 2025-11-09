#include "Array.hpp"
#include "Array.tpp"

int main( void ) {
	std::cout << "===== Creating empty array =====" << std::endl;
	Array<int> arr1; // Calls default destructor
	try {
		std::cout << arr1[0] << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== Creating array of int =====" << std::endl;
	Array<int> arr2(4);
	try {
		std::cout << arr2[0] << arr2[1] << arr2[2] << arr2[3] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== Creating array of string =====" << std::endl;
	Array<std::string> arr3(3);
	arr3[0] = "Hello,";
	arr3[1] = " World";
	arr3[2] = "!";
	try {
		std::cout << arr3[0] << arr3[1] << arr3[2] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== Testing copy and assignment =====" << std::endl;
	Array<int> arr4(4);
	arr4 = arr2;
	arr4[2] = 42;
	try {
		std::cout << "arr2: " << arr2[0] << arr2[1] << arr2[2] << arr2[3] << std::endl;
		std::cout << "arr4: " << arr4[0] << arr4[1] << arr4[2] << arr4[3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}