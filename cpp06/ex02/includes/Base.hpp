#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib> //rand(), srand()
# include <ctime> //time()
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class Base {
	public:
		virtual ~Base();

		static Base *generate(void);
};

	static void identify(Base *p);
	static void identify(Base &p);

#endif
