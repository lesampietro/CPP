/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/27 14:00:07 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[34m"
# define CYAN "\033[0;36m"
# define RST "\033[0m"

class Animal {
	protected:
		std::string	_type;

	public:
		Animal(); //Default Constructor
		Animal(std::string _type); //Param Constructor
		Animal(const Animal &other); //Copy Constructor
		Animal &operator=(const Animal &other); //Copy assignment operator
		virtual ~Animal(); //Default Destructor

		virtual void		makeSound() const;
		std::string			getType() const; //Getter
		void				setType(const Animal &other); //Setter
};

#endif