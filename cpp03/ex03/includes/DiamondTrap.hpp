/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-sampietro <leticia-sampietro@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:39 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/18 14:56:11 by leticia-sam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;

	public:
		DiamondTrap();									  // Default Constructor
		DiamondTrap(std::string name);					  // Custom Constructor
		DiamondTrap(const DiamondTrap &copy);			  // Def. Copy Constructor
		DiamondTrap &operator=(const DiamondTrap &other); // Def. Assignment Operator
		~DiamondTrap();									  // Default Destructor

		using ScavTrap::attack;
		void whoAmI();
};

#endif