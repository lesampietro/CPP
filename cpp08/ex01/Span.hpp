#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <limits>
# include <cctype>
# include <algorithm>
# include <string>
# include <vector>
# include <deque>
# include <list>
# include <stack>
# include <queue>

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

class	Span {
	private:
		unsigned int		_size;
		std::vector<int>	_container;
		Span();
	
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(const int number);
		
		// Template to accept an iterator interval.
		// It must be implemented in the header file because of the way C++ handles templates: it is not compiled until instantiation.
        template <typename Iterator>
        void	addMultipleNumbers(Iterator begin, Iterator end) {
            for (Iterator it = begin; it != end; ++it) {
                addNumber(*it);
            }
        }

		int		shortestSpan();
		int		longestSpan();

		// Nested classes for exceptions
		class ContainerFullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class InsufficientValuesException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class InvalidValueException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};



#endif
