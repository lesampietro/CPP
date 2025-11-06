#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
#include <cctype> // toupper()

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"


// iter function templates
template <typename T> // const version
void iter(const T *array, const size_t length, void (*func)(const T &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
};

template <typename T> // non-const version - the compiler will choose this or the one above depending on what function was passed as argument (it must also take a const or non const reference)
void iter(T *array, const size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
};


// example functions to be passed to iter
template <typename T>
void printElement(const T &element)
{
	std::cout << element << std::endl;
};

template <typename T>
void printModifiedInt(T &element)
{
	element++;
	std::cout << element << std::endl;
};

template <typename T>
void printModifiedString(T &element)
{
	for (size_t i = 0; i < element.length(); i++)
	{
		element[i] = std::toupper(element[i]);
	}
	std::cout << element << std::endl;
};

#endif