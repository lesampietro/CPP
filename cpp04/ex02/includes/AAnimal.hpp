/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/27 00:00:46 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class AAnimal {
	protected:
		std::string	_type;
		AAnimal(); //Default Constructor		

	public:
		AAnimal(std::string _type); //Param Constructor
		AAnimal(const AAnimal &other); //Copy Constructor
		AAnimal &operator=(const AAnimal &other); //Copy assignment operator
		virtual ~AAnimal(); //Default Destructor

		virtual void		makeSound() const = 0; //Pure Virtual Function
		std::string			getType() const; //Getter
		void    setType(const AAnimal &other); //Setter
};

#endif


//An Abstract Class is a class that serves as base to others and cannot be instantiated. It must have at least one pure virtual function