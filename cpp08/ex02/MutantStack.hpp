#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

template<typename T>
class	MutantStack : public std::stack<T> {
	public:
		// Constructors, assignment operator and destructor are implemented directly here because the class is a template. If we were to separate the implementation into a .cpp file, we would need to explicitly instantiate the template for each type we want to use. On the other hand, another option would be to implement the member functions in a .tpp file.
		MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this; }
		~MutantStack() {}


		// ::container_type is used to access the underlying container of the stack, which in this case is std::deque.
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		// "c" is a protected member of std::stack that holds the underlying container. By using this->c, we can access the underlying container and call its begin() and end() methods to return iterators.
		// It has to be "c" because it's the STL standardized protected member.
		// Because typedef was already used above to define the iterator types, we can directly return the iterators (below) from the underlying container without needing to specify the type again.
		iterator begin() {
			return this->c.begin();}
		iterator end() {
			return this->c.end();}
		
		const_iterator begin() const {
			return this->c.begin();}
		const_iterator end() const {
			return this->c.end();}
};


template <typename T>
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &other) {
	// Not necessary to use the keyword "typedef" here, because the iterators are already defined as typedefs in the MutantStack class. We can directly use "typename MutantStack<T>::const_iterator" to declare the iterators itinit and itend.
	typename MutantStack<T>::const_iterator itinit = other.begin();
	typename MutantStack<T>::const_iterator itend = other.end();

	os << "{ ";
	while (itinit != itend) {
		os << *itinit;
		itinit++;
		if (itinit != itend)
			os << ", ";
	}
	os << " }";
	return os;
}

#endif

// std::stack is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure. The class template std::stack is defined in the <stack> header. 
// To say it is an adapter means it is not a real container, but rather a wrapper that provides a specific interface to an underlying container. The underlying container is typically a deque (double-ended queue) by default, but it can be any container that supports the necessary operations (like push_back, pop_back, back, etc.). The stack provides a restricted interface to the underlying container, allowing only access to the top element and operations that modify the stack (like push and pop).
// Main operations of std::stack include: 
// - push(): Adds an element to the top of the stack.
// - pop(): Removes the top element from the stack.
// - top(): Returns a reference to the top element of the stack.
// - empty() and size() as well.
// Containers that can be underlying containers for std::stack include std::vector, std::deque, and std::list. 