#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib> //rand(), srand()
# include <ctime> //time()

# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define MGNT "\033[0;35m"
# define BLU "\033[34m"
# define CYN "\033[0;36m"
# define RST "\033[0m"

// Forward declarations
class	A;
class	B;
class	C;

class Base {
	public:
		virtual ~Base();
	};
	
	Base	*generate(void);
	void	identify(Base *p);
	void	identify(Base &p);

#endif
