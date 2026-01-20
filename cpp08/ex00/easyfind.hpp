#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

template <typename T>
void easyfind(T &container, int value)
{
	if (container.empty())
	{
		std::cerr << YLW << "Error: Container is empty!"  << std::endl;
		return ;
	}

	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		int position = std::distance(container.begin(), it);
		if (*it == value) {
			std::cout << GRN << "Success! " << RST << "Found: " << value << " at position: ";
			std::cout << "container[" << position << "]" << std::endl;
			return ;
		}
	}
	std::cerr << YLW << "Error: Value not found in container!";
	std::cout << RST << std::endl;
};

#endif

// STL = Standard Template Library - is a library that consist of different data structures and algorithms to effectively store and manipulate data.

// To go through each element of the container, use an iterator: "typename T::iterator". 
// An iterator is an object that points to an element in a container and allows us to traverse the container. Because T is a template parameter, we use "typename T::iterator" to specify that we are referring to the iterator type associated with the container type T.
// Because the iterator points to an element in the container, we should use the * operator to access the value stored at that position.

// Pre-increment (++it) is preferred over (it++) because it avoids creating a temporary copy of the iterator before incrementing it. This is particularly relevant for complex types where the copy operation can be more expensive.

// A sentinel is a special value or marker used to indicate the end of a data structure or to signal a specific condition. In the context of iterators, the end() iterator acts as a sentinel to signify that the search has reached the end of the container without finding the desired value.