/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/17 19:20:09 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string _name;

	public:
		DiamondTrap();									  // Default Constructor
		DiamondTrap(std::string name);					  // Custom Constructor
		DiamondTrap(const DiamondTrap &copy);			  // Def. Copy Constructor
		DiamondTrap &operator=(const DiamondTrap &other); // Def. Assignment Operator
		~DiamondTrap();									  // Default Destructor

		void attack(const std::string &target); // Overwrite ClapTrap::attack()
		void guardGate();						// New method
};

#endif