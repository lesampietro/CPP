/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:23 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 19:19:05 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog(); //Default Constructor
		Dog(const Dog &other); //Copy Constructor
		Dog &operator=(const Dog &other); //Copy assignment operator
		~Dog(); //Default Destructor

		void	makeSound() const;
};

#endif