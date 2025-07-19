/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/19 19:00:05 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;

public:
	DiamondTrap();									  // Default Constructor
	DiamondTrap(std::string name);					  // Custom Constructor
	DiamondTrap(const DiamondTrap &copy);			  // Def. Copy Constructor
	DiamondTrap &operator=(const DiamondTrap &other); // Def. Assignment Operator
	~DiamondTrap();									  // Default Destructor

	using ScavTrap::attack; // "Imports" ScavTrap::attack()
	void whoAmI();
};

#endif

// Without the "using" keyword, I'd have to declare "diamond.ScavTrap::attack("param")" everytime I'd like to use this function, instead of simply declaring diamond.attack("param");