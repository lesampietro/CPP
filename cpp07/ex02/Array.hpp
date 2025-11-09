#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MAG "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

template <typename T>
class Array {
	private:
	unsigned int	_size;
	T				*_array;

	public:
	Array();
	Array(const unsigned int &n);
	Array(const Array &copy);
	Array &operator=(const Array &other);
	~Array();
	
	unsigned int	size() const; //should not modify any variables of the class
	T				&operator[](unsigned int index); // returns a & to the element at the given index
};

# include "Array.tpp" // implementation


#endif