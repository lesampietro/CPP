#include "includes/Serializer.hpp"

int main(void)
{
	Data		data;
	Data		*ptr;
	uintptr_t	raw;

	int test = 0;
	std::cout << GREEN << "////// TEST #" << ++test << RST << std::endl;
	std::cout << "Converting a data structure to raw data...\n" << std::endl;
	data.age = 32;
	data.name = "Lelê";
	std::cout << data;
	raw = Serializer::serialize(&data);
	std::cout << YELLOW << "serialized data: " << RST << raw << std::endl;
	std::cout << "data struct memory address: " << CYAN << &data << RST;
	std::cout << "\nraw data memory address: " << CYAN << &raw << RST;

	std::cout << GREEN << "\n\n////// TEST #" << ++test << RST << std::endl;
	std::cout << "Converting raw data back to a data struct...\n" << std::endl;
	std::cout << raw;
	ptr = Serializer::deserialize(raw);
	std::cout << YELLOW << "\ndeserialized data: " << RST;
	std::cout << *ptr;
	std::cout << "data struct memory address: " << CYAN << &data << RST;
	std::cout << "\nptr to data struct memory address: " << CYAN << ptr << RST;

	std::cout << GREEN << "\n\n////// TEST #" << ++test << RST << std::endl;
	std::cout << "Converting null pointer to raw data...\n" << std::endl;
	Data	*nullPtr = NULL;
	std::cout << "nullPtr: " << CYAN << nullPtr << RST << std::endl;
	raw = Serializer::serialize(nullPtr);
	std::cout << YELLOW << "serialized data: " << RST << raw << std::endl;

	std::cout << GREEN << "\n////// TEST #" << ++test << RST << std::endl;
	std::cout << "Converting null pointer to raw data...\n" << std::endl;
	Data *invalidPtr = reinterpret_cast<Data *>(0xdeadc0de); // Force an arbitrary hexadecimal value into a Data* pointer type
	raw = Serializer::serialize(invalidPtr);
	ptr = Serializer::deserialize(raw);
	std::cout << YELLOW << "serialized data: " << RST << raw << std::endl;
	std::cout << YELLOW << "ptr to data struct memory address: " << RST << ptr;
	// attempting to read memory at *ptr will cause segmentation fault:
	// std::cout << *ptr;
	return 0;
}
