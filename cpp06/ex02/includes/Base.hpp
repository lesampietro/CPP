#ifndef BASE_HPP
# define BASE_HPP

# include <stdint.h> //uintptr_t
# include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class Base {
	public:
		virtual ~Base();
	
};

#endif
