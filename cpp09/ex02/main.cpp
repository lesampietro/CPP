#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc <= 2) {
		std::cout << MGNT << "Error: Not enough arguments." << RST << std::endl;
		std::cout << "Please insert a sequence of positive integers." << std::endl;
		return 1;
	}

	PmergeMe obj;
	obj.mergeInsertSort(argc, argv);

	return 0;
}

