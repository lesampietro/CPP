/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/19 18:58:17 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(); //Default Constructor
		FragTrap(std::string name); //Custom Constructor
		FragTrap(const FragTrap &copy); //Def. Copy Constructor
		FragTrap &operator=(const FragTrap &other); //Def. Assignment Operator
		~FragTrap(); //Default Destructor

		void	highFivesGuys(); //New method
};

#endif

//It's necessary to use virtual inheritance to solve the "Diamond Problem", which happens when a class inherits two other Classes, which share the same "base" Class. Whithout the "virtual" keyword, DiamondTrap would inherit two copies of ClapTrap, causing ambiguity and duplicated memory allocation.