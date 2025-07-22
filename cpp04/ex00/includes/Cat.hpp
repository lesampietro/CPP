/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:20 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 19:19:02 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat(); //Default Constructor
		Cat(const Cat &other); //Copy Constructor
		Cat &operator=(const Cat &other); //Copy assignment operator
		~Cat(); //Default Destructor

		void	makeSound() const;
};

#endif