#include "Array.hpp"

int main( void ) {
	{
		std::cout << YLW << "=== Creating empty array ===";
		std::cout << RST << std::endl;
		Array<int> arr1; // Calls default destructor

		std::cout << "Testing array size (should be 0):" << std::endl;
		std::cout << CYN << "arr1.size() = " << RST << arr1.size() << std::endl;

		std::cout << "\nTrying to access empty array:" << std::endl;
		try {
			std::cout << CYN << "arr1[0]: ";
			std::cout << arr1[0] << std::endl; // will throw an exception
		}
		catch (std::exception &e){
			std::cout << MAG << "Error: " << RST << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	std::cout << "_________________________________________\n" << std::endl;

	{
		std::cout << YLW << "=== Creating array of int ===";
		std::cout << RST << std::endl;
		std::cout << "*Using param constructor (allocates mem)*" << std::endl;
		Array<int> arr2(4); // Calls constructor with size parameter

		std::cout << "\nTesting array size (should be 4):" << std::endl;
		std::cout << CYN << "arr2.size() = " << RST << arr2.size() << std::endl;

		std::cout << "\n*Creating some numbers for the array*" << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = i + 1;

		std::cout << "\nTrying to access array contents:" << std::endl;
		try {
			std::cout << CYN << "arr2 contents: " << RST << std::endl;
			for (unsigned int i = 0; i < arr2.size(); i++)
				std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << MAG << "Error: " << RST << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << YLW <<  "=== Testing assignment (=) operator ===";
		std::cout << RST << std::endl;
		std::cout << "*Creating new arrays with different sizes*" << std::endl;
		Array<int> arr3;
		Array<int> arr4(10);

		std::cout << "\nTesting array3 size (should be 0):" << std::endl;
		std::cout << CYN << "arr3.size() = " << RST << arr3.size() << std::endl;
		std::cout << "\nTesting array3 size (should be 10):" << std::endl;
		std::cout << CYN << "arr4.size() = " << RST << arr4.size() << std::endl;

		std::cout << "\n*Using chained =operator*" << std::endl;
		arr4 = arr3 = arr2; // Chaining

		std::cout << "*Changing arr3[2] and arr4[2] contents*" << std::endl;
		arr3[2] = 42;
		arr4[2] = 1000;

		std::cout << "\nTrying to access arrays contents:" << std::endl;
		try {
			std::cout << CYN << "arr2 contents: " << RST << std::endl;
			for (unsigned int i = 0; i < arr2.size(); i++)
				std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
			std::cout << std::endl;

			std::cout << CYN << "arr3 contents: " << RST << std::endl;
			for (unsigned int i = 0; i < arr2.size(); i++)
				std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;
			std::cout << std::endl;

			std::cout << CYN << "arr4 contents: " << RST << std::endl;
			for (unsigned int i = 0; i < arr2.size(); i++)
				std::cout << "arr4[" << i << "]: " << arr4[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << MAG << "Error: " << RST << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	std::cout << "_________________________________________\n" << std::endl;

	{
		std::cout << YLW << "=== Creating array of strings ===";
		std::cout << RST << std::endl;
		std::cout << "*Using param constructor (allocates mem)*" << std::endl;
		Array<std::string> arr5(3);

		std::cout << "\nTesting array size (should be 3):" << std::endl;
		std::cout << CYN << "arr5.size() = " << RST << arr5.size() << std::endl;

		std::cout << "\n*Creating some words for the array*" << std::endl;
		arr5[0] = "Hello,";
		arr5[1] = " World";
		arr5[2] = "!";

		std::cout << "\nTrying to access array contents:" << std::endl;
		try {
			std::cout << CYN << "arr5 contents: " << RST << std::endl;
			for (unsigned int i = 0; i < arr5.size(); i++)
				std::cout << "arr5[" << i << "]: " << arr5[i] << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << YLW << "=== Testing copy constructor ===";
		std::cout << RST << std::endl;
		Array<std::string> arr6(arr5); // Calls copy constructor

		std::cout << "Testing array size (should be 3):" << std::endl;
		std::cout << CYN << "arr6.size() = " << RST << arr6.size() << std::endl;

		std::cout << "\n*Modifying the string on arr6[1]*" << std::endl;
		arr6[1] = " you";

		std::cout << "\nTrying to access array contents:" << std::endl;
		try
		{
			std::cout << CYN << "arr6 contents: " << RST << std::endl;
			for (unsigned int i = 0; i < arr5.size(); i++)
				std::cout << "arr6[" << i << "]: " << arr6[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "_________________________________________\n" << std::endl;
}