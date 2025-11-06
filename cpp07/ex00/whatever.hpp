#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
};

template <typename T>
T const &min(T const &a, T const &b)
{
	return ((a < b) ? a : b);
};

template <typename T>
T const &max(T const &a, T const &b)
{
	return ((a > b) ? a : b);
};

#endif