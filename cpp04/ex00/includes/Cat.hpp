#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat {
	private:
		std::string 	_name;

	public:
		Cat(); //Default Constructor
		Cat(std::string name);
		Cat(const Cat &other); //Copy Constructor
		Cat &operator=(const Cat &other); //Copy assignment operator
		~Cat(); //Default Destructor

};

#endif