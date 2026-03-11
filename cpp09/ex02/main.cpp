#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: Not enough arguments" << std::endl;
		return 1;
	}

	PmergeMe pmergeme;
	pmergeme.sort(argc, argv);

	return 0;
}

