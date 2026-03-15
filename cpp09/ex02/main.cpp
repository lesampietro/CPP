#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		PmergeMe obj;
		obj.mergeInsertSort(argc, argv);
	} catch (const std::exception& e) {
		std::cerr << MGNT << "Error: " << RST << e.what() << std::endl;
	}
	return 0;
}
