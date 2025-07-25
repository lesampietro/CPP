/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/25 14:53:04 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
#define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class Animal {
	protected:
		std::string	_type;

	public:
		Animal(); //Default Constructor
		Animal(const Animal &other); //Copy Constructor
		Animal &operator=(const Animal &other); //Copy assignment operator
		virtual ~Animal(); //Default Destructor

		virtual void		makeSound() const;
		std::string			getType() const;
};

#endif


//Without virtual, C++ decides which function to call based on the pointer type, not the actual object type.
//Use virtual only in the base class

//When the base class (Animal) ~destructor is called (after being initialized from a derived class) its _type attribute will still have the derived class value ("Cat" or "Dog"). That's why "std::cout << this->type;" will print the correct type even in the base class destructor ("Cat" or "Dog" instead of "Animal").