#include "easyfind.hpp"

// Test helper
template <typename T>
void runTests(const char* name, const T& c, int a, int b, int cval, int missing)
{
    std::cout << YLW << "\n======== Testing with container type: " << RST << name;
	std::cout << YLW " ========" << RST << std::endl;

    std::cout << "Searching for: " << a << std::endl;
    easyfind(c, a);

    std::cout << "\nSearching for: " << b << std::endl;
    easyfind(c, b);

    std::cout << "\nSearching for: " << cval << std::endl;
    easyfind(c, cval);

    std::cout << "\nSearching for: " << missing << std::endl;
    easyfind(c, missing);
}

int main(void)
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(21);
    vec.push_back(42);

    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);

    std::list<int> lst;
    lst.push_back(123);
    lst.push_back(456);
    lst.push_back(789);

    std::vector<int> emptyVec;

    runTests("vector<int>", vec, 10, 21, 42, 13);
    runTests("deque<int>", deq, 1, 2, 3, 1000);
    runTests("list<int>", lst, 123, 456, 789, 987);

    std::cout << YLW << "\n======== Testing empty container ========" << RST << std::endl;
    easyfind(emptyVec, 5);

    return (0);
}