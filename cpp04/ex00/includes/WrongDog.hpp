/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:19:23 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/22 14:58:53 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal{
	public:
		WrongDog(); //Default Constructor
		WrongDog(const WrongDog &other); //Copy Constructor
		WrongDog &operator=(const WrongDog &other); //Copy assignment operator
		~WrongDog(); //Default Destructor

		void	makeSound() const;
};

#endif