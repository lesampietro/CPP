#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog {
	private:
		std::string 	_name;

	public:
		Dog(); //Default Constructor
		Dog(std::string name);
		Dog(const Dog &other); //Copy Constructor
		Dog &operator=(const Dog &other); //Copy assignment operator
		~Dog(); //Default Destructor

};

#endif