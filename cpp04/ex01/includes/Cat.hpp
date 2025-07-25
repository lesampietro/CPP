/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:20 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/26 19:10:38 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain* _brain;

	public:
		Cat(); //Default Constructor
		Cat(const Cat &other); //Copy Constructor
		Cat &operator=(const Cat &other); //Copy assignment operator
		~Cat(); //Default Destructor

		void	makeSound() const;
		Brain* getBrain() const; //Getter
};

#endif