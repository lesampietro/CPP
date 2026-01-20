#include "easyfind.hpp"

int main( void ) {

	std::cout << "======== Testing with container type: vector<int> ========" << std::endl;
	std::vector<int> vec; // Initializing vec = {a, b, c} is not permitted in c++98
	vec.push_back(10);
	vec.push_back(21);
	vec.push_back(42);

	std::cout << "Created a vector<int> with the contents: 10, 21, 42" << std::endl;

	int toFindA = 42;
	int toFindB = 13;

	std::cout << "Searching for: " << toFindA << std::endl;
	easyfind(vec, toFindA);
	std::cout << "Searching for: " << toFindB << std::endl;
	easyfind(vec, toFindB);
	
	std::cout << "\n======== Testing with container type: deque<int> ========" << std::endl;
	std::deque<int> deq; // Initializing deq = {a, b, c} is not permitted in c++98
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);

	std::cout << "Created a deque<int> with the contents: 1, 2, 3" << std::endl;

	int toFindC = 1;
	int toFindD = 1000;

	std::cout << "Searching for: " << toFindC << std::endl;
	easyfind(deq, toFindC);
	std::cout << "Searching for: " << toFindD << std::endl;
	easyfind(deq, toFindD);

	std::cout << "\n======== Testing with container type: list<int> ========" << std::endl;
	std::list<int> lst; // Initializing lst = {a, b, c} is not permitted in c++98
	lst.push_back(123);
	lst.push_back(456);
	lst.push_back(789);

	std::cout << "Created a list<int> with the contents: 123, 456, 789" << std::endl;
	
	int toFindE = 456;
	int toFindF = 987;

	std::cout << "Searching for: " << toFindE << std::endl;
	easyfind(lst, toFindE);
	std::cout << "Searching for: " << toFindF << std::endl;
	easyfind(lst, toFindF);

	std::cout << std::endl;

	return 0;
}