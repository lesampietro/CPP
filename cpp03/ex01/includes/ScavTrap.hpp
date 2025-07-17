/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/17 16:24:33 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(); //Default Constructor
		ScavTrap(std::string name); //Custom Constructor
		ScavTrap(const ScavTrap &copy); //Def. Copy Constructor
		ScavTrap &operator=(const ScavTrap &other); //Def. Assignment Operator
		~ScavTrap(); //Default Destructor

		void	attack(const std::string &target);//Overwrite ClapTrap::attack()
		void	guardGate(); //New method
};

#endif