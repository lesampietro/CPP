/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:23 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/26 23:43:17 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal{
	private:
		Brain* _brain;

	public:
		Dog(); //Default Constructor
		Dog(const Dog &other); //Copy Constructor
		Dog &operator=(const Dog &other); //Copy assignment operator
		~Dog(); //Default Destructor

		void	makeSound() const;
		Brain* getBrain() const; // Getter
};

#endif