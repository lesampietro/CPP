/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/18 14:41:21 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(); //Default Constructor
		FragTrap(std::string name); //Custom Constructor
		FragTrap(const FragTrap &copy); //Def. Copy Constructor
		FragTrap &operator=(const FragTrap &other); //Def. Assignment Operator
		~FragTrap(); //Default Destructor

		void	highFivesGuys(); //New method
};

#endif